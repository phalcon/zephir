
extern zend_class_entry *test_builtinmethods_ce;

ZEPHIR_INIT_CLASS(Test_BuiltInMethods);

PHP_METHOD(Test_BuiltInMethods, stringMethodLength1);
PHP_METHOD(Test_BuiltInMethods, stringMethodLength2);
PHP_METHOD(Test_BuiltInMethods, stringMethodLength3);
PHP_METHOD(Test_BuiltInMethods, stringMethodLength4);
PHP_METHOD(Test_BuiltInMethods, stringMethodLength5);
PHP_METHOD(Test_BuiltInMethods, stringMethodIndex);
PHP_METHOD(Test_BuiltInMethods, stringMethodIndexWithPosition);
PHP_METHOD(Test_BuiltInMethods, stringMethodTrim1);
PHP_METHOD(Test_BuiltInMethods, arrayMethodJoin1);
PHP_METHOD(Test_BuiltInMethods, arrayMethodReverse1);

ZEND_BEGIN_ARG_INFO_EX(arginfo_test_builtinmethods_stringmethodlength4, 0, 0, 1)
	ZEND_ARG_INFO(0, a)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_test_builtinmethods_stringmethodlength5, 0, 0, 1)
	ZEND_ARG_INFO(0, a)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_test_builtinmethods_stringmethodindex, 0, 0, 2)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, needle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_test_builtinmethods_stringmethodindexwithposition, 0, 0, 3)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, needle)
	ZEND_ARG_INFO(0, position)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_test_builtinmethods_arraymethodjoin1, 0, 0, 1)
	ZEND_ARG_INFO(0, a)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_test_builtinmethods_arraymethodreverse1, 0, 0, 1)
	ZEND_ARG_INFO(0, a)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(test_builtinmethods_method_entry) {
	PHP_ME(Test_BuiltInMethods, stringMethodLength1, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Test_BuiltInMethods, stringMethodLength2, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Test_BuiltInMethods, stringMethodLength3, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Test_BuiltInMethods, stringMethodLength4, arginfo_test_builtinmethods_stringmethodlength4, ZEND_ACC_PUBLIC)
	PHP_ME(Test_BuiltInMethods, stringMethodLength5, arginfo_test_builtinmethods_stringmethodlength5, ZEND_ACC_PUBLIC)
	PHP_ME(Test_BuiltInMethods, stringMethodIndex, arginfo_test_builtinmethods_stringmethodindex, ZEND_ACC_PUBLIC)
	PHP_ME(Test_BuiltInMethods, stringMethodIndexWithPosition, arginfo_test_builtinmethods_stringmethodindexwithposition, ZEND_ACC_PUBLIC)
	PHP_ME(Test_BuiltInMethods, stringMethodTrim1, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Test_BuiltInMethods, arrayMethodJoin1, arginfo_test_builtinmethods_arraymethodjoin1, ZEND_ACC_PUBLIC)
	PHP_ME(Test_BuiltInMethods, arrayMethodReverse1, arginfo_test_builtinmethods_arraymethodreverse1, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
