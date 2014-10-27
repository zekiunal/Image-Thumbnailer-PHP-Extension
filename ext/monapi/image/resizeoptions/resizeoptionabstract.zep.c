
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
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * @author      Zeki Unal <zekiunal@gmail.com>
 * @description
 *
 * @package     Monapi\Image\ResizeOptions
 * @name        ResizeOptionAbstract
 * @version     0.1
 */
ZEPHIR_INIT_CLASS(Monapi_Image_ResizeOptions_ResizeOptionAbstract) {

	ZEPHIR_REGISTER_CLASS(Monapi\\Image\\ResizeOptions, ResizeOptionAbstract, monapi, image_resizeoptions_resizeoptionabstract, monapi_image_resizeoptions_resizeoptionabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * @param integer $height
 * @param integer $original_width
 * @param integer $original_height
 * @return integer
 */
PHP_METHOD(Monapi_Image_ResizeOptions_ResizeOptionAbstract, getSizeByFixedHeight) {

	zval *height_param = NULL, *original_width_param = NULL, *original_height_param = NULL;
	int height, original_width, original_height, ratio;

	zephir_fetch_params(0, 3, 0, &height_param, &original_width_param, &original_height_param);

	height = zephir_get_intval(height_param);
	original_width = zephir_get_intval(original_width_param);
	original_height = zephir_get_intval(original_height_param);


	ratio = (long) (zephir_safe_div_long_long(original_width, original_height TSRMLS_CC));
	RETURN_LONG((height * ratio));

}

/**
 * @param integer $width
 * @param integer $original_width
 * @param integer $original_height
 * @return integer
 */
PHP_METHOD(Monapi_Image_ResizeOptions_ResizeOptionAbstract, getSizeByFixedWidth) {

	double ratio;
	zval *width_param = NULL, *original_width_param = NULL, *original_height_param = NULL;
	int width, original_width, original_height, result;

	zephir_fetch_params(0, 3, 0, &width_param, &original_width_param, &original_height_param);

	width = zephir_get_intval(width_param);
	original_width = zephir_get_intval(original_width_param);
	original_height = zephir_get_intval(original_height_param);


	ratio = zephir_safe_div_long_long(original_height, original_width TSRMLS_CC);
	result = (long) (((double) width * ratio));
	RETURN_LONG(result);

}

