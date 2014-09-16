
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
#include "kernel/operators.h"
#include "kernel/array.h"


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


	RETURN_MEMBER(this_ptr, "testVar");

}

PHP_METHOD(Test_Assign, getMyArray) {


	RETURN_MEMBER(this_ptr, "myArray");

}

PHP_METHOD(Test_Assign, testAssign1) {

	int a;


	a = 1;
	RETURN_LONG(a);

}

PHP_METHOD(Test_Assign, testAssign2) {

	int a;


	a = 1;
	RETURN_LONG(a);

}

PHP_METHOD(Test_Assign, testAssign3) {

	int a;


	a = 0;
	RETURN_LONG(a);

}

PHP_METHOD(Test_Assign, testAssign4) {

	int a;


	a = 0;
	RETURN_LONG(a);

}

PHP_METHOD(Test_Assign, testAssign5) {

	int a;


	a = (long) (2.0);
	RETURN_LONG(a);

}

PHP_METHOD(Test_Assign, testAssign6) {

	zend_bool a;


	a = (1) ? 1 : 0;
	RETURN_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign7) {

	zend_bool a;


	a = (1.0) ? 1 : 0;
	RETURN_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign8) {

	zend_bool a;


	a = 1;
	RETURN_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign9) {

	zend_bool a;


	a = 0;
	RETURN_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign10) {

	zend_bool a;


	a = 0;
	RETURN_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign11) {

	double a;


	a = 0.0;
	RETURN_DOUBLE(a);

}

PHP_METHOD(Test_Assign, testAssign12) {

	double a;


	a = (double) (4);
	RETURN_DOUBLE(a);

}

PHP_METHOD(Test_Assign, testAssign13) {

	double a;


	a = 0;
	RETURN_DOUBLE(a);

}

PHP_METHOD(Test_Assign, testAssign14) {

	double a;


	a = 1;
	RETURN_DOUBLE(a);

}

PHP_METHOD(Test_Assign, testAssign15) {

	double a;


	a = 5.0;
	RETURN_DOUBLE(a);

}

PHP_METHOD(Test_Assign, testAssign16) {

	int a;


	a = 1;
	RETURN_LONG(a);

}

PHP_METHOD(Test_Assign, testAssign17) {

	double a;


	a = 1.0;
	RETURN_DOUBLE(a);

}

PHP_METHOD(Test_Assign, testAssign18) {

	zend_bool a;


	a = 0;
	RETURN_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign19) {

	zend_bool a;


	a = 1;
	RETURN_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign20) {

	zval a;


	ZEPHIR_SINIT_VAR(a);
	ZVAL_NULL(&a);
	RETURN_LCTORW(a);

}

PHP_METHOD(Test_Assign, testAssign21) {

	int a, b;


	a = 1;
	b = a;
	RETURN_LONG(b);

}

PHP_METHOD(Test_Assign, testAssign22) {

	double a, b;


	a = 1.0;
	b = a;
	RETURN_DOUBLE(b);

}

PHP_METHOD(Test_Assign, testAssign23) {

	zend_bool a, b;


	a = 1;
	b = a;
	RETURN_BOOL(b);

}

PHP_METHOD(Test_Assign, testAssign24) {

	double b;
	int a;


	a = 1;
	b = (double) a;
	RETURN_DOUBLE(b);

}

PHP_METHOD(Test_Assign, testAssign25) {

	double b;
	int a;


	a = 1;
	b = (double) a;
	RETURN_DOUBLE(b);

}

PHP_METHOD(Test_Assign, testAssign26) {

	double a;
	int b;


	a = (double) (1);
	b = (long) a;
	RETURN_LONG(b);

}

PHP_METHOD(Test_Assign, testAssign27) {

	double a;
	int b;


	b = 1;
	a = (double) b;
	RETURN_DOUBLE(a);

}

PHP_METHOD(Test_Assign, testAssign28) {

	zend_bool a;
	int b;


	b = 1;
	a = (b) ? 1 : 0;
	RETURN_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign29) {

	zend_bool a;
	double b;


	b = 1.0;
	a = (b) ? 1 : 0;
	RETURN_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign30) {

	int a;
	zend_bool b;


	b = 0;
	a = b;
	RETURN_LONG(a);

}

PHP_METHOD(Test_Assign, testAssign31) {

	double a;
	zend_bool b;


	b = 0;
	a = (double) b;
	RETURN_DOUBLE(a);

}

PHP_METHOD(Test_Assign, testAssign32) {

	zend_bool b, a;


	b = 0;
	a = b;
	RETURN_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign33) {

	zend_bool b, a;


	b = 0;
	a = b;
	RETURN_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign34) {

	zend_bool a;
	int b;


	b = 0;
	a = (b) ? 1 : 0;
	RETURN_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign35) {

	zend_bool a;
	double b;


	b = 0;
	a = (b) ? 1 : 0;
	RETURN_BOOL(a);

}

PHP_METHOD(Test_Assign, testAssign36) {

	zend_bool b, a;


	b = 0;
	a = b;
	RETURN_BOOL(a);

}

PHP_METHOD(Test_Assign, testPropertyAssign1) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(_0, 1.5);
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("testVar"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("testVar"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("testVar"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 'A');
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "hello", 1);
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("testVar"), _1 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "testVar");

}

PHP_METHOD(Test_Assign, testPropertyAssign2) {

	zval *f;
	char e = 'A';
	zend_bool d = 0;
	zval *c = NULL, *_0;
	double b = 1.5;
	int a = 1;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(c);
	ZVAL_NULL(c);
	ZEPHIR_INIT_VAR(f);
	array_init(f);

	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, a);
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(_0, b);
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("testVar"), c TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("testVar"), d ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, e);
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("testVar"), f TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "testVar");

}

PHP_METHOD(Test_Assign, testPropertyIncr1) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("testVar") TSRMLS_CC));
	RETURN_MEMBER(this_ptr, "testVar");

}

PHP_METHOD(Test_Assign, testPropertyAddAssign1) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 2);
	ZEPHIR_ADD_ASSIGN(_0, _1)
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "testVar");

}

PHP_METHOD(Test_Assign, testPropertyAddAssign2) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 2);
	ZEPHIR_ADD_ASSIGN(_0, _1)
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "testVar");

}

PHP_METHOD(Test_Assign, testPropertyAssignValuePlus1) {

	zval *_0, *_1;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("testVar"), PH_NOISY_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, (zephir_get_numberval(_0) + 1));
	zephir_update_property_this(this_ptr, SL("testVar"), _1 TSRMLS_CC);
	RETURN_MEMBER(this_ptr, "testVar");

}

PHP_METHOD(Test_Assign, testPropertyDecr) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 2);
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("testVar") TSRMLS_CC));
	RETURN_MEMBER(this_ptr, "testVar");

}

PHP_METHOD(Test_Assign, testPropertySubAssign1) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 2);
	ZEPHIR_SUB_ASSIGN(_0, _1)
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "testVar");

}

PHP_METHOD(Test_Assign, testPropertySubAssign2) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 2);
	ZEPHIR_SUB_ASSIGN(_0, _1)
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "testVar");

}

PHP_METHOD(Test_Assign, testPropertyMulAssign1) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 2);
	ZEPHIR_MUL_ASSIGN(_0, _1)
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "testVar");

}

PHP_METHOD(Test_Assign, testPropertyMulAssign2) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 3);
	ZEPHIR_MUL_ASSIGN(_0, _1)
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "testVar");

}

PHP_METHOD(Test_Assign, testPropertyAssignStringConcat) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "test", 1);
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	zephir_concat_self_str(&_0, " string", sizeof(" string")-1 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("testVar"), _0 TSRMLS_CC);
	RETURN_MEMBER(this_ptr, "testVar");

}

PHP_METHOD(Test_Assign, testPropertyArray1) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("myArray"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, 1);
	zephir_update_property_array_append(this_ptr, SL("myArray"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, 1.5);
	zephir_update_property_array_append(this_ptr, SL("myArray"), _1 TSRMLS_CC);
	zephir_update_property_array_append(this_ptr, SL("myArray"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_array_append(this_ptr, SL("myArray"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	zephir_update_property_array_append(this_ptr, SL("myArray"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, 'A');
	zephir_update_property_array_append(this_ptr, SL("myArray"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_STRING(_1, "hello", 1);
	zephir_update_property_array_append(this_ptr, SL("myArray"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_array_append(this_ptr, SL("myArray"), _2 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray2) {

	zval *f;
	char e = 'A';
	zend_bool d = 0;
	zval *c = NULL, *_0, *_1;
	double b = 1.5;
	int a = 1;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(c);
	ZVAL_NULL(c);
	ZEPHIR_INIT_VAR(f);
	array_init(f);

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("myArray"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, a);
	zephir_update_property_array_append(this_ptr, SL("myArray"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, b);
	zephir_update_property_array_append(this_ptr, SL("myArray"), _1 TSRMLS_CC);
	zephir_update_property_array_append(this_ptr, SL("myArray"), c TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_BOOL(_1, d);
	zephir_update_property_array_append(this_ptr, SL("myArray"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, e);
	zephir_update_property_array_append(this_ptr, SL("myArray"), _1 TSRMLS_CC);
	zephir_update_property_array_append(this_ptr, SL("myArray"), f TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray3) {

	zval *_0, *_1, *_2, *_3, *_4, *_5, *_6, *_7, *_8, *_9, *_10, *_11;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("myArray"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 1);
	zephir_update_property_array(this_ptr, SL("myArray"), _1, _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_DOUBLE(_4, 1.5);
	zephir_update_property_array(this_ptr, SL("myArray"), _3, _4 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, 0);
	zephir_update_property_array(this_ptr, SL("myArray"), _5, ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, 0);
	zephir_update_property_array(this_ptr, SL("myArray"), _6, ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, 0);
	zephir_update_property_array(this_ptr, SL("myArray"), _7, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_LONG(_8, 0);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_LONG(_9, 'A');
	zephir_update_property_array(this_ptr, SL("myArray"), _8, _9 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_10);
	array_init(_10);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_LONG(_11, 0);
	zephir_update_property_array(this_ptr, SL("myArray"), _11, _10 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray4) {

	zval *index, *_0, *_1, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);



	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("myArray"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	zephir_update_property_array(this_ptr, SL("myArray"), index, _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_DOUBLE(_2, 1.5);
	zephir_update_property_array(this_ptr, SL("myArray"), index, _2 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("myArray"), index, ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("myArray"), index, ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("myArray"), index, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 'A');
	zephir_update_property_array(this_ptr, SL("myArray"), index, _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	array_init(_4);
	zephir_update_property_array(this_ptr, SL("myArray"), index, _4 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray5) {

	zval *index_param = NULL, *_0, *_1, *_2, *_3, *_4;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(index, index_param);


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("myArray"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	zephir_update_property_array(this_ptr, SL("myArray"), index, _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_DOUBLE(_2, 1.5);
	zephir_update_property_array(this_ptr, SL("myArray"), index, _2 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("myArray"), index, ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("myArray"), index, ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("myArray"), index, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 'A');
	zephir_update_property_array(this_ptr, SL("myArray"), index, _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	array_init(_4);
	zephir_update_property_array(this_ptr, SL("myArray"), index, _4 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray6) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("myArray"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("ll"), 2, 0, 1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_DOUBLE(_1, 1.5);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("ll"), 2, 0, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC, SL("ll"), 2, 0, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_false) TSRMLS_CC, SL("ll"), 2, 0, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_true) TSRMLS_CC, SL("ll"), 2, 0, 1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 'A');
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("ll"), 2, 0, 1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "hello", 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("ll"), 2, 0, 1);
	ZEPHIR_INIT_BNVAR(_1);
	array_init(_1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("ll"), 2, 0, 1);
	RETURN_MM_MEMBER(this_ptr, "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray7) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("myArray"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_DOUBLE(_1, 1.5);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_false) TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_true) TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 'A');
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "hello", 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	ZEPHIR_INIT_BNVAR(_1);
	array_init(_1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	RETURN_MM_MEMBER(this_ptr, "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray8) {

	zval *index, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);



	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("myArray"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("zz"), 2, index, index);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_DOUBLE(_1, 1.5);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("zz"), 2, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC, SL("zz"), 2, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_false) TSRMLS_CC, SL("zz"), 2, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_true) TSRMLS_CC, SL("zz"), 2, index, index);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 'A');
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("zz"), 2, index, index);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "hello", 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("zz"), 2, index, index);
	ZEPHIR_INIT_BNVAR(_1);
	array_init(_1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("zz"), 2, index, index);
	RETURN_MM_MEMBER(this_ptr, "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray9) {

	zval *index_param = NULL, *_0, *_1;
	int index;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	index = zephir_get_intval(index_param);


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("myArray"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("ll"), 2, index, index);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_DOUBLE(_1, 1.5);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("ll"), 2, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC, SL("ll"), 2, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_false) TSRMLS_CC, SL("ll"), 2, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_true) TSRMLS_CC, SL("ll"), 2, index, index);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 'A');
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("ll"), 2, index, index);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "hello", 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("ll"), 2, index, index);
	ZEPHIR_INIT_BNVAR(_1);
	array_init(_1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("ll"), 2, index, index);
	RETURN_MM_MEMBER(this_ptr, "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray10) {

	zval *index_param = NULL, *_0, *_1;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(index, index_param);


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("myArray"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("zz"), 2, index, index);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_DOUBLE(_1, 1.5);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("zz"), 2, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC, SL("zz"), 2, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_false) TSRMLS_CC, SL("zz"), 2, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_true) TSRMLS_CC, SL("zz"), 2, index, index);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 'A');
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("zz"), 2, index, index);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "hello", 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("zz"), 2, index, index);
	ZEPHIR_INIT_BNVAR(_1);
	array_init(_1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("zz"), 2, index, index);
	RETURN_MM_MEMBER(this_ptr, "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray11) {

	zval *index, *_0, *_1, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_0 TSRMLS_CC, SL("zza"), 2, index, index);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_DOUBLE(_1, 1.5);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("zza"), 2, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC, SL("zza"), 2, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_false) TSRMLS_CC, SL("zza"), 2, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_true) TSRMLS_CC, SL("zza"), 2, index, index);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 'A');
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_2 TSRMLS_CC, SL("zza"), 2, index, index);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "hello", 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_3 TSRMLS_CC, SL("zza"), 2, index, index);
	ZEPHIR_INIT_VAR(_4);
	array_init(_4);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_4 TSRMLS_CC, SL("zza"), 2, index, index);
	RETURN_MM_MEMBER(this_ptr, "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray12) {

	zval *index, *temp1, *temp2, *temp3, *_0, *_1, *_2, *_3, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_0 TSRMLS_CC, SL("zza"), 2, index, index);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_DOUBLE(_1, 1.5);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("zza"), 2, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC, SL("zza"), 2, index, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_false) TSRMLS_CC, SL("zza"), 2, index, index);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("myArray"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(temp1);
	zephir_array_fetch(&temp1, _2, index, PH_NOISY, "test/assign.zep", 557 TSRMLS_CC);
	ZEPHIR_OBS_VAR(temp2);
	zephir_read_property_this(&temp2, this_ptr, SL("myArray"), PH_NOISY_CC);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_true) TSRMLS_CC, SL("zza"), 2, index, index);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 'A');
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_3 TSRMLS_CC, SL("zza"), 2, index, index);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "hello", 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_4 TSRMLS_CC, SL("zza"), 2, index, index);
	ZEPHIR_INIT_VAR(_5);
	array_init(_5);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_5 TSRMLS_CC, SL("zza"), 2, index, index);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("myArray"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(temp3);
	ZVAL_LONG(temp3, zephir_fast_count_int(_6 TSRMLS_CC));
	RETURN_MM_MEMBER(this_ptr, "myArray");

}

PHP_METHOD(Test_Assign, testPropertyArray13) {

	zval *index, *temp1, *temp2, *temp3, *_0, *_1, *_2, *_3, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_0 TSRMLS_CC, SL("za"), 1, index);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_DOUBLE(_1, 1.5);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_1 TSRMLS_CC, SL("za"), 1, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC, SL("za"), 1, index);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_false) TSRMLS_CC, SL("za"), 1, index);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("myArray"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(temp1);
	zephir_array_fetch(&temp1, _2, index, PH_NOISY, "test/assign.zep", 574 TSRMLS_CC);
	ZEPHIR_OBS_VAR(temp2);
	zephir_read_property_this(&temp2, this_ptr, SL("myArray"), PH_NOISY_CC);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &ZEPHIR_GLOBAL(global_true) TSRMLS_CC, SL("za"), 1, index);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 'A');
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_3 TSRMLS_CC, SL("za"), 1, index);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "hello", 1);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_4 TSRMLS_CC, SL("za"), 1, index);
	ZEPHIR_INIT_VAR(_5);
	array_init(_5);
	zephir_update_property_array_multi(this_ptr, SL("myArray"), &_5 TSRMLS_CC, SL("za"), 1, index);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("myArray"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(temp3);
	ZVAL_LONG(temp3, zephir_fast_count_int(_6 TSRMLS_CC));
	RETURN_MM_MEMBER(this_ptr, "myArray");

}

PHP_METHOD(Test_Assign, testStaticPropertyAssign1) {

	zval *_2;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(_0, 1.5);
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), _0 TSRMLS_CC);
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 'A');
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "hello", 1);
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 5);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 2);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 3);
	zephir_array_fast_append(_2, _1);
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), _2 TSRMLS_CC);
	_0 = zephir_fetch_static_property_ce(test_assign_ce, SL("testVarStatic") TSRMLS_CC);
	RETURN_CTOR(_0);

}

PHP_METHOD(Test_Assign, testStaticPropertyAssign2) {

	zval *f;
	char e = 'A';
	zend_bool d = 0;
	zval *c = NULL, *_0;
	double b = 1.5;
	int a = 1;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(c);
	ZVAL_NULL(c);
	ZEPHIR_INIT_VAR(f);
	array_init(f);

	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, a);
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(_0, b);
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), _0 TSRMLS_CC);
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), c TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_BOOL(_0, d);
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, e);
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), _0 TSRMLS_CC);
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), f TSRMLS_CC);
	_0 = zephir_fetch_static_property_ce(test_assign_ce, SL("testVarStatic") TSRMLS_CC);
	RETURN_CTOR(_0);

}

PHP_METHOD(Test_Assign, testStaticPropertyArray1) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), _0 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("l"), 1, 0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_DOUBLE(_0, 1.5);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("l"), 1, 0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC, SL("l"), 1, 0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &ZEPHIR_GLOBAL(global_false) TSRMLS_CC, SL("l"), 1, 0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &ZEPHIR_GLOBAL(global_true) TSRMLS_CC, SL("l"), 1, 0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_LONG(_0, 'A');
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("l"), 1, 0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "hello", 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("l"), 1, 0);
	ZEPHIR_INIT_BNVAR(_0);
	array_init(_0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("l"), 1, 0);
	_1 = zephir_fetch_static_property_ce(test_assign_ce, SL("testVarStatic") TSRMLS_CC);
	RETURN_CTOR(_1);

}

PHP_METHOD(Test_Assign, testStaticPropertyArray2) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), _0 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("s"), 2, SL("hello"));
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_DOUBLE(_0, 1.5);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("s"), 2, SL("hello"));
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC, SL("s"), 2, SL("hello"));
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &ZEPHIR_GLOBAL(global_false) TSRMLS_CC, SL("s"), 2, SL("hello"));
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &ZEPHIR_GLOBAL(global_true) TSRMLS_CC, SL("s"), 2, SL("hello"));
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_LONG(_0, 'A');
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("s"), 2, SL("hello"));
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "hello", 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("s"), 2, SL("hello"));
	ZEPHIR_INIT_BNVAR(_0);
	array_init(_0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("s"), 2, SL("hello"));
	_1 = zephir_fetch_static_property_ce(test_assign_ce, SL("testVarStatic") TSRMLS_CC);
	RETURN_CTOR(_1);

}

PHP_METHOD(Test_Assign, testStaticPropertyArray3) {

	zval *index, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);



	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), _0 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("z"), 1, index);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_DOUBLE(_0, 1.5);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("z"), 1, index);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC, SL("z"), 1, index);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &ZEPHIR_GLOBAL(global_false) TSRMLS_CC, SL("z"), 1, index);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &ZEPHIR_GLOBAL(global_true) TSRMLS_CC, SL("z"), 1, index);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_LONG(_0, 'A');
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("z"), 1, index);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "hello", 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("z"), 1, index);
	ZEPHIR_INIT_BNVAR(_0);
	array_init(_0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("z"), 1, index);
	_1 = zephir_fetch_static_property_ce(test_assign_ce, SL("testVarStatic") TSRMLS_CC);
	RETURN_CTOR(_1);

}

PHP_METHOD(Test_Assign, testStaticPropertyArrayMutli1) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), _0 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("ll"), 2, 0, 0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_DOUBLE(_0, 1.5);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("ll"), 2, 0, 0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC, SL("ll"), 2, 0, 0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &ZEPHIR_GLOBAL(global_false) TSRMLS_CC, SL("ll"), 2, 0, 0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &ZEPHIR_GLOBAL(global_true) TSRMLS_CC, SL("ll"), 2, 0, 0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_LONG(_0, 'A');
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("ll"), 2, 0, 0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "hello", 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("ll"), 2, 0, 0);
	ZEPHIR_INIT_BNVAR(_0);
	array_init(_0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("ll"), 2, 0, 0);
	_1 = zephir_fetch_static_property_ce(test_assign_ce, SL("testVarStatic") TSRMLS_CC);
	RETURN_CTOR(_1);

}

PHP_METHOD(Test_Assign, testStaticPropertyArrayMutli2) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), _0 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_DOUBLE(_0, 1.5);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &ZEPHIR_GLOBAL(global_false) TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &ZEPHIR_GLOBAL(global_true) TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_LONG(_0, 'A');
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "hello", 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	ZEPHIR_INIT_BNVAR(_0);
	array_init(_0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("ss"), 4, SL("hello"), SL("hello"));
	_1 = zephir_fetch_static_property_ce(test_assign_ce, SL("testVarStatic") TSRMLS_CC);
	RETURN_CTOR(_1);

}

PHP_METHOD(Test_Assign, testStaticPropertyArrayMutli3) {

	zval *index, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);



	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), _0 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("zz"), 2, index, index);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_DOUBLE(_0, 1.5);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("zz"), 2, index, index);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC, SL("zz"), 2, index, index);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &ZEPHIR_GLOBAL(global_false) TSRMLS_CC, SL("zz"), 2, index, index);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &ZEPHIR_GLOBAL(global_true) TSRMLS_CC, SL("zz"), 2, index, index);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_LONG(_0, 'A');
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("zz"), 2, index, index);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "hello", 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("zz"), 2, index, index);
	ZEPHIR_INIT_BNVAR(_0);
	array_init(_0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("zz"), 2, index, index);
	_1 = zephir_fetch_static_property_ce(test_assign_ce, SL("testVarStatic") TSRMLS_CC);
	RETURN_CTOR(_1);

}

PHP_METHOD(Test_Assign, testStaticPropertyArrayAppend1) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_static_property_ce(test_assign_ce, SL("testVarStatic"), _0 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("la"), 2, 0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_DOUBLE(_0, 1.5);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("la"), 2, 0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC, SL("la"), 2, 0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &ZEPHIR_GLOBAL(global_false) TSRMLS_CC, SL("la"), 2, 0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &ZEPHIR_GLOBAL(global_true) TSRMLS_CC, SL("la"), 2, 0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_LONG(_0, 'A');
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("la"), 2, 0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "hello", 1);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("la"), 2, 0);
	ZEPHIR_INIT_BNVAR(_0);
	array_init(_0);
	zephir_update_static_property_array_multi_ce(test_assign_ce, SL("testVarStatic"), &_0 TSRMLS_CC, SL("la"), 2, 0);
	_1 = zephir_fetch_static_property_ce(test_assign_ce, SL("testVarStatic") TSRMLS_CC);
	RETURN_CTOR(_1);

}

PHP_METHOD(Test_Assign, testArrayVarAssign1) {

	zval *index, *value, *a;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index, &value);



	ZEPHIR_INIT_VAR(a);
	array_init(a);
	zephir_array_update_zval(&a, index, &value, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(a);

}

PHP_METHOD(Test_Assign, testArrayVarAssign2) {

	int _0;
	zval *index, *value, *_POST;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index, &value);



	ZEPHIR_INIT_VAR(_POST);
	array_init(_POST);
	_0 = zephir_maybe_separate_zval(&_POST);
	zephir_array_update_zval(&_POST, index, &value, PH_COPY | PH_SEPARATE);
	if (_0) {
		ZEND_SET_SYMBOL(&EG(symbol_table), "_POST", _POST);
	}
	RETURN_CCTOR(_POST);

}

PHP_METHOD(Test_Assign, testArrayProperty) {

	int _0;
	zval *index, *value, *_POST;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index, &value);



	ZEPHIR_INIT_VAR(_POST);
	array_init(_POST);
	_0 = zephir_maybe_separate_zval(&_POST);
	zephir_array_update_zval(&_POST, index, &value, PH_COPY | PH_SEPARATE);
	if (_0) {
		ZEND_SET_SYMBOL(&EG(symbol_table), "_POST", _POST);
	}
	RETURN_CCTOR(_POST);

}

/**
 * @link https://github.com/phalcon/zephir/issues/159
 */
PHP_METHOD(Test_Assign, testGlobalVarAssign) {

	int _0;
	zval *index, *value, *_POST;

	zephir_fetch_params(0, 2, 0, &index, &value);



	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	_0 = zephir_maybe_separate_zval(&_POST);
	zephir_array_update_zval(&_POST, index, &value, PH_COPY | PH_SEPARATE);
	if (_0) {
		ZEND_SET_SYMBOL(&EG(symbol_table), "_POST", _POST);
	}

}

/**
 * @link https://github.com/phalcon/zephir/issues/523
 */
PHP_METHOD(Test_Assign, testConstantKeyAssign) {

	zval *elements;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(elements);
	array_init_size(elements, 5);
	add_assoc_long_ex(elements, SS("abc"), 1);
	add_index_long(elements, 14, 7);
	add_index_long(elements, 15, 8);
	ZEPHIR_MM_RESTORE();

}

