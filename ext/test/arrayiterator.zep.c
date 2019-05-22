
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
#include "kernel/array.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Test_ArrayIterator) {

	ZEPHIR_REGISTER_CLASS(Test, ArrayIterator, test, arrayiterator, test_arrayiterator_method_entry, 0);

	zend_declare_property_long(test_arrayiterator_ce, SL("position"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(test_arrayiterator_ce, SL("test"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(test_arrayiterator_ce TSRMLS_CC, 1, zend_ce_iterator);
	return SUCCESS;

}

PHP_METHOD(Test_ArrayIterator, __construct) {

	zval _1, _2;
	zval _0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	zephir_create_array(&_0, 3, 0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	ZEPHIR_MM_ZVAL_STRING(&_1, "one");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_MM_ZVAL_STRING(&_1, "two");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_MM_ZVAL_STRING(&_1, "three");
	zephir_array_fast_append(&_0, &_1);
	zephir_update_property_zval(this_ptr, SL("test"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, 0);
	zephir_update_property_zval(this_ptr, SL("position"), &_2);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Test_ArrayIterator, rewind) {

	zval _0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&_0);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("position"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Test_ArrayIterator, current) {

	zval _0, _1, _2;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	zephir_read_property(&_0, this_ptr, SL("test"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_SEPARATE(&_0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_read_property(&_2, this_ptr, SL("position"), PH_NOISY_CC);
	ZEPHIR_MM_ADD_ENTRY(&_2);
	zephir_array_fetch(&_1, &_0, &_2, PH_NOISY | PH_READONLY, "test/arrayiterator.zep", 22 TSRMLS_CC);
	RETURN_MM_CTOR(&_1);

}

PHP_METHOD(Test_ArrayIterator, key) {

	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();

	RETURN_MM_MEMBER(getThis(), "position");

}

PHP_METHOD(Test_ArrayIterator, next) {

	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();

	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("position") TSRMLS_CC));
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Test_ArrayIterator, valid) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("test"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_SEPARATE(&_0);
	ZEPHIR_MM_ADD_ENTRY(&_0);
	zephir_read_property(&_1, this_ptr, SL("position"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_SEPARATE(&_1);
	ZEPHIR_MM_ADD_ENTRY(&_1);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &_1));

}

