
extern zend_class_entry *test_oo_testinterface_ce;

ZEPHIR_INIT_CLASS(Test_Oo_TestInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_test_oo_testinterface_setparam, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, param, "Param",0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(test_oo_testinterface_method_entry) {
	PHP_ABSTRACT_ME(Test_Oo_TestInterface, setParam, arginfo_test_oo_testinterface_setparam)
  PHP_FE_END
};
