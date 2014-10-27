
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * @author      Zeki Unal <zekiunal@gmail.com>
 * @description
 *
 * @package     Monapi\Image\Processor
 * @name        JPegProcessor
 * @version     0.1
 */
ZEPHIR_INIT_CLASS(Monapi_Image_Processor_JPegProcessor) {

	ZEPHIR_REGISTER_CLASS(Monapi\\Image\\Processor, JPegProcessor, monapi, image_processor_jpegprocessor, monapi_image_processor_jpegprocessor_method_entry, 0);

	return SUCCESS;

}

/**
 * @param string $file_name
 * @return resource
 */
PHP_METHOD(Monapi_Image_Processor_JPegProcessor, createImage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *file_name;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_name);



	ZEPHIR_RETURN_CALL_FUNCTION("imagecreatefromjpeg", NULL, file_name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *
 * @param resource $image
 * @param string   $filename
 * @param integer  $quality
 * @param integer  $filters
 * @return bool
 */
PHP_METHOD(Monapi_Image_Processor_JPegProcessor, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *filename = NULL, *quality = NULL, *filters = NULL;
	zval *image, *filename_param = NULL, *quality_param = NULL, *filters_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &image, &filename_param, &quality_param, &filters_param);

	if (!filename_param) {
		ZEPHIR_INIT_VAR(filename);
		ZVAL_EMPTY_STRING(filename);
	} else {
		zephir_get_strval(filename, filename_param);
	}
	if (!quality_param) {
		ZEPHIR_INIT_VAR(quality);
		ZVAL_EMPTY_STRING(quality);
	} else {
		zephir_get_strval(quality, quality_param);
	}
	if (!filters_param) {
		ZEPHIR_INIT_VAR(filters);
		ZVAL_EMPTY_STRING(filters);
	} else {
		zephir_get_strval(filters, filters_param);
	}


	ZEPHIR_RETURN_CALL_FUNCTION("imagejpeg", NULL, image, filename, quality);
	zephir_check_call_status();
	RETURN_MM();

}

