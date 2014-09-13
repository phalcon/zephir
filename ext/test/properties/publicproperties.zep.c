
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"

ZEPHIR_INIT_CLASS(Test_Properties_PublicProperties) {

	ZEPHIR_REGISTER_CLASS(Test\\Properties, PublicProperties, test, properties_publicproperties, test_properties_publicproperties_method_entry, 0);

	/**
	 * This is a public property with no initial value
	 */
	zend_declare_property_null(test_properties_publicproperties_ce, SL("someNull"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * This is a public property with initial null value
	 */
	zend_declare_property_null(test_properties_publicproperties_ce, SL("someNullInitial"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * This is a public property with initial boolean false
	 */
	zend_declare_property_bool(test_properties_publicproperties_ce, SL("someFalse"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * This is a public property with initial boolean true
	 */
	zend_declare_property_bool(test_properties_publicproperties_ce, SL("someTrue"), 1, ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * This is a public property with an initial integer value
	 */
	zend_declare_property_long(test_properties_publicproperties_ce, SL("someInteger"), 10, ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * This is a public property with an initial double value
	 */
	zend_declare_property_double(test_properties_publicproperties_ce, SL("someDouble"), 10.25, ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * This is a public property with an initial string value
	 */
	zend_declare_property_string(test_properties_publicproperties_ce, SL("someString"), "test", ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * This is a public property with an initial empty-array value
	 */
	zend_declare_property_null(test_properties_publicproperties_ce, SL("someEmptyArray"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * This is a public property with an initial array value
	 */
	zend_declare_property_null(test_properties_publicproperties_ce, SL("someArray"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_long(test_properties_publicproperties_ce, SL("testPropertyFromSelfConstantValue"), 123, ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_long(test_properties_publicproperties_ce, SL("testPropertyFromClassNameConstantValue"), 123, ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_class_constant_long(test_properties_publicproperties_ce, SL("TEST_CONST"), 123 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Test_Properties_PublicProperties, test394Issue) {

	zval *_1;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "someTrue", 1);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, this_ptr, _0, PH_NOISY_CC);
	RETURN_CCTOR(_1);

}

PHP_METHOD(Test_Properties_PublicProperties, __construct) {

	zval *_1;
	zval *_0, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("someEmptyArray"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 6);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_LONG(_2, 2);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_LONG(_2, 3);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_LONG(_2, 4);
	zephir_array_fast_append(_1, _2);
	zephir_update_property_this(this_ptr, SL("someArray"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

