
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * @author      Zeki Unal <zekiunal@gmail.com>
 * @description
 *
 * @package     Monapi\Image\ResizeOptions
 * @name        Extract
 * @version     0.1
 */
ZEPHIR_INIT_CLASS(Monapi_Image_ResizeOptions_Exact) {

	ZEPHIR_REGISTER_CLASS_EX(Monapi\\Image\\ResizeOptions, Exact, monapi, image_resizeoptions_exact, monapi_image_resizeoptions_resizeoptionabstract_ce, monapi_image_resizeoptions_exact_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Monapi_Image_ResizeOptions_Exact, getOptimalSize) {

	zval *width_param = NULL, *height_param = NULL, *original_width_param = NULL, *original_height_param = NULL, *sizes, *_0 = NULL;
	int width, height, original_width, original_height;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &width_param, &height_param, &original_width_param, &original_height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	if (!original_width_param) {
		original_width = 0;
	} else {
		original_width = zephir_get_intval(original_width_param);
	}
	if (!original_height_param) {
		original_height = 0;
	} else {
		original_height = zephir_get_intval(original_height_param);
	}


	ZEPHIR_INIT_VAR(sizes);
	array_init_size(sizes, 3);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, width);
	zephir_array_update_string(&sizes, SL("optimal_width"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, height);
	zephir_array_update_string(&sizes, SL("optimal_height"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(sizes);

}

