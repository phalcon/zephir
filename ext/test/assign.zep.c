
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * Control Flow
 */
ZEPHIR_INIT_CLASS(Test_Assign) {

	ZEPHIR_REGISTER_CLASS(Test, Assign, test, assign, test_assign_method_entry, 0);

	zend_declare_property_null(test_assign_ce, SL("testVar"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(test_assign_ce, SL("myArray"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(test_assign_ce, SL("testVarStatic"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Test_Assign, getTestVar) {

	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();

	RETURN_MM_MEMBER(getThis(), "testVar");

}

PHP_METHOD(Test_Assign, getMyArray) {

	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();

	RETURN_MM_MEMBER(getThis(), "myArray");

}

PHP_METHOD(Test_Assign, testAssign1) {

	zend_long a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = 1;
	RETURN_MM_LONG(a);

}

PHP_METHOD(Test_Assign, testAssign2) {

	zend_long a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = 1;
	RETURN_MM_LONG(a);

}

PHP_METHOD(Test_Assign, testAssign3) {

	zend_long a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = 0;
	RETURN_MM_LONG(a);

}

PHP_METHOD(Test_Assign, testAssign4) {

	zend_long a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = 0;
	RETURN_MM_LONG(a);

}

PHP_METHOD(Test_Assign, testAssign5) {

	zend_long a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = (long) (2.0);
	RETURN_MM_LONG(a);

}

PHP_METHOD(Test_Assign, testAssign6) {

	zend_bool a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = ((1) ? 1 : 0);
	RETURN_MM_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign7) {

	zend_bool a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = ((1.0 != 0.0) ? 1 : 0);
	RETURN_MM_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign8) {

	zend_bool a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = 1;
	RETURN_MM_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign9) {

	zend_bool a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = 0;
	RETURN_MM_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign10) {

	zend_bool a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = 0;
	RETURN_MM_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign11) {

	double a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = 0.0;
	RETURN_MM_DOUBLE(a);

}

PHP_METHOD(Test_Assign, testAssign12) {

	double a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = (double) (4);
	RETURN_MM_DOUBLE(a);

}

PHP_METHOD(Test_Assign, testAssign13) {

	double a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = 0;
	RETURN_MM_DOUBLE(a);

}

PHP_METHOD(Test_Assign, testAssign14) {

	double a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = 1;
	RETURN_MM_DOUBLE(a);

}

PHP_METHOD(Test_Assign, testAssign15) {

	double a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = 5.0;
	RETURN_MM_DOUBLE(a);

}

PHP_METHOD(Test_Assign, testAssign16) {

	zend_long a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = 1;
	RETURN_MM_LONG(a);

}

PHP_METHOD(Test_Assign, testAssign17) {

	double a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = 1.0;
	RETURN_MM_DOUBLE(a);

}

PHP_METHOD(Test_Assign, testAssign18) {

	zend_bool a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = 0;
	RETURN_MM_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign19) {

	zend_bool a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = 1;
	RETURN_MM_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign20) {

	zval a;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&a);


	ZVAL_NULL(&a);
	RETURN_MM_CTOR(&a);

}

PHP_METHOD(Test_Assign, testAssign21) {

	zend_long a = 0, b = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = 1;
	b = a;
	RETURN_MM_LONG(b);

}

PHP_METHOD(Test_Assign, testAssign22) {

	double a = 0, b = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = 1.0;
	b = a;
	RETURN_MM_DOUBLE(b);

}

PHP_METHOD(Test_Assign, testAssign23) {

	zend_bool a = 0, b = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = 1;
	b = a;
	RETURN_MM_BOOL(b);

}

PHP_METHOD(Test_Assign, testAssign24) {

	double b = 0;
	zend_long a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = 1;
	b = (double) a;
	RETURN_MM_DOUBLE(b);

}

PHP_METHOD(Test_Assign, testAssign25) {

	double b = 0;
	zend_long a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = 1;
	b = (double) a;
	RETURN_MM_DOUBLE(b);

}

PHP_METHOD(Test_Assign, testAssign26) {

	double a = 0;
	zend_long b = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	a = (double) (1);
	b = (long) a;
	RETURN_MM_LONG(b);

}

PHP_METHOD(Test_Assign, testAssign27) {

	double a = 0;
	zend_long b = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	b = 1;
	a = (double) b;
	RETURN_MM_DOUBLE(a);

}

PHP_METHOD(Test_Assign, testAssign28) {

	zend_bool a = 0;
	zend_long b = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	b = 1;
	a = ((b) ? 1 : 0);
	RETURN_MM_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign29) {

	zend_bool a = 0;
	double b = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	b = 1.0;
	a = ((b != 0.0) ? 1 : 0);
	RETURN_MM_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign30) {

	zend_long a = 0;
	zend_bool b = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	b = 0;
	a = b;
	RETURN_MM_LONG(a);

}

PHP_METHOD(Test_Assign, testAssign31) {

	double a = 0;
	zend_bool b = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	b = 0;
	a = (double) b;
	RETURN_MM_DOUBLE(a);

}

PHP_METHOD(Test_Assign, testAssign32) {

	zend_bool b = 0, a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	b = 0;
	a = b;
	RETURN_MM_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign33) {

	zend_bool b = 0, a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	b = 0;
	a = b;
	RETURN_MM_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign34) {

	zend_bool a = 0;
	zend_long b = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	b = 0;
	a = ((b) ? 1 : 0);
	RETURN_MM_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign35) {

	zend_bool a = 0;
	double b = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	b = 0;
	a = ((b != 0.0) ? 1 : 0);
	RETURN_MM_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign36) {

	zend_bool b = 0, a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	b = 0;
	a = b;
	RETURN_MM_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign37) {

	zval _1, _4;
	zval v, arr, _0, _2, _3;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);


	ZEPHIR_MM_ZVAL_STRING(&v, "abc");
	array_init(&arr);
	ZEPHIR_MM_ADD_ENTRY(&arr);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	add_assoc_stringl_ex(&_1, SL("b_key"), SL("b_val"));
	array_init(&_2);
	ZEPHIR_MM_ADD_ENTRY(&_2);
	zephir_array_update_string(&_1, SL("b"), &_2, PH_SEPARATE);
	zephir_array_update_string(&_0, SL("a"), &_1, PH_SEPARATE);
	ZEPHIR_CPY_WRT(&arr, &_0);
	ZEPHIR_MM_ZVAL_STRING(&_2, "d_val");
	zephir_array_update_multi(&arr, &_2, SL("sss"), 6, SL("a"), SL("b"), SL("d_key"));
	ZVAL_LONG(&_2, 1);
	zephir_array_update_string(&arr, SL("s"), &_2, PH_SEPARATE);
	ZEPHIR_MM_ZVAL_STRING(&_3, "f");
	zephir_array_update_multi(&arr, &_3, SL("sssss"), 10, SL("a"), SL("b"), SL("c"), SL("d"), SL("e"));
	zephir_create_array(&_1, 1, 0);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	zephir_create_array(&_4, 1, 0);
	ZEPHIR_MM_ADD_ENTRY(&_4);
	add_index_long(&_4, 3, 4);
	zephir_array_update_long(&_1, 2, &_4, PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&arr, 1, &_1, PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZVAL_LONG(&_3, 6);
	zephir_array_update_multi(&arr, &_3, SL("lll"), 3, 1, 2, 5);
	zephir_array_update_multi(&arr, &v, SL("llz"), 3, 1, 2, &v);
	RETURN_MM_CTOR(&arr);

}

PHP_METHOD(Test_Assign, testAssign38) {

	zval *index, index_sub, arr, _0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(1, 1, 0, &index);



	array_init(&arr);
	ZEPHIR_MM_ADD_ENTRY(&arr);
	ZEPHIR_MM_ZVAL_STRING(&_0, "val");
	zephir_array_update_zval(&arr, index, &_0, PH_SEPARATE);
	RETURN_MM_CTOR(&arr);

}

PHP_METHOD(Test_Assign, testAssign39) {

	zval a, b, c;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&b);
	ZVAL_UNDEF(&c);


	ZEPHIR_MM_ZVAL_STRING(&a, "hello");
	ZVAL_BOOL(&b, 0);
	ZVAL_LONG(&a, 10);
	ZEPHIR_MM_ZVAL_STRING(&b, "140");
	zephir_add_function(&c, &a, &b);
	RETURN_MM_CTOR(&c);

}

PHP_METHOD(Test_Assign, testAssign40) {

	zval a, b;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&b);


	object_init(&b);
	array_init(&a);
	ZEPHIR_MM_ADD_ENTRY(&a);
	ZEPHIR_MM_ZVAL_STRING(&a, "123");
	ZVAL_LONG(&b, 7);
	zephir_sub_function(return_value, &a, &b);
	RETURN_MM();

}

/**
 * @link https://github.com/phalcon/zephir/issues/1573
 */
PHP_METHOD(Test_Assign, testAssign41) {

	zval *num_param = NULL;
	zend_long num, a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();

	zephir_fetch_params(1, 1, 0, &num_param);

	num = zephir_get_intval(num_param);


	a = 42;
	a /= num;
	RETURN_MM_LONG(a);

}

/**
 * @link https://github.com/phalcon/zephir/issues/1573
 */
PHP_METHOD(Test_Assign, testAssign42) {

	zval *num_param = NULL;
	zend_long num, a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();

	zephir_fetch_params(1, 1, 0, &num_param);

	num = zephir_get_intval(num_param);


	a = 2;
	num /= a;
	RETURN_MM_LONG(num);

}

PHP_METHOD(Test_Assign, testAssign43) {

	zval *num_param = NULL;
	zend_long num, a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();

	zephir_fetch_params(1, 1, 0, &num_param);

	num = zephir_get_intval(num_param);


	a = 43;
	a %= num;
	RETURN_MM_LONG(a);

}

PHP_METHOD(Test_Assign, testAssign44) {

	zval *num_param = NULL;
	zend_long num, a = 0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();

	zephir_fetch_params(1, 1, 0, &num_param);

	num = zephir_get_intval(num_param);


	a = 2;
	num %= a;
	RETURN_MM_LONG(num);

}

PHP_METHOD(Test_Assign, testPropertyAssign1) {

	zval __$null, __$true, __$false, _0, _1;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 1);
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(&_0, 1.5);
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	zephir_update_property_zval(this_ptr, SL("testVar"), &__$null);
	if (0) {
		zephir_update_property_zval(this_ptr, SL("testVar"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("testVar"), &__$false);
	}
	if (1) {
		zephir_update_property_zval(this_ptr, SL("testVar"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("testVar"), &__$false);
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 'A');
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	ZEPHIR_MM_ZVAL_STRING(&_1, "hello");
	zephir_update_property_zval(this_ptr, SL("testVar"), &_1);
	array_init(&_1);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	zephir_update_property_zval(this_ptr, SL("testVar"), &_1);
	RETURN_MM_MEMBER(getThis(), "testVar");

}

PHP_METHOD(Test_Assign, testPropertyAssign2) {

	zval f;
	char e;
	zend_bool d;
	double b;
	zend_long a;
	zval __$true, __$false, c, _0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&c);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&f);


	a = 1;
	b = 1.5;
	ZVAL_NULL(&c);
	d = 0;
	e = 'A';
	array_init(&f);
	ZEPHIR_MM_ADD_ENTRY(&f);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, a);
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(&_0, b);
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	zephir_update_property_zval(this_ptr, SL("testVar"), &c);
	if (d) {
		zephir_update_property_zval(this_ptr, SL("testVar"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("testVar"), &__$false);
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, e);
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	zephir_update_property_zval(this_ptr, SL("testVar"), &f);
	RETURN_MM_MEMBER(getThis(), "testVar");

}

PHP_METHOD(Test_Assign, testPropertyIncr1) {

	zval _0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&_0);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 1);
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("testVar") TSRMLS_CC));
	RETURN_MM_MEMBER(getThis(), "testVar");

}

PHP_METHOD(Test_Assign, testPropertyAddAssign1) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	ZVAL_LONG(&_1, 2);
	zephir_read_property(&_0, this_ptr, SL("testVar"), PH_NOISY_CC);
	ZEPHIR_ADD_ASSIGN(&_0, &_1)
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	RETURN_MM_MEMBER(getThis(), "testVar");

}

PHP_METHOD(Test_Assign, testPropertyAddAssign2) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 1);
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	ZVAL_LONG(&_1, 2);
	zephir_read_property(&_0, this_ptr, SL("testVar"), PH_NOISY_CC);
	ZEPHIR_ADD_ASSIGN(&_0, &_1)
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	RETURN_MM_MEMBER(getThis(), "testVar");

}

PHP_METHOD(Test_Assign, testPropertyAssignValuePlus1) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 1);
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	zephir_read_property(&_0, this_ptr, SL("testVar"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, (zephir_get_numberval(&_0) + 1));
	zephir_update_property_zval(this_ptr, SL("testVar"), &_1);
	RETURN_MM_MEMBER(getThis(), "testVar");

}

PHP_METHOD(Test_Assign, testPropertyDecr) {

	zval _0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&_0);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 2);
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("testVar") TSRMLS_CC));
	RETURN_MM_MEMBER(getThis(), "testVar");

}

PHP_METHOD(Test_Assign, testPropertySubAssign1) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	ZVAL_LONG(&_1, 2);
	zephir_read_property(&_0, this_ptr, SL("testVar"), PH_NOISY_CC);
	ZEPHIR_SUB_ASSIGN(&_0, &_1)
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	RETURN_MM_MEMBER(getThis(), "testVar");

}

PHP_METHOD(Test_Assign, testPropertySubAssign2) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 1);
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	ZVAL_LONG(&_1, 2);
	zephir_read_property(&_0, this_ptr, SL("testVar"), PH_NOISY_CC);
	ZEPHIR_SUB_ASSIGN(&_0, &_1)
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	RETURN_MM_MEMBER(getThis(), "testVar");

}

PHP_METHOD(Test_Assign, testPropertyMulAssign1) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 1);
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	ZVAL_LONG(&_1, 2);
	zephir_read_property(&_0, this_ptr, SL("testVar"), PH_NOISY_CC);
	ZEPHIR_MUL_ASSIGN(&_0, &_1)
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	RETURN_MM_MEMBER(getThis(), "testVar");

}

PHP_METHOD(Test_Assign, testPropertyMulAssign2) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 1);
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	ZVAL_LONG(&_1, 3);
	zephir_read_property(&_0, this_ptr, SL("testVar"), PH_NOISY_CC);
	ZEPHIR_MUL_ASSIGN(&_0, &_1)
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	RETURN_MM_MEMBER(getThis(), "testVar");

}

PHP_METHOD(Test_Assign, testPropertyAssignStringConcat) {

	zval _0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_ZVAL_STRING(&_0, "test");
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	ZEPHIR_MM_CONCAT_SELF_STR(&_0, " string", sizeof(" string")-1);
	zephir_update_property_zval(this_ptr, SL("testVar"), &_0);
	RETURN_MM_MEMBER(getThis(), "testVar");

}

PHP_METHOD(Test_Assign, testPropertyArray1) {

	zval __$null, __$true, __$false, _0, _1, _2;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	array_init(&_0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_update_property_zval(this_ptr, SL("myArray"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, 1);
	zephir_update_property_array_append(this_ptr, SL("myArray"), &_1);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(&_1, 1.5);
	zephir_update_property_array_append(this_ptr, SL("myArray"), &_1);
	zephir_update_property_array_append(this_ptr, SL("myArray"), &__$null);
	if (0) {
		zephir_update_property_array_append(this_ptr, SL("myArray"), &__$true);
	} else {
		zephir_update_property_array_append(this_ptr, SL("myArray"), &__$false);
	}
	if (1) {
		zephir_update_property_array_append(this_ptr, SL("myArray"), &__$true);
	} else {
		zephir_update_property_array_append(this_ptr, SL("myArray"), &__$false);
	}
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, 'A');
	zephir_update_property_array_append(this_ptr, SL("myArray"), &_1);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZEPHIR_MM_ZVAL_STRING(&_1, "hello");
	zephir_update_property_array_append(this_ptr, SL("myArray"), &_1);
	array_init(&_2);
	ZEPHIR_MM_ADD_ENTRY(&_2);
	zephir_update_property_array_append(this_ptr, SL("myArray"), &_2);
	RETURN_MM_MEMBER(getThis(), "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray2) {

	zval f;
	char e;
	zend_bool d;
	zval c, _0, _1;
	double b;
	zend_long a;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&c);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&f);


	a = 1;
	b = 1.5;
	ZVAL_NULL(&c);
	d = 0;
	e = 'A';
	array_init(&f);
	ZEPHIR_MM_ADD_ENTRY(&f);
	array_init(&_0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_update_property_zval(this_ptr, SL("myArray"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, a);
	zephir_update_property_array_append(this_ptr, SL("myArray"), &_1);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(&_1, b);
	zephir_update_property_array_append(this_ptr, SL("myArray"), &_1);
	zephir_update_property_array_append(this_ptr, SL("myArray"), &c);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_BOOL(&_1, d);
	zephir_update_property_array_append(this_ptr, SL("myArray"), &_1);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, e);
	zephir_update_property_array_append(this_ptr, SL("myArray"), &_1);
	zephir_update_property_array_append(this_ptr, SL("myArray"), &f);
	RETURN_MM_MEMBER(getThis(), "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray3) {

	zval __$null, __$false, __$true, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);


	array_init(&_0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_update_property_zval(this_ptr, SL("myArray"), &_0);
	ZVAL_LONG(&_1, 0);
	ZVAL_LONG(&_2, 1);
	zephir_update_property_array(this_ptr, SL("myArray"), &_1, &_2);
	ZVAL_LONG(&_3, 0);
	ZVAL_DOUBLE(&_4, 1.5);
	zephir_update_property_array(this_ptr, SL("myArray"), &_3, &_4);
	ZVAL_LONG(&_5, 0);
	zephir_update_property_array(this_ptr, SL("myArray"), &_5, &__$null);
	ZVAL_LONG(&_6, 0);
	zephir_update_property_array(this_ptr, SL("myArray"), &_6, &__$false);
	ZVAL_LONG(&_7, 0);
	zephir_update_property_array(this_ptr, SL("myArray"), &_7, &__$true);
	ZVAL_LONG(&_8, 0);
	ZVAL_LONG(&_9, 'A');
	zephir_update_property_array(this_ptr, SL("myArray"), &_8, &_9);
	array_init(&_10);
	ZEPHIR_MM_ADD_ENTRY(&_10);
	ZVAL_LONG(&_11, 0);
	zephir_update_property_array(this_ptr, SL("myArray"), &_11, &_10);
	RETURN_MM_MEMBER(getThis(), "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray4) {

	zval *index, index_sub, __$null, __$false, __$true, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&index_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	zephir_fetch_params(1, 1, 0, &index);



	array_init(&_0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_update_property_zval(this_ptr, SL("myArray"), &_0);
	ZVAL_LONG(&_1, 1);
	zephir_update_property_array(this_ptr, SL("myArray"), index, &_1);
	ZVAL_DOUBLE(&_2, 1.5);
	zephir_update_property_array(this_ptr, SL("myArray"), index, &_2);
	zephir_update_property_array(this_ptr, SL("myArray"), index, &__$null);
	zephir_update_property_array(this_ptr, SL("myArray"), index, &__$false);
	zephir_update_property_array(this_ptr, SL("myArray"), index, &__$true);
	ZVAL_LONG(&_3, 'A');
	zephir_update_property_array(this_ptr, SL("myArray"), index, &_3);
	array_init(&_4);
	ZEPHIR_MM_ADD_ENTRY(&_4);
	zephir_update_property_array(this_ptr, SL("myArray"), index, &_4);
	RETURN_MM_MEMBER(getThis(), "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray5) {

	zval *index_param = NULL, __$null, __$false, __$true, _0, _1, _2, _3, _4;
	zval index;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&index);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(&index, index_param);


	array_init(&_0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_update_property_zval(this_ptr, SL("myArray"), &_0);
	ZVAL_LONG(&_1, 1);
	zephir_update_property_array(this_ptr, SL("myArray"), &index, &_1);
	ZVAL_DOUBLE(&_2, 1.5);
	zephir_update_property_array(this_ptr, SL("myArray"), &index, &_2);
	zephir_update_property_array(this_ptr, SL("myArray"), &index, &__$null);
	zephir_update_property_array(this_ptr, SL("myArray"), &index, &__$false);
	zephir_update_property_array(this_ptr, SL("myArray"), &index, &__$true);
	ZVAL_LONG(&_3, 'A');
	zephir_update_property_array(this_ptr, SL("myArray"), &index, &_3);
	array_init(&_4);
	ZEPHIR_MM_ADD_ENTRY(&_4);
	zephir_update_property_array(this_ptr, SL("myArray"), &index, &_4);
	RETURN_MM_MEMBER(getThis(), "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray6) {

	zval __$null, __$false, __$true, _0, _1;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	array_init(&_0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_update_property_zval(this_ptr, SL("myArray"), &_0);
	ZVAL_LONG(&_1, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("ll"), 2, 0, 1);
	ZVAL_DOUBLE(&_1, 1.5);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("ll"), 2, 0, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$null, SL("ll"), 2, 0, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$false, SL("ll"), 2, 0, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$true, SL("ll"), 2, 0, 1);
	ZVAL_LONG(&_1, 'A');
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("ll"), 2, 0, 1);
	ZEPHIR_MM_ZVAL_STRING(&_1, "hello");
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("ll"), 2, 0, 1);
	array_init(&_1);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("ll"), 2, 0, 1);
	RETURN_MM_MEMBER(getThis(), "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray7) {

	zval __$null, __$false, __$true, _0, _1;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	array_init(&_0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_update_property_zval(this_ptr, SL("myArray"), &_0);
	ZVAL_LONG(&_1, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("ss"), 4, SL("hello"), SL("hello"));
	ZVAL_DOUBLE(&_1, 1.5);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("ss"), 4, SL("hello"), SL("hello"));
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$null, SL("ss"), 4, SL("hello"), SL("hello"));
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$false, SL("ss"), 4, SL("hello"), SL("hello"));
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$true, SL("ss"), 4, SL("hello"), SL("hello"));
	ZVAL_LONG(&_1, 'A');
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("ss"), 4, SL("hello"), SL("hello"));
	ZEPHIR_MM_ZVAL_STRING(&_1, "hello");
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("ss"), 4, SL("hello"), SL("hello"));
	array_init(&_1);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("ss"), 4, SL("hello"), SL("hello"));
	RETURN_MM_MEMBER(getThis(), "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray8) {

	zval *index, index_sub, __$null, __$false, __$true, _0, _1;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&index_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	zephir_fetch_params(1, 1, 0, &index);



	array_init(&_0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_update_property_zval(this_ptr, SL("myArray"), &_0);
	ZVAL_LONG(&_1, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("zz"), 2, index, index);
	ZVAL_DOUBLE(&_1, 1.5);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("zz"), 2, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$null, SL("zz"), 2, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$false, SL("zz"), 2, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$true, SL("zz"), 2, index, index);
	ZVAL_LONG(&_1, 'A');
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("zz"), 2, index, index);
	ZEPHIR_MM_ZVAL_STRING(&_1, "hello");
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("zz"), 2, index, index);
	array_init(&_1);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("zz"), 2, index, index);
	RETURN_MM_MEMBER(getThis(), "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray9) {

	zval *index_param = NULL, __$null, __$false, __$true, _0, _1;
	zend_long index;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	zephir_fetch_params(1, 1, 0, &index_param);

	index = zephir_get_intval(index_param);


	array_init(&_0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_update_property_zval(this_ptr, SL("myArray"), &_0);
	ZVAL_LONG(&_1, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("ll"), 2, index, index);
	ZVAL_DOUBLE(&_1, 1.5);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("ll"), 2, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$null, SL("ll"), 2, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$false, SL("ll"), 2, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$true, SL("ll"), 2, index, index);
	ZVAL_LONG(&_1, 'A');
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("ll"), 2, index, index);
	ZEPHIR_MM_ZVAL_STRING(&_1, "hello");
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("ll"), 2, index, index);
	array_init(&_1);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("ll"), 2, index, index);
	RETURN_MM_MEMBER(getThis(), "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray10) {

	zval *index_param = NULL, __$null, __$false, __$true, _0, _1;
	zval index;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&index);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(&index, index_param);


	array_init(&_0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_update_property_zval(this_ptr, SL("myArray"), &_0);
	ZVAL_LONG(&_1, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("zz"), 2, &index, &index);
	ZVAL_DOUBLE(&_1, 1.5);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("zz"), 2, &index, &index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$null, SL("zz"), 2, &index, &index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$false, SL("zz"), 2, &index, &index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$true, SL("zz"), 2, &index, &index);
	ZVAL_LONG(&_1, 'A');
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("zz"), 2, &index, &index);
	ZEPHIR_MM_ZVAL_STRING(&_1, "hello");
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("zz"), 2, &index, &index);
	array_init(&_1);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("zz"), 2, &index, &index);
	RETURN_MM_MEMBER(getThis(), "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray11) {

	zval *index, index_sub, __$null, __$false, __$true, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&index_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	zephir_fetch_params(1, 1, 0, &index);



	ZVAL_LONG(&_0, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_0, SL("zza"), 3, index, index);
	ZVAL_DOUBLE(&_1, 1.5);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("zza"), 3, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$null, SL("zza"), 3, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$false, SL("zza"), 3, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$true, SL("zza"), 3, index, index);
	ZVAL_LONG(&_2, 'A');
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_2, SL("zza"), 3, index, index);
	ZEPHIR_MM_ZVAL_STRING(&_3, "hello");
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_3, SL("zza"), 3, index, index);
	array_init(&_4);
	ZEPHIR_MM_ADD_ENTRY(&_4);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_4, SL("zza"), 3, index, index);
	RETURN_MM_MEMBER(getThis(), "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray12) {

	zval *index, index_sub, __$null, __$false, __$true, temp1, temp2, temp3, _0, _1, _2, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&index_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&temp1);
	ZVAL_UNDEF(&temp2);
	ZVAL_UNDEF(&temp3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	zephir_fetch_params(1, 1, 0, &index);



	ZVAL_LONG(&_0, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_0, SL("zza"), 3, index, index);
	ZVAL_DOUBLE(&_1, 1.5);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("zza"), 3, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$null, SL("zza"), 3, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$false, SL("zza"), 3, index, index);
	zephir_read_property(&_2, this_ptr, SL("myArray"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&temp1, &_2, index, PH_NOISY, "test/assign.zep", 657 TSRMLS_CC);
	zephir_read_property(&temp2, this_ptr, SL("myArray"), PH_NOISY_CC);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$true, SL("zza"), 3, index, index);
	ZVAL_LONG(&_3, 'A');
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_3, SL("zza"), 3, index, index);
	ZEPHIR_MM_ZVAL_STRING(&_4, "hello");
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_4, SL("zza"), 3, index, index);
	array_init(&_5);
	ZEPHIR_MM_ADD_ENTRY(&_5);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_5, SL("zza"), 3, index, index);
	zephir_read_property(&_6, this_ptr, SL("myArray"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&temp3, zephir_fast_count_int(&_6 TSRMLS_CC));
	RETURN_MM_MEMBER(getThis(), "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray13) {

	zval *index, index_sub, __$null, __$false, __$true, temp1, temp2, temp3, _0, _1, _2, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&index_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&temp1);
	ZVAL_UNDEF(&temp2);
	ZVAL_UNDEF(&temp3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	zephir_fetch_params(1, 1, 0, &index);



	ZVAL_LONG(&_0, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_0, SL("za"), 2, index);
	ZVAL_DOUBLE(&_1, 1.5);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1, SL("za"), 2, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$null, SL("za"), 2, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$false, SL("za"), 2, index);
	zephir_read_property(&_2, this_ptr, SL("myArray"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&temp1, &_2, index, PH_NOISY, "test/assign.zep", 674 TSRMLS_CC);
	zephir_read_property(&temp2, this_ptr, SL("myArray"), PH_NOISY_CC);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &__$true, SL("za"), 2, index);
	ZVAL_LONG(&_3, 'A');
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_3, SL("za"), 2, index);
	ZEPHIR_MM_ZVAL_STRING(&_4, "hello");
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_4, SL("za"), 2, index);
	array_init(&_5);
	ZEPHIR_MM_ADD_ENTRY(&_5);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_5, SL("za"), 2, index);
	zephir_read_property(&_6, this_ptr, SL("myArray"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&temp3, zephir_fast_count_int(&_6 TSRMLS_CC));
	RETURN_MM_MEMBER(getThis(), "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray14) {

	zval _0, _1, _3;
	zval v, _2, _4, _5, _6;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_ZVAL_STRING(&v, "abc");
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_create_array(&_1, 1, 0);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	add_assoc_stringl_ex(&_1, SL("b_key"), SL("b_val"));
	zephir_array_update_string(&_0, SL("a"), &_1, PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("myArray"), &_0);
	ZEPHIR_MM_ZVAL_STRING(&_2, "d_val");
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_2, SL("sss"), 6, SL("a"), SL("b"), SL("d_key"));
	zephir_create_array(&_1, 1, 0);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	zephir_create_array(&_3, 1, 0);
	ZEPHIR_MM_ADD_ENTRY(&_3);
	add_index_long(&_3, 3, 4);
	zephir_array_update_long(&_1, 2, &_3, PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZVAL_LONG(&_2, 1);
	zephir_update_property_array(this_ptr, SL("myArray"), &_2, &_1);
	ZEPHIR_MM_ZVAL_STRING(&_4, "s");
	ZVAL_LONG(&_5, 1);
	zephir_update_property_array(this_ptr, SL("myArray"), &_4, &_5);
	ZEPHIR_MM_ZVAL_STRING(&_6, "f");
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_6, SL("sssss"), 10, SL("a"), SL("b"), SL("c"), SL("d"), SL("e"));
	ZVAL_LONG(&_6, 6);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_6, SL("lll"), 3, 1, 2, 5);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &v, SL("llz"), 3, 1, 2, &v);
	RETURN_MM_MEMBER(getThis(), "myArray");

}

PHP_METHOD(Test_Assign, testStaticPropertyAssign1) {

	zval _2;
	zval __$null, __$false, __$true, _0, _1, _3;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 1);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(&_0, 1.5);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &_0);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &__$null);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &__$false);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &__$true);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 'A');
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZEPHIR_MM_ZVAL_STRING(&_0, "hello");
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &_0);
	array_init(&_1);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &_1);
	zephir_create_array(&_2, 3, 0);
	ZEPHIR_MM_ADD_ENTRY(&_2);
	ZVAL_LONG(&_3, 1);
	zephir_array_fast_append(&_2, &_3);
	ZVAL_LONG(&_3, 2);
	zephir_array_fast_append(&_2, &_3);
	ZVAL_LONG(&_3, 3);
	zephir_array_fast_append(&_2, &_3);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &_2);
	zephir_read_static_property_ce(&_0, test_assign_ce, SL("testVarStatic"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_CTOR(&_0);

}

PHP_METHOD(Test_Assign, testStaticPropertyAssign2) {

	zval f;
	char e;
	zend_bool d;
	zval c, _0;
	double b;
	zend_long a;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&c);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&f);


	a = 1;
	b = 1.5;
	ZVAL_NULL(&c);
	d = 0;
	e = 'A';
	array_init(&f);
	ZEPHIR_MM_ADD_ENTRY(&f);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, a);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(&_0, b);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &_0);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &c);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_BOOL(&_0, d);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, e);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &_0);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &f);
	zephir_read_static_property_ce(&_0, test_assign_ce, SL("testVarStatic"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_CTOR(&_0);

}

PHP_METHOD(Test_Assign, testStaticPropertyArray1) {

	zval __$null, __$false, __$true, _0, _1, _2;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	array_init(&_0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &_0);
	ZVAL_LONG(&_1, 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("l"), 1, 0);
	ZVAL_DOUBLE(&_1, 1.5);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("l"), 1, 0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$null TSRMLS_CC, SL("l"), 1, 0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$false TSRMLS_CC, SL("l"), 1, 0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$true TSRMLS_CC, SL("l"), 1, 0);
	ZVAL_LONG(&_1, 'A');
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("l"), 1, 0);
	ZEPHIR_MM_ZVAL_STRING(&_1, "hello");
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("l"), 1, 0);
	array_init(&_1);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("l"), 1, 0);
	zephir_read_static_property_ce(&_2, test_assign_ce, SL("testVarStatic"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_CTOR(&_2);

}

PHP_METHOD(Test_Assign, testStaticPropertyArray2) {

	zval __$null, __$false, __$true, _0, _1, _2;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	array_init(&_0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &_0);
	ZVAL_LONG(&_1, 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("s"), 2, SL("hello"));
	ZVAL_DOUBLE(&_1, 1.5);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("s"), 2, SL("hello"));
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$null TSRMLS_CC, SL("s"), 2, SL("hello"));
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$false TSRMLS_CC, SL("s"), 2, SL("hello"));
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$true TSRMLS_CC, SL("s"), 2, SL("hello"));
	ZVAL_LONG(&_1, 'A');
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("s"), 2, SL("hello"));
	ZEPHIR_MM_ZVAL_STRING(&_1, "hello");
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("s"), 2, SL("hello"));
	array_init(&_1);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("s"), 2, SL("hello"));
	zephir_read_static_property_ce(&_2, test_assign_ce, SL("testVarStatic"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_CTOR(&_2);

}

PHP_METHOD(Test_Assign, testStaticPropertyArray3) {

	zval *index, index_sub, __$null, __$false, __$true, _0, _1, _2;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&index_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	zephir_fetch_params(1, 1, 0, &index);



	array_init(&_0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &_0);
	ZVAL_LONG(&_1, 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("z"), 1, index);
	ZVAL_DOUBLE(&_1, 1.5);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("z"), 1, index);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$null TSRMLS_CC, SL("z"), 1, index);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$false TSRMLS_CC, SL("z"), 1, index);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$true TSRMLS_CC, SL("z"), 1, index);
	ZVAL_LONG(&_1, 'A');
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("z"), 1, index);
	ZEPHIR_MM_ZVAL_STRING(&_1, "hello");
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("z"), 1, index);
	array_init(&_1);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("z"), 1, index);
	zephir_read_static_property_ce(&_2, test_assign_ce, SL("testVarStatic"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_CTOR(&_2);

}

PHP_METHOD(Test_Assign, testStaticPropertyArrayAppend) {

	zval __$false, _0, _1, _2;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	array_init(&_0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &_0);
	ZEPHIR_MM_ZVAL_STRING(&_1, "test");
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("a"), 1);
	ZVAL_LONG(&_1, 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("a"), 1);
	ZVAL_DOUBLE(&_1, 1.5);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("a"), 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$false TSRMLS_CC, SL("a"), 1);
	array_init(&_1);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("a"), 1);
	zephir_read_static_property_ce(&_2, test_assign_ce, SL("testVarStatic"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_CTOR(&_2);

}

PHP_METHOD(Test_Assign, testStaticPropertyArrayMutli1) {

	zval __$null, __$false, __$true, _0, _1, _2;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	array_init(&_0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &_0);
	ZVAL_LONG(&_1, 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("ll"), 2, 0, 0);
	ZVAL_DOUBLE(&_1, 1.5);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("ll"), 2, 0, 0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$null TSRMLS_CC, SL("ll"), 2, 0, 0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$false TSRMLS_CC, SL("ll"), 2, 0, 0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$true TSRMLS_CC, SL("ll"), 2, 0, 0);
	ZVAL_LONG(&_1, 'A');
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("ll"), 2, 0, 0);
	ZEPHIR_MM_ZVAL_STRING(&_1, "hello");
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("ll"), 2, 0, 0);
	array_init(&_1);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("ll"), 2, 0, 0);
	zephir_read_static_property_ce(&_2, test_assign_ce, SL("testVarStatic"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_CTOR(&_2);

}

PHP_METHOD(Test_Assign, testStaticPropertyArrayMutli2) {

	zval __$null, __$false, __$true, _0, _1, _2;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	array_init(&_0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &_0);
	ZVAL_LONG(&_1, 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	ZVAL_DOUBLE(&_1, 1.5);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$null TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$false TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$true TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	ZVAL_LONG(&_1, 'A');
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	ZEPHIR_MM_ZVAL_STRING(&_1, "hello");
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	array_init(&_1);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	zephir_read_static_property_ce(&_2, test_assign_ce, SL("testVarStatic"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_CTOR(&_2);

}

PHP_METHOD(Test_Assign, testStaticPropertyArrayMutli3) {

	zval *index, index_sub, __$null, __$false, __$true, _0, _1, _2;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&index_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	zephir_fetch_params(1, 1, 0, &index);



	array_init(&_0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &_0);
	ZVAL_LONG(&_1, 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("zz"), 2, index, index);
	ZVAL_DOUBLE(&_1, 1.5);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("zz"), 2, index, index);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$null TSRMLS_CC, SL("zz"), 2, index, index);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$false TSRMLS_CC, SL("zz"), 2, index, index);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$true TSRMLS_CC, SL("zz"), 2, index, index);
	ZVAL_LONG(&_1, 'A');
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("zz"), 2, index, index);
	ZEPHIR_MM_ZVAL_STRING(&_1, "hello");
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("zz"), 2, index, index);
	array_init(&_1);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("zz"), 2, index, index);
	zephir_read_static_property_ce(&_2, test_assign_ce, SL("testVarStatic"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_CTOR(&_2);

}

PHP_METHOD(Test_Assign, testStaticPropertyArrayMulti4) {

	zval _0, _1, _3;
	zval v, _2, _4;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_ZVAL_STRING(&v, "abc");
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_create_array(&_1, 1, 0);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	add_assoc_stringl_ex(&_1, SL("b_key"), SL("b_val"));
	zephir_array_update_string(&_0, SL("a"), &_1, PH_SEPARATE);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &_0);
	ZEPHIR_MM_ZVAL_STRING(&_2, "d_val");
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_2 TSRMLS_CC, SL("sss"), 6, SL("a"), SL("b"), SL("d_key"));
	zephir_create_array(&_1, 1, 0);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	zephir_create_array(&_3, 1, 0);
	ZEPHIR_MM_ADD_ENTRY(&_3);
	add_index_long(&_3, 3, 4);
	zephir_array_update_long(&_1, 2, &_3, PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("l"), 1, 1);
	ZVAL_LONG(&_2, 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_2 TSRMLS_CC, SL("s"), 2, SL("s"));
	ZEPHIR_MM_ZVAL_STRING(&_2, "f");
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_2 TSRMLS_CC, SL("sssss"), 10, SL("a"), SL("b"), SL("c"), SL("d"), SL("e"));
	ZVAL_LONG(&_2, 6);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_2 TSRMLS_CC, SL("lll"), 3, 1, 2, 5);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &v TSRMLS_CC, SL("llz"), 3, 1, 2, &v);
	zephir_read_static_property_ce(&_4, test_assign_ce, SL("testVarStatic"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_CTOR(&_4);

}

PHP_METHOD(Test_Assign, testStaticPropertyArrayAppend1) {

	zval __$null, __$false, __$true, _0, _1, _2;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	array_init(&_0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_update_static_property(test_assign_ce, ZEND_STRL("testVarStatic"), &_0);
	ZVAL_LONG(&_1, 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("la"), 2, 0);
	ZVAL_DOUBLE(&_1, 1.5);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("la"), 2, 0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$null TSRMLS_CC, SL("la"), 2, 0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$false TSRMLS_CC, SL("la"), 2, 0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &__$true TSRMLS_CC, SL("la"), 2, 0);
	ZVAL_LONG(&_1, 'A');
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("la"), 2, 0);
	ZEPHIR_MM_ZVAL_STRING(&_1, "hello");
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("la"), 2, 0);
	array_init(&_1);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_1 TSRMLS_CC, SL("la"), 2, 0);
	zephir_read_static_property_ce(&_2, test_assign_ce, SL("testVarStatic"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_CTOR(&_2);

}

PHP_METHOD(Test_Assign, testArrayVarAssign1) {

	zval *index, index_sub, *value, value_sub, a;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&a);

	zephir_fetch_params(1, 2, 0, &index, &value);



	array_init(&a);
	ZEPHIR_MM_ADD_ENTRY(&a);
	zephir_array_update_zval(&a, index, value, PH_SEPARATE);
	RETURN_MM_CTOR(&a);

}

PHP_METHOD(Test_Assign, testArrayVarAssign2) {

	zval *index, index_sub, *value, value_sub, _POST;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_POST);

	zephir_fetch_params(1, 2, 0, &index, &value);



	array_init(&_POST);
	ZEPHIR_MM_ADD_ENTRY(&_POST);
	zephir_array_update_zval(&_POST, index, value, PH_SEPARATE);
	RETURN_MM_CTOR(&_POST);

}

PHP_METHOD(Test_Assign, testArrayProperty) {

	zval *index, index_sub, *value, value_sub, _POST;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_POST);

	zephir_fetch_params(1, 2, 0, &index, &value);



	array_init(&_POST);
	ZEPHIR_MM_ADD_ENTRY(&_POST);
	zephir_array_update_zval(&_POST, index, value, PH_SEPARATE);
	RETURN_MM_CTOR(&_POST);

}

/**
 * @link https://github.com/phalcon/zephir/issues/159
 */
PHP_METHOD(Test_Assign, testGlobalVarAssign) {

	zval *index, index_sub, *value, value_sub, _POST;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_POST);

	zephir_get_global(&_POST, SL("_POST"));
	zephir_fetch_params(1, 2, 0, &index, &value);



	zephir_array_update_zval(&_POST, index, value, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

/**
 * @link https://github.com/phalcon/zephir/issues/523
 */
PHP_METHOD(Test_Assign, testConstantKeyAssign) {

	zval elements;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&elements);


	zephir_create_array(&elements, 3, 0);
	ZEPHIR_MM_ADD_ENTRY(&elements);
	add_assoc_long_ex(&elements, SL("abc"), 1);
	add_index_long(&elements, 131072, 131079);
	add_index_long(&elements, 131073, 131080);
	ZEPHIR_MM_RESTORE();

}

/**
 * @link https://github.com/phalcon/zephir/issues/746
 *
 */
PHP_METHOD(Test_Assign, testArrayBoolExpressionAssign) {

	zval str, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);


	ZEPHIR_MM_ZVAL_STRING(&str, "abc");
	array_init(&_0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_update_property_zval(this_ptr, SL("myArray"), &_0);
	ZEPHIR_MM_ZVAL_STRING(&_1, "a");
	ZVAL_BOOL(&_2, ZEPHIR_IS_STRING(&str, "abc"));
	zephir_update_property_array(this_ptr, SL("myArray"), &_1, &_2);
	ZEPHIR_MM_ZVAL_STRING(&_3, "b");
	ZVAL_BOOL(&_4, !ZEPHIR_IS_STRING(&str, "abc"));
	zephir_update_property_array(this_ptr, SL("myArray"), &_3, &_4);
	RETURN_MM_MEMBER(getThis(), "myArray");

}

/**
 * @link https://github.com/phalcon/zephir/issues/725
 */
PHP_METHOD(Test_Assign, testAssignSuperGlobals) {

	zval _GET, v, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	zephir_get_global(&_GET, SL("_GET"));

	ZEPHIR_MM_ZVAL_STRING(&v, "stest2");
	ZEPHIR_MM_ZVAL_STRING(&_0, "stest");
	zephir_array_update_string(&_GET, SL("steststr"), &_0, PH_SEPARATE);
	zephir_array_update_string(&_GET, SL("steststr2"), &v, PH_SEPARATE);
	ZVAL_LONG(&_1, 1);
	zephir_array_update_string(&_GET, SL("stestint"), &_1, PH_SEPARATE);
	ZVAL_LONG(&_2, 2);
	zephir_array_update_string(&_GET, SL("stestint2"), &_2, PH_SEPARATE);
	ZEPHIR_MM_ZVAL_STRING(&_3, "testval");
	zephir_array_update_zval(&_GET, &v, &_3, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

