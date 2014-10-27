Image-Thumbnailer-PHP-Extension
===============================

Create thumbnail images, convert image types.

### 1.Basic Usage Example
```
$image = new Monapi\Image\Thumbnail('your_image_file.jpg');
$image->resize(100,100);
$image->save('destination_file.jpg');
```
