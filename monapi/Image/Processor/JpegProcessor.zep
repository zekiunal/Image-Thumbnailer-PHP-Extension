namespace Monapi\Image\Processor;

/**
 * @author      Zeki Unal <zekiunal@gmail.com>
 * @description
 *
 * @package     Monapi\Image\Processor
 * @name        JPegProcessor
 * @version     0.1
 */
class JPegProcessor
{
    /**
     * @param string $file_name
     * @return resource
     */
    public function createImage(file_name)
    {
        return imagecreatefromjpeg(file_name);
    }

    /**
     *
     * @param resource $image
     * @param string   $filename
     * @param integer  $quality
     * @param integer  $filters
     * @return bool
     */
    public function save(image, string filename = null, string quality = null, string filters = null)
    {
        return imagejpeg(image, filename, quality);
    }
}
