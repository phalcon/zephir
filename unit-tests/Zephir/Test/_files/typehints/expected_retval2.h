
extern zend_class_entry *typehints_retval_ce;

ZEPHIR_INIT_CLASS(TypeHints_RetVal);

PHP_METHOD(TypeHints_RetVal, retval_var);
PHP_METHOD(TypeHints_RetVal, retval_string);
PHP_METHOD(TypeHints_RetVal, retval_boolean);
PHP_METHOD(TypeHints_RetVal, retval_int);
PHP_METHOD(TypeHints_RetVal, retval_long);
PHP_METHOD(TypeHints_RetVal, retval_double);
PHP_METHOD(TypeHints_RetVal, retval_retval);

ZEPHIR_INIT_FUNCS(typehints_retval_method_entry) {
	PHP_ME(TypeHints_RetVal, retval_var, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(TypeHints_RetVal, retval_string, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(TypeHints_RetVal, retval_boolean, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(TypeHints_RetVal, retval_int, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(TypeHints_RetVal, retval_long, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(TypeHints_RetVal, retval_double, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(TypeHints_RetVal, retval_retval, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
