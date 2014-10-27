
extern zend_class_entry *monapi_image_resizeoptions_exact_ce;

ZEPHIR_INIT_CLASS(Monapi_Image_ResizeOptions_Exact);

PHP_METHOD(Monapi_Image_ResizeOptions_Exact, getOptimalSize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_monapi_image_resizeoptions_exact_getoptimalsize, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, original_width)
	ZEND_ARG_INFO(0, original_height)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(monapi_image_resizeoptions_exact_method_entry) {
	PHP_ME(Monapi_Image_ResizeOptions_Exact, getOptimalSize, arginfo_monapi_image_resizeoptions_exact_getoptimalsize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
