namespace Monapi\Image\ResizeOptions;

/**
 * @author      Zeki Unal <zekiunal@gmail.com>
 * @description
 *
 * @package     Monapi\Image\ResizeOptions
 * @name        Extract
 * @version     0.1
 */
class Exact extends ResizeOptionAbstract
{
    public static function getOptimalSize(int width, int height, int original_width = null, int original_height = null) -> array
    {
        var sizes;
        let sizes = [
            "optimal_width": width,
            "optimal_height": height
        ];
        return sizes;
    }
}
