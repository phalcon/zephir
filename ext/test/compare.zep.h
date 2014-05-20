
extern zend_class_entry *test_compare_ce;

ZEPHIR_INIT_CLASS(Test_Compare);

PHP_METHOD(Test_Compare, isLessInt);
PHP_METHOD(Test_Compare, isLessDouble);
PHP_METHOD(Test_Compare, isLessThenPi);
PHP_METHOD(Test_Compare, isMoreThenPi);

ZEND_BEGIN_ARG_INFO_EX(arginfo_test_compare_islessint, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_test_compare_islessdouble, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_test_compare_islessthenpi, 0, 0, 1)
	ZEND_ARG_INFO(0, a)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_test_compare_ismorethenpi, 0, 0, 1)
	ZEND_ARG_INFO(0, a)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(test_compare_method_entry) {
	PHP_ME(Test_Compare, isLessInt, arginfo_test_compare_islessint, ZEND_ACC_PUBLIC)
	PHP_ME(Test_Compare, isLessDouble, arginfo_test_compare_islessdouble, ZEND_ACC_PUBLIC)
	PHP_ME(Test_Compare, isLessThenPi, arginfo_test_compare_islessthenpi, ZEND_ACC_PUBLIC)
	PHP_ME(Test_Compare, isMoreThenPi, arginfo_test_compare_ismorethenpi, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
