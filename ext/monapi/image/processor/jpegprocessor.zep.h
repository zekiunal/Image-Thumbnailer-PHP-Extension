
extern zend_class_entry *monapi_image_processor_jpegprocessor_ce;

ZEPHIR_INIT_CLASS(Monapi_Image_Processor_JPegProcessor);

PHP_METHOD(Monapi_Image_Processor_JPegProcessor, createImage);
PHP_METHOD(Monapi_Image_Processor_JPegProcessor, save);

ZEND_BEGIN_ARG_INFO_EX(arginfo_monapi_image_processor_jpegprocessor_createimage, 0, 0, 1)
	ZEND_ARG_INFO(0, file_name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_monapi_image_processor_jpegprocessor_save, 0, 0, 1)
	ZEND_ARG_INFO(0, image)
	ZEND_ARG_INFO(0, filename)
	ZEND_ARG_INFO(0, quality)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(monapi_image_processor_jpegprocessor_method_entry) {
	PHP_ME(Monapi_Image_Processor_JPegProcessor, createImage, arginfo_monapi_image_processor_jpegprocessor_createimage, ZEND_ACC_PUBLIC)
	PHP_ME(Monapi_Image_Processor_JPegProcessor, save, arginfo_monapi_image_processor_jpegprocessor_save, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
