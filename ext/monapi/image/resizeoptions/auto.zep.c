
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
#include "kernel/array.h"


/**
 * @author      Zeki Unal <zekiunal@gmail.com>
 * @description
 *
 * @package     Monapi\Image\ResizeOptions
 * @name        Auto
 * @version     0.1
 */
ZEPHIR_INIT_CLASS(Monapi_Image_ResizeOptions_Auto) {

	ZEPHIR_REGISTER_CLASS_EX(Monapi\\Image\\ResizeOptions, Auto, monapi, image_resizeoptions_auto, monapi_image_resizeoptions_resizeoptionabstract_ce, monapi_image_resizeoptions_auto_method_entry, 0);

	return SUCCESS;

}

/**
 * @param integer $width
 * @param integer $height
 * @param integer $original_width
 * @param integer $original_height
 * @return array
 */
PHP_METHOD(Monapi_Image_ResizeOptions_Auto, getOptimalSize) {

	zval *original_width = NULL, *original_height = NULL;
	zval *width_param = NULL, *height_param = NULL, *original_width_param = NULL, *original_height_param = NULL, *sizes = NULL, *_0, *_1;
	int width, height, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &width_param, &height_param, &original_width_param, &original_height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	if (!original_width_param) {
		ZEPHIR_INIT_VAR(original_width);
		ZVAL_EMPTY_STRING(original_width);
	} else {
		zephir_get_strval(original_width, original_width_param);
	}
	if (!original_height_param) {
		ZEPHIR_INIT_VAR(original_height);
		ZVAL_EMPTY_STRING(original_height);
	} else {
		zephir_get_strval(original_height, original_height_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, width);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, height);
	ZEPHIR_CALL_SELF(&sizes, "getsizebyauto", NULL, _0, _1, original_width, original_height);
	zephir_check_call_status();
	RETURN_CCTOR(sizes);

}

PHP_METHOD(Monapi_Image_ResizeOptions_Auto, getSizeByAuto) {

	zval *width_param = NULL, *height_param = NULL, *original_width_param = NULL, *original_height_param = NULL, *optimal_width = NULL, *optimal_height = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *sizes;
	int width, height, original_width, original_height, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &width_param, &height_param, &original_width_param, &original_height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	original_width = zephir_get_intval(original_width_param);
	original_height = zephir_get_intval(original_height_param);


	if (original_height < original_width) {
		ZEPHIR_INIT_VAR(optimal_width);
		ZVAL_LONG(optimal_width, width);
		ZEPHIR_INIT_VAR(_0);
		ZVAL_LONG(_0, original_width);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_LONG(_1, original_height);
		ZEPHIR_CALL_SELF(&optimal_height, "getsizebyfixedwidth", NULL, optimal_width, _0, _1);
		zephir_check_call_status();
		if (ZEPHIR_GT_LONG(optimal_height, height)) {
			ZEPHIR_INIT_NVAR(optimal_height);
			ZVAL_LONG(optimal_height, height);
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, original_width);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_LONG(_1, original_height);
			ZEPHIR_CALL_SELF(&optimal_width, "getsizebyfixedheight", NULL, optimal_height, _0, _1);
			zephir_check_call_status();
		}
	} else if (original_height > original_width) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, height);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, original_width);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, original_height);
		ZEPHIR_CALL_SELF(&optimal_width, "getsizebyfixedheight", NULL, _0, _1, _2);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(optimal_height);
		ZVAL_LONG(optimal_height, height);
		if (ZEPHIR_GT_LONG(optimal_width, width)) {
			ZEPHIR_INIT_NVAR(optimal_width);
			ZVAL_LONG(optimal_width, width);
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, original_width);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_LONG(_1, original_height);
			ZEPHIR_CALL_SELF(&optimal_height, "getsizebyfixedwidth", NULL, optimal_width, _0, _1);
			zephir_check_call_status();
		}
	} else {
		if (height > width) {
			ZEPHIR_INIT_NVAR(optimal_width);
			ZVAL_LONG(optimal_width, width);
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, width);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_LONG(_1, original_width);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_LONG(_2, original_height);
			ZEPHIR_CALL_SELF(&optimal_height, "getsizebyfixedwidth", NULL, _0, _1, _2);
			zephir_check_call_status();
		} else if (height < width) {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, height);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_LONG(_1, original_width);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_LONG(_2, original_height);
			ZEPHIR_CALL_SELF(&optimal_width, "getsizebyfixedheight", NULL, _0, _1, _2);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(optimal_height);
			ZVAL_LONG(optimal_height, height);
		} else {
			ZEPHIR_INIT_NVAR(optimal_width);
			ZVAL_LONG(optimal_width, width);
			ZEPHIR_INIT_NVAR(optimal_height);
			ZVAL_LONG(optimal_height, height);
		}
	}
	ZEPHIR_INIT_VAR(sizes);
	array_init_size(sizes, 3);
	zephir_array_update_string(&sizes, SL("optimal_width"), &optimal_width, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sizes, SL("optimal_height"), &optimal_height, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(sizes);

}

