
extern zend_class_entry *monapi_image_resizeoptions_auto_ce;

ZEPHIR_INIT_CLASS(Monapi_Image_ResizeOptions_Auto);

PHP_METHOD(Monapi_Image_ResizeOptions_Auto, getOptimalSize);
PHP_METHOD(Monapi_Image_ResizeOptions_Auto, getSizeByAuto);

ZEND_BEGIN_ARG_INFO_EX(arginfo_monapi_image_resizeoptions_auto_getoptimalsize, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, original_width)
	ZEND_ARG_INFO(0, original_height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_monapi_image_resizeoptions_auto_getsizebyauto, 0, 0, 4)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, original_width)
	ZEND_ARG_INFO(0, original_height)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(monapi_image_resizeoptions_auto_method_entry) {
	PHP_ME(Monapi_Image_ResizeOptions_Auto, getOptimalSize, arginfo_monapi_image_resizeoptions_auto_getoptimalsize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Monapi_Image_ResizeOptions_Auto, getSizeByAuto, arginfo_monapi_image_resizeoptions_auto_getsizebyauto, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
  PHP_FE_END
};
