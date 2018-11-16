
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Test_FunctionExists) {

	ZEPHIR_REGISTER_CLASS(Test, FunctionExists, test, functionexists, test_functionexists_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Test_FunctionExists, testWithPassedName) {

	zval *func_param = NULL;
	zval func;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&func);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &func_param);

	zephir_get_strval(&func, func_param);


	RETURN_MM_BOOL((zephir_function_exists(&func TSRMLS_CC)  == SUCCESS));

}

PHP_METHOD(Test_FunctionExists, testBuiltInFunctions) {

	zval result, functions;
	zval func, _0, *_1, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&func);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&functions);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	ZEPHIR_INIT_VAR(&functions);
	zephir_create_array(&functions, 8, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "substr");
	zephir_array_fast_append(&functions, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "cubstr");
	zephir_array_fast_append(&functions, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "ucfirst");
	zephir_array_fast_append(&functions, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "bcfirst");
	zephir_array_fast_append(&functions, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "stripos");
	zephir_array_fast_append(&functions, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "ktripos");
	zephir_array_fast_append(&functions, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "trim");
	zephir_array_fast_append(&functions, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "prim");
	zephir_array_fast_append(&functions, &_0);
	zephir_is_iterable(&functions, 0, "test/functionexists.zep", 31);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&functions), _1)
	{
		ZEPHIR_INIT_NVAR(&func);
		ZVAL_COPY(&func, _1);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_BOOL(&_2$$3, (zephir_function_exists(&func TSRMLS_CC)  == SUCCESS));
		zephir_array_update_zval(&result, &func, &_2$$3, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&func);
	RETURN_CTOR(&result);

}

PHP_METHOD(Test_FunctionExists, testWithString) {

	zval *this_ptr = getThis();


	RETURN_BOOL((zephir_function_exists_ex(SL("substr") TSRMLS_CC) == SUCCESS));

}

