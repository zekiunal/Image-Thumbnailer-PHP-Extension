
extern zend_class_entry *monapi_image_thumbnail_ce;

ZEPHIR_INIT_CLASS(Monapi_Image_Thumbnail);

PHP_METHOD(Monapi_Image_Thumbnail, resize);
PHP_METHOD(Monapi_Image_Thumbnail, getImageInfo);
PHP_METHOD(Monapi_Image_Thumbnail, __construct);
PHP_METHOD(Monapi_Image_Thumbnail, createImage);
PHP_METHOD(Monapi_Image_Thumbnail, getImageProcessorByExtension);
PHP_METHOD(Monapi_Image_Thumbnail, getImageProcessorByMimeType);
PHP_METHOD(Monapi_Image_Thumbnail, getDimensions);
PHP_METHOD(Monapi_Image_Thumbnail, createCanvas);
PHP_METHOD(Monapi_Image_Thumbnail, getExtension);
PHP_METHOD(Monapi_Image_Thumbnail, save);

ZEND_BEGIN_ARG_INFO_EX(arginfo_monapi_image_thumbnail_resize, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_monapi_image_thumbnail_getimageinfo, 0, 0, 1)
	ZEND_ARG_INFO(0, file_name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_monapi_image_thumbnail___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, file_name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_monapi_image_thumbnail_createimage, 0, 0, 1)
	ZEND_ARG_INFO(0, file_name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_monapi_image_thumbnail_getimageprocessorbyextension, 0, 0, 1)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_monapi_image_thumbnail_getimageprocessorbymimetype, 0, 0, 1)
	ZEND_ARG_INFO(0, mime_type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_monapi_image_thumbnail_getdimensions, 0, 0, 3)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_monapi_image_thumbnail_createcanvas, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_monapi_image_thumbnail_getextension, 0, 0, 1)
	ZEND_ARG_INFO(0, file_name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_monapi_image_thumbnail_save, 0, 0, 1)
	ZEND_ARG_INFO(0, file_name)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(monapi_image_thumbnail_method_entry) {
	PHP_ME(Monapi_Image_Thumbnail, resize, arginfo_monapi_image_thumbnail_resize, ZEND_ACC_PUBLIC)
	PHP_ME(Monapi_Image_Thumbnail, getImageInfo, arginfo_monapi_image_thumbnail_getimageinfo, ZEND_ACC_PROTECTED)
	PHP_ME(Monapi_Image_Thumbnail, __construct, arginfo_monapi_image_thumbnail___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Monapi_Image_Thumbnail, createImage, arginfo_monapi_image_thumbnail_createimage, ZEND_ACC_PROTECTED)
	PHP_ME(Monapi_Image_Thumbnail, getImageProcessorByExtension, arginfo_monapi_image_thumbnail_getimageprocessorbyextension, ZEND_ACC_PROTECTED)
	PHP_ME(Monapi_Image_Thumbnail, getImageProcessorByMimeType, arginfo_monapi_image_thumbnail_getimageprocessorbymimetype, ZEND_ACC_PROTECTED)
	PHP_ME(Monapi_Image_Thumbnail, getDimensions, arginfo_monapi_image_thumbnail_getdimensions, ZEND_ACC_PROTECTED)
	PHP_ME(Monapi_Image_Thumbnail, createCanvas, arginfo_monapi_image_thumbnail_createcanvas, ZEND_ACC_PROTECTED)
	PHP_ME(Monapi_Image_Thumbnail, getExtension, arginfo_monapi_image_thumbnail_getextension, ZEND_ACC_PROTECTED)
	PHP_ME(Monapi_Image_Thumbnail, save, arginfo_monapi_image_thumbnail_save, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
