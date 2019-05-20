
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(test_11__closure) {

	ZEPHIR_REGISTER_CLASS(test, 11__closure, test, 11__closure, test_11__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(test_11__closure, __invoke) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();


	ZEPHIR_RETURN_CALL_CE_STATIC(test_mcall_caller_ce, "perform", &_0, 0);
	zephir_check_call_status();
	RETURN_MM();

}

