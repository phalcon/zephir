
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
#include "kernel/operators.h"
#include "kernel/exit.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Test_ExitDie) {

	ZEPHIR_REGISTER_CLASS(Test, ExitDie, test, exitdie, test_exitdie_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Test_ExitDie, testExit) {

	zval *param = NULL, param_sub, __$null;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&param_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params(1, 0, 1, &param);

	if (!param) {
		param = &param_sub;
		param = &__$null;
	}


	if (ZEPHIR_IS_EMPTY(param)) {
		ZEPHIR_MM_RESTORE();
		zephir_exit_empty();
	}
	ZEPHIR_MM_RESTORE();
	zephir_exit(param);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Test_ExitDie, testDie) {

	zval *param = NULL, param_sub, __$null;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&param_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params(1, 0, 1, &param);

	if (!param) {
		param = &param_sub;
		param = &__$null;
	}


	if (ZEPHIR_IS_EMPTY(param)) {
		ZEPHIR_MM_RESTORE();
		zephir_exit_empty();
	}
	ZEPHIR_MM_RESTORE();
	zephir_exit(param);
	ZEPHIR_MM_RESTORE();

}

