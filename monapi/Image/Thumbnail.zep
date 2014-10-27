namespace Monapi\Image;

/**
 * @author      Zeki Unal <zekiunal@gmail.com>
 * @description
 *
 * @package     Image
 * @name        Monapi\Image
 * @version     0.1
 */
class Thumbnail
{
    const IMAGE_JPEG = "Monapi\\Image\\Processor\\JpegProcessor";

    const IMAGE_JPG  = "Monapi\\Image\\Processor\\JpegProcessor";

    const IMAGE_GIF  = "Monapi\\Image\\Processor\\GIF";

    const IMAGE_PNG  = "Monapi\\Image\\Processor\\PNG";

    /**
     * @var integer
     */
    protected image_resize;

    /**
     * @var integer
     */
    protected width;

    /**
     * @var integer
     */
    protected height;

    /**
     * @var resource
     */
    protected image;

    /**
     * @var array
     */
    protected mime_type_class_map = [
        "image/jpeg" : Thumbnail::IMAGE_JPEG,
        "image/jpg"  : Thumbnail::IMAGE_JPG,
        "image/gif"  : Thumbnail::IMAGE_GIF,
        "image/png"  : Thumbnail::IMAGE_PNG
    ];

    /**
     * @var array
     */
    protected extension_class_map = [
        ".jpeg" : Thumbnail::IMAGE_JPEG,
        ".jpg"  : Thumbnail::IMAGE_JPG,
        ".gif"  : Thumbnail::IMAGE_GIF,
        ".png"  : Thumbnail::IMAGE_PNG
    ];

    /**
     * @var array
     */
    protected resize_option_class_map = [
        "exact"     : "Monapi\\Image\\ResizeOptions\\Exact",
        "portrait"  : "Monapi\\Image\\ResizeOptions\\Portrait",
        "landscape" : "Monapi\\Image\\ResizeOptions\\Landscape",
        "auto"      : "Monapi\\Image\\ResizeOptions\\Auto",
        "crop"      : "Monapi\\Image\\ResizeOptions\\Crop",
        "default"   : "Monapi\\Image\\ResizeOptions\\DefaultSize"
    ];


    public function resize( width,  height, string option=null)
    {
        if option == null {
            let option = "auto";
        }
        var dimensions;
        let dimensions = this->getDimensions(width, height, option);
        let this->image_resize = this->createCanvas(dimensions["optimal_width"], dimensions["optimal_height"]);
        imagecopyresampled(
            this->image_resize,
            this->image,
            0,
            0,
            0,
            0,
            dimensions["optimal_width"],
            dimensions["optimal_height"],
            this->width,
            this->height
        );
    }

    /**
     * @param string $file_name
     * @return array
     */
    protected function getImageInfo(string file_name) -> array
    {
        var image;
        var info;

        let image = getimagesize(file_name);
        let info = [
            "mime"   : image["mime"],
            "width"  : image[0],
            "height" : image[1]
        ];
        return info;
    }

    public function __construct(string file_name)
    {
        let this->image = this->createImage(file_name);
        if this->image === false {
            var image_info;
            var processor;
            let image_info = this->getImageInfo(file_name);
            let processor = this->getImageProcessorByMimeType(image_info["mime"]);
            let this->image = processor->createImage(file_name);
            let this->width = image_info["width"];
            let this->height = image_info["height"];
        } else {
            let this->width = imagesx(this->image);
            let this->height = imagesy(this->image);
        }
    }

    /**
     * @param string $file_name
     * @return resource
     */
    protected function createImage(string file_name)
    {
        var processor;
        let processor = this->getImageProcessorByExtension(this->getExtension(file_name));
        return processor->createImage(file_name);
    }

    /**
     * @param string $extension
     * @return ImageProcessorInterface
     */
    protected function getImageProcessorByExtension(string extension)
    {
        var processor;
        let processor = this->extension_class_map[extension];
        return new {processor}();
    }

    /**
     * @param string $mime_type
     * @return ImageProcessorInterface
     */
    protected function getImageProcessorByMimeType(mime_type)
    {
        var processor;
        let processor = this->mime_type_class_map[mime_type];
        return new {processor}();
    }

    protected function getDimensions(int width,int height,string option) -> array
    {
        var type;

        /**
         * @var ResizeOptionInterface $type
         */
        let type = this->resize_option_class_map[option];
        return {type}::getOptimalSize(width, height, this->width, this->height);
    }

    protected function createCanvas(width, height)
    {
        return imagecreatetruecolor(width, height);
    }

    /**
     * @param string $file_name
     * @return string
     */
    protected function getExtension(file_name)
    {
        return strtolower(strrchr(file_name, '.'));
    }

    /**
     * @param string  $file_name
     * @param integer $quality
     */
    public function save(file_name,int quality = 100)
    {
        var temp_file;
        var processor;
        let temp_file = tempnam(sys_get_temp_dir(), "Tux");
        let processor = this->getImageProcessorByExtension(this->getExtension(file_name));
        processor->save(this->image_resize, temp_file, quality);
        copy(temp_file, file_name);
        unlink(temp_file);
        imagedestroy(this->image_resize);
    }
}
