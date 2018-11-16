
extern zend_class_entry *test_flow_switchflow_ce;

ZEPHIR_INIT_CLASS(Test_Flow_SwitchFlow);

PHP_METHOD(Test_Flow_SwitchFlow, testSwitch1);
PHP_METHOD(Test_Flow_SwitchFlow, testSwitch2);
PHP_METHOD(Test_Flow_SwitchFlow, testSwitch3);
PHP_METHOD(Test_Flow_SwitchFlow, testSwitch4);
PHP_METHOD(Test_Flow_SwitchFlow, testSwitch5);
PHP_METHOD(Test_Flow_SwitchFlow, testSwitch6);
PHP_METHOD(Test_Flow_SwitchFlow, testSwitch7);
PHP_METHOD(Test_Flow_SwitchFlow, testSwitch8);
PHP_METHOD(Test_Flow_SwitchFlow, testSwitch9);
PHP_METHOD(Test_Flow_SwitchFlow, testSwitch10);
PHP_METHOD(Test_Flow_SwitchFlow, testSwitch11);
PHP_METHOD(Test_Flow_SwitchFlow, testSwitch12);
PHP_METHOD(Test_Flow_SwitchFlow, testSwitch13);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_flow_switchflow_testswitch1, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_flow_switchflow_testswitch1, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_flow_switchflow_testswitch2, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_flow_switchflow_testswitch2, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_flow_switchflow_testswitch3, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_flow_switchflow_testswitch3, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_flow_switchflow_testswitch4, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_flow_switchflow_testswitch4, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_flow_switchflow_testswitch5, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_flow_switchflow_testswitch5, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_flow_switchflow_testswitch6, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_flow_switchflow_testswitch6, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_flow_switchflow_testswitch7, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_flow_switchflow_testswitch7, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_flow_switchflow_testswitch8, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_flow_switchflow_testswitch8, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_flow_switchflow_testswitch9, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_flow_switchflow_testswitch9, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_flow_switchflow_testswitch10, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_flow_switchflow_testswitch10, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_test_flow_switchflow_testswitch12, 0, 0, 2)
	ZEND_ARG_INFO(0, var1)
	ZEND_ARG_INFO(0, var2)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_test_flow_switchflow_testswitch13, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, a, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(test_flow_switchflow_method_entry) {
	PHP_ME(Test_Flow_SwitchFlow, testSwitch1, arginfo_test_flow_switchflow_testswitch1, ZEND_ACC_PUBLIC)
	PHP_ME(Test_Flow_SwitchFlow, testSwitch2, arginfo_test_flow_switchflow_testswitch2, ZEND_ACC_PUBLIC)
	PHP_ME(Test_Flow_SwitchFlow, testSwitch3, arginfo_test_flow_switchflow_testswitch3, ZEND_ACC_PUBLIC)
	PHP_ME(Test_Flow_SwitchFlow, testSwitch4, arginfo_test_flow_switchflow_testswitch4, ZEND_ACC_PUBLIC)
	PHP_ME(Test_Flow_SwitchFlow, testSwitch5, arginfo_test_flow_switchflow_testswitch5, ZEND_ACC_PUBLIC)
	PHP_ME(Test_Flow_SwitchFlow, testSwitch6, arginfo_test_flow_switchflow_testswitch6, ZEND_ACC_PUBLIC)
	PHP_ME(Test_Flow_SwitchFlow, testSwitch7, arginfo_test_flow_switchflow_testswitch7, ZEND_ACC_PUBLIC)
	PHP_ME(Test_Flow_SwitchFlow, testSwitch8, arginfo_test_flow_switchflow_testswitch8, ZEND_ACC_PUBLIC)
	PHP_ME(Test_Flow_SwitchFlow, testSwitch9, arginfo_test_flow_switchflow_testswitch9, ZEND_ACC_PUBLIC)
	PHP_ME(Test_Flow_SwitchFlow, testSwitch10, arginfo_test_flow_switchflow_testswitch10, ZEND_ACC_PUBLIC)
	PHP_ME(Test_Flow_SwitchFlow, testSwitch11, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Test_Flow_SwitchFlow, testSwitch12, arginfo_test_flow_switchflow_testswitch12, ZEND_ACC_PUBLIC)
	PHP_ME(Test_Flow_SwitchFlow, testSwitch13, arginfo_test_flow_switchflow_testswitch13, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
