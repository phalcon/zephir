
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * Arithmetic operations
 */
ZEPHIR_INIT_CLASS(Test_Arithmetic) {

	ZEPHIR_REGISTER_CLASS(Test, Arithmetic, arithmetic, test_arithmetic_method_entry, 0);


	return SUCCESS;

}

PHP_METHOD(Test_Arithmetic, intSum) {

	long a, b, c;

	a = 1;

	b = 2;

	c = a + b;

	RETURN_LONG(c);


}

PHP_METHOD(Test_Arithmetic, int2Sum) {

	long a, c;

	a = 1;

	c = a + 2;

	RETURN_LONG(c);


}

PHP_METHOD(Test_Arithmetic, intSumSimple) {

	long c;

	c = 1 + 2;

	RETURN_LONG(c);


}

PHP_METHOD(Test_Arithmetic, boolSum) {

	zend_bool a, b, c;

	a = (1) ? 1 : 0;

	b = (2) ? 1 : 0;

	c = a |b;

	RETURN_BOOL(c);


}

PHP_METHOD(Test_Arithmetic, bool2Sum) {

	zend_bool a, c;

	a = (1) ? 1 : 0;

	c = a + 2;

	RETURN_BOOL(c);


}

PHP_METHOD(Test_Arithmetic, bool3Sum) {

	zend_bool a, c;

	a = 1;

	c = a |0;

	RETURN_BOOL(c);


}

PHP_METHOD(Test_Arithmetic, boolSumSimple) {

	zend_bool c;

	c = (1 + 2) ? 1 : 0;

	RETURN_BOOL(c);


}

PHP_METHOD(Test_Arithmetic, doubleSum) {

	double a, b, c;

	a = (double) (1);

	b = (double) (2);

	c = a +  b;

	RETURN_DOUBLE(c);


}

PHP_METHOD(Test_Arithmetic, double2Sum) {

	double a, b, c;

	a = 1.0;

	b = 2.0;

	c = a +  b;

	RETURN_DOUBLE(c);


}

PHP_METHOD(Test_Arithmetic, doubleSumSimple) {

	double c;

	c = (double) (1 + 2);

	RETURN_DOUBLE(c);


}

PHP_METHOD(Test_Arithmetic, doubleSum2Simple) {

	double c;

	c = 1.0 + 2.0;

	RETURN_DOUBLE(c);


}

PHP_METHOD(Test_Arithmetic, varSum) {

	zval a, b, c;

	ZEPHIR_SINIT_VAR(a);
	ZVAL_LONG(&a, 1);

	ZEPHIR_SINIT_VAR(b);
	ZVAL_LONG(&b, 2);

	ZEPHIR_SINIT_VAR(c);
	zephir_add_function(&c, &a, &b);

	RETURN_CCTORW(&c);


}

PHP_METHOD(Test_Arithmetic, varSumSimple) {

	zval c;

	ZEPHIR_SINIT_VAR(c);
	ZVAL_LONG(&c, 1 + 2);

	RETURN_CCTORW(&c);


}

PHP_METHOD(Test_Arithmetic, intDoubleSum) {

	double a;
	long b, c;

	a = (double) (1);

	b = 2;

	c = (long) (a +  (double) b);

	RETURN_LONG(c);


}

PHP_METHOD(Test_Arithmetic, intDoubleSumSimple) {

	long c;

	c = (long) ((double) 1 + 2.0);

	RETURN_LONG(c);


}

PHP_METHOD(Test_Arithmetic, doubleIntSum) {

	double a, c;
	long b;

	a = (double) (1);

	b = 2;

	c = a +  (double) b;

	RETURN_DOUBLE(c);


}

PHP_METHOD(Test_Arithmetic, doubleIntSumSimple) {

	double c;

	c = (double) 1 + 2.0;

	RETURN_DOUBLE(c);


}

PHP_METHOD(Test_Arithmetic, varIntSum) {

	long a;
	zval b, c;

	a = 1;

	ZEPHIR_SINIT_VAR(b);
	ZVAL_LONG(&b, 2);

	ZEPHIR_SINIT_VAR(c);
	ZVAL_LONG(&c, a + zephir_get_intval(&b));

	RETURN_CCTORW(&c);


}

PHP_METHOD(Test_Arithmetic, intVarSum) {

	long c, a;
	zval b;

	a = 1;

	ZEPHIR_SINIT_VAR(b);
	ZVAL_LONG(&b, 2);

	c = zephir_get_intval(&b) + a;

	RETURN_LONG(c);


}

PHP_METHOD(Test_Arithmetic, intVarImplicitCastSum) {

	long c;
	zval *a, *b, *_0;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(a);
	ZVAL_STRING(a, "1", 1);

	ZEPHIR_INIT_VAR(b);
	ZVAL_STRING(b, "2", 1);

	ZEPHIR_INIT_VAR(_0);
	zephir_add_function(_0, b, a);

	c = zephir_get_doubleval(_0);

	RETURN_MM_LONG(c);


}

PHP_METHOD(Test_Arithmetic, intVarImplicitCast2Sum) {

	long c;
	zval *a, b, *_0;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(a);
	ZVAL_STRING(a, "1", 1);

	ZEPHIR_SINIT_VAR(b);
	ZVAL_LONG(&b, 2);

	ZEPHIR_INIT_VAR(_0);
	zephir_add_function(_0, &b, a);

	c = zephir_get_doubleval(_0);

	RETURN_MM_LONG(c);


}

PHP_METHOD(Test_Arithmetic, complexSum) {

	zval c;

	ZEPHIR_SINIT_VAR(c);
	ZVAL_DOUBLE(&c, (double) 2 + 1.0);

	RETURN_CCTORW(&c);


}

PHP_METHOD(Test_Arithmetic, complex2Sum) {

	zval c;

	ZEPHIR_SINIT_VAR(c);
	ZVAL_BOOL(&c, 1 |1);

	RETURN_CCTORW(&c);


}

PHP_METHOD(Test_Arithmetic, complex3Sum) {

	zval c;

	ZEPHIR_SINIT_VAR(c);
	ZVAL_BOOL(&c, 1 |((1.0) ? 1 : 0));

	RETURN_CCTORW(&c);


}

PHP_METHOD(Test_Arithmetic, complex4Sum) {

	zval c;

	ZEPHIR_SINIT_VAR(c);
	ZVAL_DOUBLE(&c, 1.0 + 1);

	RETURN_CCTORW(&c);


}

PHP_METHOD(Test_Arithmetic, complex5Sum) {

	zval c;

	ZEPHIR_SINIT_VAR(c);
	ZVAL_LONG(&c, 1 + 1);

	RETURN_CCTORW(&c);


}

PHP_METHOD(Test_Arithmetic, complex6Sum) {

	zval c;

	ZEPHIR_SINIT_VAR(c);
	ZVAL_BOOL(&c, 1 |((1) ? 1 : 0));

	RETURN_CCTORW(&c);


}

PHP_METHOD(Test_Arithmetic, complex7Sum) {

	zval c;
	long b;
	zend_bool a;

	a = (1) ? 1 : 0;

	b = 2;

	ZEPHIR_SINIT_VAR(c);
	ZVAL_LONG(&c, a + b);

	RETURN_CCTORW(&c);


}

PHP_METHOD(Test_Arithmetic, complex9Sum) {

	zval c;
	long b;
	zend_bool a;

	a = (1) ? 1 : 0;

	b = 2;

	ZEPHIR_SINIT_VAR(c);
	ZVAL_LONG(&c, b + a);

	RETURN_CCTORW(&c);


}

PHP_METHOD(Test_Arithmetic, complex10Sum) {

	zval c;
	long b;
	zend_bool a;

	a = (1.0) ? 1 : 0;

	b = 2;

	ZEPHIR_SINIT_VAR(c);
	ZVAL_LONG(&c, b + a);

	RETURN_CCTORW(&c);


}

PHP_METHOD(Test_Arithmetic, complex11Sum) {

	zval c;
	long b;
	zend_bool a;

	a = (1) ? 1 : 0;

	b = (long) (2.0);

	ZEPHIR_SINIT_VAR(c);
	ZVAL_LONG(&c, b + a);

	RETURN_CCTORW(&c);


}

PHP_METHOD(Test_Arithmetic, complex12Sum) {

	long b, c;
	zend_bool a;

	a = (1) ? 1 : 0;

	b = (long) (2.0);

	c = b + a;

	RETURN_LONG(c);


}

PHP_METHOD(Test_Arithmetic, complex13Sum) {

	long c;
	zend_bool a, b;

	a = (1) ? 1 : 0;

	b = (2.0) ? 1 : 0;

	c = b |a;

	RETURN_LONG(c);


}

PHP_METHOD(Test_Arithmetic, complex14Sum) {

	long c;
	zend_bool b;
	zval a;

	ZEPHIR_SINIT_VAR(a);
	ZVAL_LONG(&a, 1);

	b = (2.0) ? 1 : 0;

	c = b + zephir_get_intval(&a);

	RETURN_LONG(c);


}

PHP_METHOD(Test_Arithmetic, complex15Sum) {

	zend_bool c;
	zval a, b, *_0;

	ZEPHIR_MM_GROW();
	ZEPHIR_SINIT_VAR(a);
	ZVAL_LONG(&a, 1);

	ZEPHIR_SINIT_VAR(b);
	ZVAL_DOUBLE(&b, 2.0);

	ZEPHIR_INIT_VAR(_0);
	zephir_add_function(_0, &b, &a);

	c = zephir_get_boolval(_0);

	RETURN_MM_BOOL(c);


}

PHP_METHOD(Test_Arithmetic, complex16Sum) {

	double c;
	zval a, b, *_0;

	ZEPHIR_MM_GROW();
	ZEPHIR_SINIT_VAR(a);
	ZVAL_LONG(&a, 1);

	ZEPHIR_SINIT_VAR(b);
	ZVAL_DOUBLE(&b, 2.0);

	ZEPHIR_INIT_VAR(_0);
	zephir_add_function(_0, &b, &a);

	c = zephir_get_doubleval(_0);

	RETURN_MM_DOUBLE(c);


}

PHP_METHOD(Test_Arithmetic, complex17Sum) {

	double c;
	zend_bool b;
	zval a;

	ZEPHIR_SINIT_VAR(a);
	ZVAL_LONG(&a, 1);

	b = (2.0) ? 1 : 0;

	c = (double) (zephir_get_intval(&a) + b);

	RETURN_DOUBLE(c);


}

PHP_METHOD(Test_Arithmetic, complex18Sum) {

	double c;
	zend_bool b;
	zval a, d;

	ZEPHIR_SINIT_VAR(a);
	ZVAL_LONG(&a, 1);

	b = (2.0) ? 1 : 0;

	ZEPHIR_SINIT_VAR(d);
	ZVAL_LONG(&d, zephir_get_intval(&a) + b);

	c = (double) (zephir_get_intval(&a) + b + zephir_get_intval(&d));

	RETURN_DOUBLE(c);


}

PHP_METHOD(Test_Arithmetic, complex19Sum) {

	double c;
	zend_bool b;
	zval a, d, *_0;

	ZEPHIR_MM_GROW();
	ZEPHIR_SINIT_VAR(a);
	ZVAL_LONG(&a, 1);

	b = (2.0) ? 1 : 0;

	ZEPHIR_SINIT_VAR(d);
	ZVAL_LONG(&d, zephir_get_intval(&a) + b);

	ZEPHIR_INIT_VAR(_0);
	zephir_add_function(_0, &a, &d);

	c = (double) (zephir_get_intval(_0) + b);

	RETURN_MM_DOUBLE(c);


}

PHP_METHOD(Test_Arithmetic, complex20Sum) {

	double c;
	zend_bool b;
	zval a, d, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	ZEPHIR_SINIT_VAR(a);
	ZVAL_LONG(&a, 1);

	b = (2.0) ? 1 : 0;

	ZEPHIR_SINIT_VAR(d);
	ZVAL_LONG(&d, zephir_get_intval(&a) + b);

	ZEPHIR_INIT_VAR(_0);
	zephir_add_function(_0, &d, &d);
	ZEPHIR_INIT_VAR(_1);
	zephir_add_function(_1, _0, &d);
	ZEPHIR_INIT_VAR(_2);
	zephir_add_function(_2, _1, &d);

	c = zephir_get_doubleval(_2);

	RETURN_MM_DOUBLE(c);


}

PHP_METHOD(Test_Arithmetic, complex21Sum) {

	double c;
	zend_bool b;
	zval a, d;

	ZEPHIR_SINIT_VAR(a);
	ZVAL_LONG(&a, 1);

	b = (2.0) ? 1 : 0;

	ZEPHIR_SINIT_VAR(d);
	ZVAL_LONG(&d, zephir_get_intval(&a) + b);

	c = (double) (b + zephir_get_intval(&d) + b + zephir_get_intval(&d) + zephir_get_intval(&d) + b + zephir_get_intval(&d) + b);

	RETURN_DOUBLE(c);


}

PHP_METHOD(Test_Arithmetic, complex22Sum) {

	double c;
	long b;
	zval a, d;

	ZEPHIR_SINIT_VAR(a);
	ZVAL_LONG(&a, 1);

	b = (long) (2.0);

	ZEPHIR_SINIT_VAR(d);
	ZVAL_LONG(&d, zephir_get_intval(&a) + b);

	c = (double) (b + zephir_get_intval(&d) + zephir_get_intval(&d) + zephir_get_intval(&d) + zephir_get_intval(&d) + b + zephir_get_intval(&d) + b);

	RETURN_DOUBLE(c);


}

PHP_METHOD(Test_Arithmetic, complex23Sum) {

	double d;
	zend_bool b;
	zval a;

	ZEPHIR_SINIT_VAR(a);
	ZVAL_LONG(&a, 1);

	b = (2.0) ? 1 : 0;

	d = (double) (zephir_get_intval(&a) + b);

	RETURN_DOUBLE(d);


}

PHP_METHOD(Test_Arithmetic, complex24Sum) {

	zend_bool b;
	zval a, d;

	ZEPHIR_SINIT_VAR(a);
	ZVAL_LONG(&a, 1);

	b = (2.0) ? 1 : 0;

	ZEPHIR_SINIT_VAR(d);
	ZVAL_LONG(&d, 1 + zephir_get_intval(&a) + 0 + b);

	RETURN_CCTORW(&d);


}

