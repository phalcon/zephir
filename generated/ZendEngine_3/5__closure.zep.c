
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


ZEPHIR_INIT_CLASS(test_5__closure) {

	ZEPHIR_REGISTER_CLASS(test, 5__closure, test, 5__closure, test_5__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(test_5__closure, __invoke) {

	zval *param1, param1_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&param1_sub);

	zephir_fetch_params(0, 1, 0, &param1);



	RETURN_NULL();

}

