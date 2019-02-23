
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


ZEPHIR_INIT_CLASS(Test_ArrayAccessObj) {

	ZEPHIR_REGISTER_CLASS(Test, ArrayAccessObj, test, arrayaccessobj, test_arrayaccessobj_method_entry, 0);

	zend_declare_property_null(test_arrayaccessobj_ce, SL("test"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(test_arrayaccessobj_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

PHP_METHOD(Test_ArrayAccessObj, __construct) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0 TSRMLS_CC);
	add_assoc_long_ex(&_0, SL("one"), 1);
	add_assoc_long_ex(&_0, SL("two"), 2);
	add_assoc_long_ex(&_0, SL("three"), 3);
	zephir_update_property_zval(this_ptr, SL("test"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Test_ArrayAccessObj, offsetSet) {

	zval *offset, offset_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params(0, 2, 0, &offset, &value);



	if (Z_TYPE_P(offset) == IS_NULL) {
		zephir_update_property_array_append(this_ptr, SL("test"), value TSRMLS_CC);
	} else {
		zephir_update_property_array(this_ptr, SL("test"), offset, value TSRMLS_CC);
	}

}

PHP_METHOD(Test_ArrayAccessObj, offsetExists) {

	zval *offset, offset_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &offset);



	zephir_read_property(&_0, this_ptr, SL("test"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, offset));

}

PHP_METHOD(Test_ArrayAccessObj, offsetUnset) {

	zval *offset, offset_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &offset);



	zephir_read_property(&_0, this_ptr, SL("test"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, offset, PH_SEPARATE);

}

PHP_METHOD(Test_ArrayAccessObj, offsetGet) {

	zval *offset, offset_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);



	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("test"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, offset)) {
		zephir_read_property(&_2, this_ptr, SL("test"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, offset, PH_NOISY, "test/arrayaccessobj.zep", 33 TSRMLS_CC);
	} else {
		ZVAL_NULL(&_0);
	}
	RETURN_CCTOR(&_0);

}

