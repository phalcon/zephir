
extern zend_class_entry *test_oo_oodynamicb_ce;

ZEPHIR_INIT_CLASS(Test_Oo_OoDynamicB);

PHP_METHOD(Test_Oo_OoDynamicB, execute);
PHP_METHOD(Test_Oo_OoDynamicB, execute2);

ZEPHIR_INIT_FUNCS(test_oo_oodynamicb_method_entry) {
	PHP_ME(Test_Oo_OoDynamicB, execute, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Test_Oo_OoDynamicB, execute2, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
