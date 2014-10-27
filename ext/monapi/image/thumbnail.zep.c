
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/string.h"

ZEPHIR_INIT_CLASS(Monapi_Image_Thumbnail) {

	ZEPHIR_REGISTER_CLASS(Monapi\\Image, Thumbnail, monapi, image_thumbnail, monapi_image_thumbnail_method_entry, 0);

	/**
	 * @var integer
	 */
	zend_declare_property_null(monapi_image_thumbnail_ce, SL("image_resize"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var integer
	 */
	zend_declare_property_null(monapi_image_thumbnail_ce, SL("width"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var integer
	 */
	zend_declare_property_null(monapi_image_thumbnail_ce, SL("height"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var resource
	 */
	zend_declare_property_null(monapi_image_thumbnail_ce, SL("image"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(monapi_image_thumbnail_ce, SL("mime_type_class_map"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(monapi_image_thumbnail_ce, SL("extension_class_map"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(monapi_image_thumbnail_ce, SL("resize_option_class_map"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(monapi_image_thumbnail_ce, SL("IMAGE_JPEG"), "Monapi\\Image\\Processor\\JpegProcessor" TSRMLS_CC);

	zend_declare_class_constant_string(monapi_image_thumbnail_ce, SL("IMAGE_JPG"), "Monapi\\Image\\Processor\\JpegProcessor" TSRMLS_CC);

	zend_declare_class_constant_string(monapi_image_thumbnail_ce, SL("IMAGE_GIF"), "Monapi\\Image\\Processor\\GIF" TSRMLS_CC);

	zend_declare_class_constant_string(monapi_image_thumbnail_ce, SL("IMAGE_PNG"), "Monapi\\Image\\Processor\\PNG" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Monapi_Image_Thumbnail, resize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *option = NULL;
	zval *width, *height, *option_param = NULL, *dimensions = NULL, *_0 = NULL, *_1, *_2, *_3, *_4, *_5, *_6, *_7, *_8, _9, _10, _11, _12;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &width, &height, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(option);
		ZVAL_EMPTY_STRING(option);
	} else {
		zephir_get_strval(option, option_param);
	}


	if (ZEPHIR_IS_STRING(option, "")) {
		ZEPHIR_INIT_NVAR(option);
		ZVAL_STRING(option, "auto", 1);
	}
	ZEPHIR_CALL_METHOD(&dimensions, this_ptr, "getdimensions", NULL, width, height, option);
	zephir_check_call_status();
	zephir_array_fetch_string(&_1, dimensions, SL("optimal_width"), PH_NOISY | PH_READONLY, "monapi/Image/Thumbnail.zep", 81 TSRMLS_CC);
	zephir_array_fetch_string(&_2, dimensions, SL("optimal_height"), PH_NOISY | PH_READONLY, "monapi/Image/Thumbnail.zep", 81 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "createcanvas", NULL, _1, _2);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("image_resize"), _0 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("image_resize"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("image"), PH_NOISY_CC);
	zephir_array_fetch_string(&_5, dimensions, SL("optimal_width"), PH_NOISY | PH_READONLY, "monapi/Image/Thumbnail.zep", 89 TSRMLS_CC);
	zephir_array_fetch_string(&_6, dimensions, SL("optimal_height"), PH_NOISY | PH_READONLY, "monapi/Image/Thumbnail.zep", 90 TSRMLS_CC);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("width"), PH_NOISY_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("height"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, 0);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_LONG(&_10, 0);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_LONG(&_11, 0);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_LONG(&_12, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagecopyresampled", NULL, _3, _4, &_9, &_10, &_11, &_12, _5, _6, _7, _8);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string $file_name
 * @return array
 */
PHP_METHOD(Monapi_Image_Thumbnail, getImageInfo) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *file_name_param = NULL, *image = NULL, *info, *_1 = NULL;
	zval *file_name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_name_param);

	zephir_get_strval(file_name, file_name_param);


	ZEPHIR_CALL_FUNCTION(&image, "getimagesize", &_0, file_name);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(info);
	array_init_size(info, 5);
	ZEPHIR_OBS_VAR(_1);
	zephir_array_fetch_string(&_1, image, SL("mime"), PH_NOISY, "monapi/Image/Thumbnail.zep", 107 TSRMLS_CC);
	zephir_array_update_string(&info, SL("mime"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_1);
	zephir_array_fetch_long(&_1, image, 0, PH_NOISY, "monapi/Image/Thumbnail.zep", 108 TSRMLS_CC);
	zephir_array_update_string(&info, SL("width"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_1);
	zephir_array_fetch_long(&_1, image, 1, PH_NOISY, "monapi/Image/Thumbnail.zep", 110 TSRMLS_CC);
	zephir_array_update_string(&info, SL("height"), &_1, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(info);

}

PHP_METHOD(Monapi_Image_Thumbnail, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2;
	zval *file_name_param = NULL, *_3 = NULL, *_4, *image_info = NULL, *processor = NULL, *_5, *_6 = NULL, *_7, *_8, *_9, *_10, *_11 = NULL;
	zval *file_name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_name_param);

	zephir_get_strval(file_name, file_name_param);


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 11);
	add_assoc_stringl_ex(_0, SS("exact"), SL("Monapi\\Image\\ResizeOptions\\Exact"), 1);
	add_assoc_stringl_ex(_0, SS("portrait"), SL("Monapi\\Image\\ResizeOptions\\Portrait"), 1);
	add_assoc_stringl_ex(_0, SS("landscape"), SL("Monapi\\Image\\ResizeOptions\\Landscape"), 1);
	add_assoc_stringl_ex(_0, SS("auto"), SL("Monapi\\Image\\ResizeOptions\\Auto"), 1);
	add_assoc_stringl_ex(_0, SS("crop"), SL("Monapi\\Image\\ResizeOptions\\Crop"), 1);
	add_assoc_stringl_ex(_0, SS("default"), SL("Monapi\\Image\\ResizeOptions\\DefaultSize"), 1);
	zephir_update_property_this(this_ptr, SL("resize_option_class_map"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 7);
	add_assoc_stringl_ex(_1, SS(".jpeg"), SL("Monapi\\Image\\Processor\\JpegProcessor"), 1);
	add_assoc_stringl_ex(_1, SS(".jpg"), SL("Monapi\\Image\\Processor\\JpegProcessor"), 1);
	add_assoc_stringl_ex(_1, SS(".gif"), SL("Monapi\\Image\\Processor\\GIF"), 1);
	add_assoc_stringl_ex(_1, SS(".png"), SL("Monapi\\Image\\Processor\\PNG"), 1);
	zephir_update_property_this(this_ptr, SL("extension_class_map"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 7);
	add_assoc_stringl_ex(_2, SS("image/jpeg"), SL("Monapi\\Image\\Processor\\JpegProcessor"), 1);
	add_assoc_stringl_ex(_2, SS("image/jpg"), SL("Monapi\\Image\\Processor\\JpegProcessor"), 1);
	add_assoc_stringl_ex(_2, SS("image/gif"), SL("Monapi\\Image\\Processor\\GIF"), 1);
	add_assoc_stringl_ex(_2, SS("image/png"), SL("Monapi\\Image\\Processor\\PNG"), 1);
	zephir_update_property_this(this_ptr, SL("mime_type_class_map"), _2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "createimage", NULL, file_name);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("image"), _3 TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("image"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_4)) {
		ZEPHIR_CALL_METHOD(&image_info, this_ptr, "getimageinfo", NULL, file_name);
		zephir_check_call_status();
		zephir_array_fetch_string(&_5, image_info, SL("mime"), PH_NOISY | PH_READONLY, "monapi/Image/Thumbnail.zep", 121 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&processor, this_ptr, "getimageprocessorbymimetype", NULL, _5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6, processor, "createimage", NULL, file_name);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("image"), _6 TSRMLS_CC);
		zephir_array_fetch_string(&_7, image_info, SL("width"), PH_NOISY | PH_READONLY, "monapi/Image/Thumbnail.zep", 123 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("width"), _7 TSRMLS_CC);
		zephir_array_fetch_string(&_8, image_info, SL("height"), PH_NOISY | PH_READONLY, "monapi/Image/Thumbnail.zep", 124 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("height"), _8 TSRMLS_CC);
	} else {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_6, "imagesx", NULL, _9);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("width"), _6 TSRMLS_CC);
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_11, "imagesy", NULL, _10);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("height"), _11 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string $file_name
 * @return resource
 */
PHP_METHOD(Monapi_Image_Thumbnail, createImage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *file_name_param = NULL, *processor = NULL, *_0 = NULL;
	zval *file_name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_name_param);

	zephir_get_strval(file_name, file_name_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getextension", NULL, file_name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&processor, this_ptr, "getimageprocessorbyextension", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(processor, "createimage", NULL, file_name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string $extension
 * @return ImageProcessorInterface
 */
PHP_METHOD(Monapi_Image_Thumbnail, getImageProcessorByExtension) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *extension_param = NULL, *processor, *_0;
	zval *extension = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &extension_param);

	zephir_get_strval(extension, extension_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("extension_class_map"), PH_NOISY_CC);
	zephir_array_fetch(&processor, _0, extension, PH_NOISY | PH_READONLY, "monapi/Image/Thumbnail.zep", 149 TSRMLS_CC);
	_1 = zend_fetch_class(Z_STRVAL_P(processor), Z_STRLEN_P(processor), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _1);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * @param string $mime_type
 * @return ImageProcessorInterface
 */
PHP_METHOD(Monapi_Image_Thumbnail, getImageProcessorByMimeType) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *mime_type, *processor, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mime_type);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("mime_type_class_map"), PH_NOISY_CC);
	zephir_array_fetch(&processor, _0, mime_type, PH_NOISY | PH_READONLY, "monapi/Image/Thumbnail.zep", 160 TSRMLS_CC);
	_1 = zend_fetch_class(Z_STRVAL_P(processor), Z_STRLEN_P(processor), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _1);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(Monapi_Image_Thumbnail, getDimensions) {

	zend_class_entry *_5;
	zval *option = NULL;
	zval *width_param = NULL, *height_param = NULL, *option_param = NULL, *type, *_0, *_1, *_2, *_3, *_4;
	int width, height, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &width_param, &height_param, &option_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	zephir_get_strval(option, option_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("resize_option_class_map"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(type);
	zephir_array_fetch(&type, _0, option, PH_NOISY, "monapi/Image/Thumbnail.zep", 171 TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("width"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("height"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, width);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, height);
	_5 = zend_fetch_class(Z_STRVAL_P(type), Z_STRLEN_P(type), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ZEPHIR_RETURN_CALL_CE_STATIC(_5, "getoptimalsize", NULL, _3, _4, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Monapi_Image_Thumbnail, createCanvas) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *width, *height;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width, &height);



	ZEPHIR_RETURN_CALL_FUNCTION("imagecreatetruecolor", NULL, width, height);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string $file_name
 * @return string
 */
PHP_METHOD(Monapi_Image_Thumbnail, getExtension) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *file_name, _0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_name);



	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, '.');
	ZEPHIR_CALL_FUNCTION(&_1, "strrchr", &_2, file_name, &_0);
	zephir_check_call_status();
	zephir_fast_strtolower(return_value, _1);
	RETURN_MM();

}

/**
 * @param string  $file_name
 * @param integer $quality
 */
PHP_METHOD(Monapi_Image_Thumbnail, save) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL, *_7 = NULL, *_8 = NULL;
	int quality, ZEPHIR_LAST_CALL_STATUS;
	zval *file_name, *quality_param = NULL, *temp_file = NULL, *processor = NULL, *_0 = NULL, _2, *_4 = NULL, *_5, *_6, *_9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file_name, &quality_param);

	if (!quality_param) {
		quality = 100;
	} else {
		quality = zephir_get_intval(quality_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "sys_get_temp_dir", &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "Tux", 0);
	ZEPHIR_CALL_FUNCTION(&temp_file, "tempnam", &_3, _0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getextension", NULL, file_name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&processor, this_ptr, "getimageprocessorbyextension", NULL, _4);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("image_resize"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, quality);
	ZEPHIR_CALL_METHOD(NULL, processor, "save", NULL, _5, temp_file, _6);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "copy", &_7, temp_file, file_name);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_8, temp_file);
	zephir_check_call_status();
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("image_resize"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, _9);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

