
extern zend_class_entry *typehints_both_ce;

ZEPHIR_INIT_CLASS(TypeHints_Both);

PHP_METHOD(TypeHints_Both, both);

ZEND_BEGIN_ARG_INFO_EX(arginfo_typehints_both_both, 0, 0, 1)
	ZEND_ARG_INFO(0, _string)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(typehints_both_method_entry) {
	PHP_ME(TypeHints_Both, both, arginfo_typehints_both_both, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
