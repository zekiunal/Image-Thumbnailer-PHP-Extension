namespace Monapi\Image\ResizeOptions;

/**
 * @author      Zeki Unal <zekiunal@gmail.com>
 * @description
 *
 * @package     Monapi\Image\ResizeOptions
 * @name        Auto
 * @version     0.1
 */
class Auto extends ResizeOptionAbstract
{
    /**
     * @param integer $width
     * @param integer $height
     * @param integer $original_width
     * @param integer $original_height
     * @return array
     */
    public static function getOptimalSize(int width, int height, string original_width = null, string original_height = null) -> array
    {
        var sizes;
        let sizes = self::getSizeByAuto(width, height, original_width, original_height);
        return sizes;
    }

    protected static function getSizeByAuto(int width, int height, int original_width, int original_height) -> array
    {
        var optimal_width;
        var optimal_height;

        if original_height < original_width {
            let optimal_width = width;
            let optimal_height = self::getSizeByFixedWidth(optimal_width, original_width, original_height);
            if optimal_height > height {
                let optimal_height = height;
                let optimal_width = self::getSizeByFixedHeight(optimal_height, original_width, original_height);
            }

        } elseif (original_height > original_width) {
            let optimal_width = self::getSizeByFixedHeight(height, original_width, original_height);
            let optimal_height = height;
            if optimal_width > width {
                let optimal_width = width;
                let optimal_height = self::getSizeByFixedWidth(optimal_width, original_width, original_height);
            }
        } else {
            if (height > width) {
                let optimal_width = width;
                let optimal_height = self::getSizeByFixedWidth(width, original_width, original_height);
            } elseif (height < width) {
                let optimal_width = self::getSizeByFixedHeight(height, original_width, original_height);
                let optimal_height = height;
            } else {
                let optimal_width = width;
                let optimal_height = height;
            }
        }

        var sizes;

        let sizes = [
            "optimal_width": optimal_width,
            "optimal_height": optimal_height
        ];

        return sizes;
    }
}
