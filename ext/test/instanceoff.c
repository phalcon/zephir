
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
#include "kernel/fcall.h"


/**
 * OO operations
 */
ZEPHIR_INIT_CLASS(Test_Instanceoff) {

	ZEPHIR_REGISTER_CLASS(Test, Instanceoff, test, instanceoff, test_instanceoff_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Test_Instanceoff, testInstanceOf1) {

	zval *a;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(a);
	object_init(a);
	RETURN_MM_BOOL(zephir_instance_of_ev(a, zend_standard_class_def TSRMLS_CC));

}

PHP_METHOD(Test_Instanceoff, testInstanceOf2) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *a;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(a);
	object_init_ex(a, test_instanceoff_ce);
	if (zephir_has_constructor(a TSRMLS_CC)) {
		zephir_call_method_noret(a, "__construct");
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(zephir_instance_of_ev(a, test_instanceoff_ce TSRMLS_CC));

}

PHP_METHOD(Test_Instanceoff, testInstanceOf3) {

	zval *a;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(a);
	object_init(a);
	RETURN_MM_BOOL(zephir_instance_of_ev(a, test_unknownclass_ce TSRMLS_CC));

}

