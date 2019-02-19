
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/object.h"


/**
 * OO operations
 */
ZEPHIR_INIT_CLASS(Test_Oo) {

	ZEPHIR_REGISTER_CLASS(Test, Oo, test, oo, test_oo_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Test_Oo, testInstance1) {

	zval o;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&o);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&o);
	object_init(&o);
	RETURN_CCTOR(&o);

}

PHP_METHOD(Test_Oo, testInstance2) {

	zval o;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&o);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&o);
	object_init_ex(&o, test_oo_ooconstruct_ce);
	ZEPHIR_CALL_METHOD(NULL, &o, "__construct", NULL, 49);
	zephir_check_call_status();
	RETURN_CCTOR(&o);

}

PHP_METHOD(Test_Oo, testInstance3) {

	zval o;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&o);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&o);
	object_init_ex(&o, test_oo_oonoconstruct_ce);
	if (zephir_has_constructor(&o TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &o, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&o);

}

PHP_METHOD(Test_Oo, testInstance4) {

	zval o, a, b;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&o);
	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&b);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&a);
	ZVAL_STRING(&a, "a");
	ZEPHIR_INIT_VAR(&b);
	ZVAL_STRING(&b, "b");
	ZEPHIR_INIT_VAR(&o);
	object_init_ex(&o, test_oo_ooconstructparams_ce);
	ZEPHIR_CALL_METHOD(NULL, &o, "__construct", NULL, 50, &a, &b);
	zephir_check_call_status();
	RETURN_CCTOR(&o);

}

PHP_METHOD(Test_Oo, testInstance5) {

	zval o, _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&o);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&o);
	object_init_ex(&o, test_oo_ooconstructparams_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "a");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "b");
	ZEPHIR_CALL_METHOD(NULL, &o, "__construct", NULL, 50, &_0, &_1);
	zephir_check_call_status();
	RETURN_CCTOR(&o);

}

PHP_METHOD(Test_Oo, testInstance6) {

	zval o, _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&o);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&o);
	object_init_ex(&o, test_oo_ooconstructparams_ce);
	ZVAL_LONG(&_0, 1);
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_METHOD(NULL, &o, "__construct", NULL, 50, &_0, &_1);
	zephir_check_call_status();
	RETURN_CCTOR(&o);

}

PHP_METHOD(Test_Oo, testInstance7) {

	zval o, _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&o);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&o);
	object_init_ex(&o, test_oo_ooconstructparams_ce);
	ZVAL_BOOL(&_0, 0);
	ZVAL_BOOL(&_1, 1);
	ZEPHIR_CALL_METHOD(NULL, &o, "__construct", NULL, 50, &_0, &_1);
	zephir_check_call_status();
	RETURN_CCTOR(&o);

}

PHP_METHOD(Test_Oo, testInstance8) {

	zval o, _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&o);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&o);
	object_init_ex(&o, test_oo_ooconstructparams_ce);
	ZVAL_DOUBLE(&_0, 1.2);
	ZVAL_DOUBLE(&_1, 7.30);
	ZEPHIR_CALL_METHOD(NULL, &o, "__construct", NULL, 50, &_0, &_1);
	zephir_check_call_status();
	RETURN_CCTOR(&o);

}

PHP_METHOD(Test_Oo, testInstance9) {

	zval o;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&o);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&o, test_oo_oodynamica_ce, "getnew", &_0, 0);
	zephir_check_call_status();
	RETURN_CCTOR(&o);

}

PHP_METHOD(Test_Oo, testInstance10) {

	zval o;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&o);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&o, test_oo_oodynamicb_ce, "getnew", &_0, 0);
	zephir_check_call_status();
	RETURN_CCTOR(&o);

}

PHP_METHOD(Test_Oo, testInstance11) {

	zval o, _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&o);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&o);
	object_init_ex(&o, test_oo_ooconstructparams_ce);
	ZVAL_LONG(&_0, 1);
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_METHOD(NULL, &o, "__construct", NULL, 50, &_0, &_1);
	zephir_check_call_status();
	RETURN_CCTOR(&o);

}

PHP_METHOD(Test_Oo, testInstance12) {

	zval o;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&o);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&o, test_oo_oodynamica_ce, "call1", &_0, 0);
	zephir_check_call_status();
	RETURN_CCTOR(&o);

}

PHP_METHOD(Test_Oo, createInstancesInLoop) {

	zend_class_entry *_4$$3;
	zval result, _0;
	zval className, instance, fqcn, _1, *_2, _3$$3, _5$$3, _6$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&fqcn);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "OoDynamicA");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "OoDynamicB");
	zephir_array_fast_append(&_0, &_1);
	zephir_is_iterable(&_0, 0, "test/oo.zep", 112);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _2)
	{
		ZEPHIR_INIT_NVAR(&className);
		ZVAL_COPY(&className, _2);
		ZEPHIR_INIT_NVAR(&fqcn);
		ZEPHIR_CONCAT_SV(&fqcn, "Test\\Oo\\", &className);
		ZEPHIR_INIT_NVAR(&instance);
		zephir_fetch_safe_class(&_3$$3, &fqcn);
		_4$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_3$$3), Z_STRLEN_P(&_3$$3), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(&instance, _4$$3);
		if (zephir_has_constructor(&instance TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &instance, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_5$$3, &instance, "execute", NULL, 0);
		zephir_check_call_status();
		zephir_array_append(&result, &_5$$3, PH_SEPARATE, "test/oo.zep", 108);
		ZEPHIR_CALL_METHOD(&_6$$3, &instance, "execute2", NULL, 0);
		zephir_check_call_status();
		zephir_array_append(&result, &_6$$3, PH_SEPARATE, "test/oo.zep", 109);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&className);
	RETURN_CTOR(&result);

}

