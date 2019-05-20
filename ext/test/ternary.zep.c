
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"


/**
 * Arithmetic operations
 */
ZEPHIR_INIT_CLASS(Test_Ternary) {

	ZEPHIR_REGISTER_CLASS(Test, Ternary, test, ternary, test_ternary_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Test_Ternary, testTernary1) {

	zval _0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&_0);


	if (100) {
		ZVAL_LONG(&_0, (1 + 100));
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	RETURN_MM_CTOR(&_0);

}

PHP_METHOD(Test_Ternary, testTernary2) {

	zval *b_param = NULL, _0;
	zend_bool b;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(1, 1, 0, &b_param);

	b = zephir_get_boolval(b_param);


	if (b) {
		ZEPHIR_MM_ZVAL_STRING(&_0, "foo");
	} else {
		ZEPHIR_MM_ZVAL_STRING(&_0, "bar");
	}
	RETURN_MM_CTOR(&_0);

}

PHP_METHOD(Test_Ternary, testTernaryComplex1) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *a, a_sub, *y, y_sub, _0, _1;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&a_sub);
	ZVAL_UNDEF(&y_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	zephir_fetch_params(1, 2, 0, &a, &y);



	if (100) {
		ZVAL_LONG(&_0, (1 + 100));
	} else {
		ZEPHIR_CALL_METHOD(&_1, a, "y", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_1)) {
			ZEPHIR_CALL_METHOD(&_0, a, "x", NULL, 0);
			zephir_check_call_status();
		} else {
			ZVAL_BOOL(&_0, zephir_array_isset(a, y));
		}
	}
	RETURN_MM_CTOR(&_0);

}

PHP_METHOD(Test_Ternary, testTernaryComplex2) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *a, a_sub, *y, y_sub, _0, _1;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&a_sub);
	ZVAL_UNDEF(&y_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	zephir_fetch_params(1, 2, 0, &a, &y);



	if (100) {
		ZVAL_LONG(&_0, (1 + 100));
	} else {
		ZEPHIR_CALL_METHOD(&_1, a, "y", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_1)) {
			ZEPHIR_CALL_METHOD(&_0, a, "x", NULL, 0);
			zephir_check_call_status();
		} else {
			ZVAL_BOOL(&_0, zephir_array_isset(a, y));
		}
	}
	RETURN_MM_LONG((5 + zephir_get_numberval(&_0)));

}

PHP_METHOD(Test_Ternary, testTernaryComplex3) {

	zval *a, a_sub, _0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&a_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(1, 1, 0, &a);



	if (Z_TYPE_P(a) == IS_RESOURCE) {
		ZEPHIR_MM_ZVAL_STRING(&_0, "unknown");
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	zephir_gettype(return_value, &_0 TSRMLS_CC);
	RETURN_MM();

}

/**
 * @link https://github.com/phalcon/zephir/issues/665
 */
PHP_METHOD(Test_Ternary, testTernaryWithPromotedTemporaryVariable) {

	zval var2, var3, _0, _1;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&var2);
	ZVAL_UNDEF(&var3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_create_array(&var2, 2, 0);
	ZEPHIR_MM_ADD_ENTRY(&var2);
	ZEPHIR_MM_ZVAL_STRING(&_0, "_b_");
	zephir_array_fast_append(&var2, &_0);
	ZEPHIR_MM_ZVAL_STRING(&_0, "_c_");
	zephir_array_fast_append(&var2, &_0);
	if (zephir_array_isset_long(&var2, 1)) {
		zephir_array_fetch_long(&_1, &var2, 1, PH_NOISY, "test/ternary.zep", 44 TSRMLS_CC);
	} else {
		ZEPHIR_MM_ZVAL_STRING(&_1, "");
	}
	zephir_fast_explode_str(&var3, SL("_"), &_1, LONG_MAX TSRMLS_CC);
	RETURN_MM_CTOR(&var3);

}

/**
 * @link https://github.com/phalcon/zephir/issues/297
 */
PHP_METHOD(Test_Ternary, testTernaryAfterLetVariable) {

	zval s;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&s);


	ZVAL_LONG(&s, 23);
	if (1 == 1) {
		ZVAL_LONG(&s, 3);
	} else {
		ZVAL_LONG(&s, 10);
	}
	RETURN_MM_CTOR(&s);

}

PHP_METHOD(Test_Ternary, testShortTernary) {

	zval *a, a_sub, _0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&a_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(1, 1, 0, &a);



	if (!(zephir_is_true(a))) {
		ZVAL_BOOL(&_0, 0);
	} else {
		ZEPHIR_CPY_WRT(&_0, a);
	}
	RETURN_MM_CTOR(&_0);

}

PHP_METHOD(Test_Ternary, testShortTernaryComplex) {

	zval *left, left_sub, *value, value_sub, _0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&left_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(1, 2, 0, &left, &value);



	if (!(zephir_is_true(left))) {
		ZEPHIR_CPY_WRT(&_0, value);
	} else {
		ZEPHIR_CPY_WRT(&_0, left);
	}
	RETURN_MM_CTOR(&_0);

}

