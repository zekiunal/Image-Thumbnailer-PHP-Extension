Image-Thumbnailer-PHP-Extension
===============================

Create thumbnail images, convert image types.

### 1.Basic Usage Example
```
$thumbnailer = new Monapi\Image\Thumbnail('your_image_file.jpg');
$thumbnailer->resize(100,100);
$thumbnailer->save('destination_file.jpg');
```
