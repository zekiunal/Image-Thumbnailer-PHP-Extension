namespace Monapi\Image\ResizeOptions;

/**
 * @author      Zeki Unal <zekiunal@gmail.com>
 * @description
 *
 * @package     Monapi\Image\ResizeOptions
 * @name        ResizeOptionAbstract
 * @version     0.1
 */
abstract class ResizeOptionAbstract
{
    /**
     * @param integer $height
     * @param integer $original_width
     * @param integer $original_height
     * @return integer
     */
    protected static function getSizeByFixedHeight(int height, int original_width, int original_height) -> int
    {
        int ratio;

        let ratio = original_width / original_height;
        return height * ratio;
    }

    /**
     * @param integer $width
     * @param integer $original_width
     * @param integer $original_height
     * @return integer
     */
    protected static function getSizeByFixedWidth(int width, int original_width, int original_height) -> int
    {
        double ratio;

        let ratio = original_height/original_width;

        int result;

        let result = width * ratio;

        return result;
    }
}
