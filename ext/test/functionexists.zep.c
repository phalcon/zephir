
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
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Test_FunctionExists) {

	ZEPHIR_REGISTER_CLASS(Test, FunctionExists, test, functionexists, test_functionexists_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Test_FunctionExists, testWithPassedName) {

	zval *func_param = NULL;
	zval func;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&func);

	zephir_fetch_params(1, 1, 0, &func_param);

	zephir_get_strval(&func, func_param);


	RETURN_MM_BOOL((zephir_function_exists(&func TSRMLS_CC)  == SUCCESS));

}

PHP_METHOD(Test_FunctionExists, testBuiltInFunctions) {

	zval result, functions;
	zval func, _0, *_1, _2, _3$$3, _4$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&func);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&functions);


	array_init(&result);
	ZEPHIR_MM_ADD_ENTRY(&result);
	zephir_create_array(&functions, 8, 0);
	ZEPHIR_MM_ADD_ENTRY(&functions);
	ZEPHIR_MM_ZVAL_STRING(&_0, "substr");
	zephir_array_fast_append(&functions, &_0);
	ZEPHIR_MM_ZVAL_STRING(&_0, "cubstr");
	zephir_array_fast_append(&functions, &_0);
	ZEPHIR_MM_ZVAL_STRING(&_0, "ucfirst");
	zephir_array_fast_append(&functions, &_0);
	ZEPHIR_MM_ZVAL_STRING(&_0, "bcfirst");
	zephir_array_fast_append(&functions, &_0);
	ZEPHIR_MM_ZVAL_STRING(&_0, "stripos");
	zephir_array_fast_append(&functions, &_0);
	ZEPHIR_MM_ZVAL_STRING(&_0, "ktripos");
	zephir_array_fast_append(&functions, &_0);
	ZEPHIR_MM_ZVAL_STRING(&_0, "trim");
	zephir_array_fast_append(&functions, &_0);
	ZEPHIR_MM_ZVAL_STRING(&_0, "prim");
	zephir_array_fast_append(&functions, &_0);
	zephir_is_iterable(&functions, 0, "test/functionexists.zep", 31);
	if (Z_TYPE_P(&functions) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&functions), _1)
		{
			ZEPHIR_CPY_WRT(&func, _1);
			ZVAL_BOOL(&_3$$3, (zephir_function_exists(&func TSRMLS_CC)  == SUCCESS));
			zephir_array_update_zval(&result, &func, &_3$$3, PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &functions, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &functions, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&func, &functions, "current", NULL, 0);
			zephir_check_call_status();
				ZVAL_BOOL(&_4$$4, (zephir_function_exists(&func TSRMLS_CC)  == SUCCESS));
				zephir_array_update_zval(&result, &func, &_4$$4, PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &functions, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	RETURN_MM_CTOR(&result);

}

PHP_METHOD(Test_FunctionExists, testWithString) {

	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();

	RETURN_MM_BOOL((zephir_function_exists_ex(SL("substr") TSRMLS_CC) == SUCCESS));

}

