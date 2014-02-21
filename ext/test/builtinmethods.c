
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


/**
 * OO operations
 */
ZEPHIR_INIT_CLASS(Test_BuiltInMethods) {

	ZEPHIR_REGISTER_CLASS(Test, BuiltInMethods, test, builtinmethods, test_builtinmethods_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Test_BuiltInMethods, stringMethodLength1) {

	zval _0;


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "hello", 0);
	RETURN_LONG(zephir_fast_strlen_ev(&_0));

}

PHP_METHOD(Test_BuiltInMethods, stringMethodLength2) {

	zval _0;


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "hello", 0);
	RETURN_LONG(zephir_fast_strlen_ev(&_0));

}

PHP_METHOD(Test_BuiltInMethods, stringMethodLength3) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SS(_0, "hello", "hello");
	RETURN_MM_LONG(zephir_fast_strlen_ev(_0));

}

PHP_METHOD(Test_BuiltInMethods, stringMethodLength4) {

	zval *a_param = NULL;
	zval *a = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &a_param);

	zephir_get_strval(a, a_param);


	RETURN_MM_LONG(zephir_fast_strlen_ev(a));

}

PHP_METHOD(Test_BuiltInMethods, stringMethodLength5) {

	zval *a_param = NULL;
	zval *a = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &a_param);

	zephir_get_strval(a, a_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "hello", a);
	RETURN_MM_LONG(zephir_fast_strlen_ev(_0));

}

PHP_METHOD(Test_BuiltInMethods, stringMethodIndex) {

	zval *str_param = NULL, *needle_param = NULL, *_0;
	zval *str = NULL, *needle = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &str_param, &needle_param);

	zephir_get_strval(str, str_param);
	zephir_get_strval(needle, needle_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strpos(_0, str, needle, 0 );
	RETURN_CCTOR(_0);

}

PHP_METHOD(Test_BuiltInMethods, stringMethodIndexWithPosition) {

	int position;
	zval *str_param = NULL, *needle_param = NULL, *position_param = NULL, _0, *_1;
	zval *str = NULL, *needle = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &str_param, &needle_param, &position_param);

	zephir_get_strval(str, str_param);
	zephir_get_strval(needle, needle_param);
	position = zephir_get_intval(position_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, position);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strpos(_1, str, needle, zephir_get_intval(&_0) );
	RETURN_CCTOR(_1);

}

PHP_METHOD(Test_BuiltInMethods, stringMethodTrim1) {

	zval *_0, _1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, " hello \t\n", 0);
	zephir_fast_trim(_0, &_1, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	RETURN_CCTOR(_0);

}

PHP_METHOD(Test_BuiltInMethods, arrayMethodJoin1) {

	zval *a_param = NULL, *_0;
	zval *a = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &a_param);

	zephir_get_arrval(a, a_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_join_str(_0, SL("|"), a TSRMLS_CC);
	RETURN_CCTOR(_0);

}

PHP_METHOD(Test_BuiltInMethods, arrayMethodReverse1) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *a_param = NULL, *_0;
	zval *a = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &a_param);

	zephir_get_arrval(a, a_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "array_reverse", a);
	zephir_check_call_status();
	RETURN_CCTOR(_0);

}

