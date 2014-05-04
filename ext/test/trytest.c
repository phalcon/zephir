
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Test_TryTest) {

	ZEPHIR_REGISTER_CLASS(Test, TryTest, test, trytest, test_trytest_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Test_TryTest, testThrow1) {


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(zend_exception_get_default(TSRMLS_C), "error", "test/trytest.zep", 10);
	return;

}

PHP_METHOD(Test_TryTest, testThrow2) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message, *_0;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(message);
	ZVAL_STRING(message, "error", 1);

	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zend_exception_get_default(TSRMLS_C));
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, message);
	zephir_check_call_status();
	zephir_throw_exception_debug(_0, "test/trytest.zep", 16 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Test_TryTest, testTry1) {



	/* try_start_1: */


	try_end_1:

	zend_clear_exception(TSRMLS_C);

}

PHP_METHOD(Test_TryTest, testTry2) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();


	/* try_start_1: */

		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "error!", 0);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_throw_exception_debug(_0, "test/trytest.zep", 27 TSRMLS_CC);
		goto try_end_1;


	try_end_1:

	zend_clear_exception(TSRMLS_C);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Test_TryTest, testTry3) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();


	/* try_start_1: */

		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "error!", 0);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_throw_exception_debug(_0, "test/trytest.zep", 34 TSRMLS_CC);
		goto try_end_1;


	try_end_1:

	ZEPHIR_INIT_NVAR(_1);
	ZEPHIR_CPY_WRT(_1, EG(exception));
	if (zephir_instance_of_ev(_1, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
		zend_clear_exception(TSRMLS_C);
		RETURN_MM_STRING("error", 1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Test_TryTest, testTry4) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *a_param = NULL, *_0 = NULL, *_1 = NULL;
	zend_bool a;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &a_param);

	a = zephir_get_boolval(a_param);



	/* try_start_1: */

		if (a) {
			ZEPHIR_INIT_VAR(_0);
			object_init_ex(_0, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_VAR(_1);
			ZVAL_STRING(_1, "error!", 0);
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(_0, "test/trytest.zep", 46 TSRMLS_CC);
			goto try_end_1;

		} else {
			ZEPHIR_INIT_LNVAR(_0);
			object_init_ex(_0, spl_ce_RuntimeException);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "error!", 0);
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(_0, "test/trytest.zep", 48 TSRMLS_CC);
			goto try_end_1;

		}

	try_end_1:

	ZEPHIR_INIT_NVAR(_1);
	ZEPHIR_CPY_WRT(_1, EG(exception));
	if (zephir_instance_of_ev(_1, spl_ce_RuntimeException TSRMLS_CC)) {
		zend_clear_exception(TSRMLS_C);
		RETURN_MM_STRING("domain error", 1);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZEPHIR_CPY_WRT(_1, EG(exception));
	if (zephir_instance_of_ev(_1, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
		zend_clear_exception(TSRMLS_C);
		RETURN_MM_STRING("error", 1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Test_TryTest, testTry5) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *a_param = NULL, *_0 = NULL, *_1 = NULL;
	zend_bool a;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &a_param);

	a = zephir_get_boolval(a_param);



	/* try_start_1: */

		if (a) {
			ZEPHIR_INIT_VAR(_0);
			object_init_ex(_0, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_VAR(_1);
			ZVAL_STRING(_1, "error!", 0);
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(_0, "test/trytest.zep", 63 TSRMLS_CC);
			goto try_end_1;

		} else {
			ZEPHIR_INIT_LNVAR(_0);
			object_init_ex(_0, spl_ce_RuntimeException);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "error!", 0);
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(_0, "test/trytest.zep", 65 TSRMLS_CC);
			goto try_end_1;

		}

	try_end_1:

	ZEPHIR_INIT_NVAR(_1);
	ZEPHIR_CPY_WRT(_1, EG(exception));
	if (zephir_instance_of_ev(_1, spl_ce_RuntimeException TSRMLS_CC)) {
		zend_clear_exception(TSRMLS_C);
		RETURN_MM_STRING("any error", 1);
	}
	if (zephir_instance_of_ev(_1, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
		zend_clear_exception(TSRMLS_C);
		RETURN_MM_STRING("any error", 1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Test_TryTest, testTry6) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *a_param = NULL, *e = NULL, *_0 = NULL, *_1 = NULL;
	zend_bool a;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &a_param);

	a = zephir_get_boolval(a_param);



	/* try_start_1: */

		if (a) {
			ZEPHIR_INIT_VAR(_0);
			object_init_ex(_0, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_VAR(_1);
			ZVAL_STRING(_1, "error!", 0);
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(_0, "test/trytest.zep", 80 TSRMLS_CC);
			goto try_end_1;

		} else {
			ZEPHIR_INIT_LNVAR(_0);
			object_init_ex(_0, spl_ce_RuntimeException);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "error!", 0);
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(_0, "test/trytest.zep", 82 TSRMLS_CC);
			goto try_end_1;

		}

	try_end_1:

	ZEPHIR_CPY_WRT(e, EG(exception));
	if (zephir_instance_of_ev(e, spl_ce_RuntimeException TSRMLS_CC)) {
		zend_clear_exception(TSRMLS_C);
		RETURN_MM_STRING("domain error", 1);
	}
	ZEPHIR_CPY_WRT(e, EG(exception));
	if (zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
		zend_clear_exception(TSRMLS_C);
		RETURN_MM_STRING("error", 1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Test_TryTest, testTry7) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *a_param = NULL, *e = NULL, *_0 = NULL, *_1 = NULL;
	zend_bool a;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &a_param);

	a = zephir_get_boolval(a_param);



	/* try_start_1: */

		if (a) {
			ZEPHIR_INIT_VAR(_0);
			object_init_ex(_0, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_VAR(_1);
			ZVAL_STRING(_1, "error!", 0);
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(_0, "test/trytest.zep", 99 TSRMLS_CC);
			goto try_end_1;

		} else {
			ZEPHIR_INIT_LNVAR(_0);
			object_init_ex(_0, spl_ce_RuntimeException);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "error!", 0);
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(_0, "test/trytest.zep", 101 TSRMLS_CC);
			goto try_end_1;

		}

	try_end_1:

	ZEPHIR_CPY_WRT(e, EG(exception));
	if (zephir_instance_of_ev(e, spl_ce_RuntimeException TSRMLS_CC)) {
		zend_clear_exception(TSRMLS_C);
		RETURN_MM_STRING("any error", 1);
	}
	if (zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
		zend_clear_exception(TSRMLS_C);
		RETURN_MM_STRING("any error", 1);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Test_TryTest, testTry8) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();


	/* try_start_1: */

		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "error 1!", 0);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_throw_exception_debug(_0, "test/trytest.zep", 111 TSRMLS_CC);
		goto try_end_1;


	try_end_1:

	zend_clear_exception(TSRMLS_C);
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "error 2!", "test/trytest.zep", 113);
	return;

}

PHP_METHOD(Test_TryTest, someMethod1) {


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_RuntimeException, "some external exception", "test/trytest.zep", 118);
	return;

}

PHP_METHOD(Test_TryTest, someMethod2) {


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_DomainException, "some external exception", "test/trytest.zep", 123);
	return;

}

PHP_METHOD(Test_TryTest, testTry9) {

	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *e = NULL;

	ZEPHIR_MM_GROW();


	/* try_start_1: */

		ZEPHIR_CALL_METHOD(NULL, this_ptr, "somemethod1", &_0);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM_STRING("not catched", 1);

	try_end_1:

	ZEPHIR_CPY_WRT(e, EG(exception));
	if (zephir_instance_of_ev(e, spl_ce_RuntimeException TSRMLS_CC)) {
		zend_clear_exception(TSRMLS_C);
		RETURN_MM_STRING("domain error", 1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Test_TryTest, testTry10) {

	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *e = NULL;

	ZEPHIR_MM_GROW();


	/* try_start_1: */

		ZEPHIR_CALL_METHOD(NULL, this_ptr, "somemethod2", &_0);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM_STRING("not catched", 1);

	try_end_1:

	ZEPHIR_CPY_WRT(e, EG(exception));
	if (zephir_instance_of_ev(e, spl_ce_RuntimeException TSRMLS_CC)) {
		zend_clear_exception(TSRMLS_C);
		RETURN_MM_STRING("domain error", 1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * @link https://github.com/phalcon/zephir/issues/369
 */
PHP_METHOD(Test_TryTest, testTryCatchInLoop) {

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *arr_param = NULL, *val = NULL, **_2, *_3 = NULL, *_5 = NULL;
	zval *arr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arr_param);

	zephir_get_arrval(arr, arr_param);


	zephir_is_iterable(arr, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(val, _2);

		/* try_start_1: */

			if (ZEPHIR_IS_LONG(val, 0)) {
				ZEPHIR_INIT_LNVAR(_3);
				object_init_ex(_3, zend_exception_get_default(TSRMLS_C));
				ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_4);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(_3, "test/trytest.zep", 165 TSRMLS_CC);
				goto try_end_1;

			}

		try_end_1:

		ZEPHIR_INIT_NVAR(_5);
		ZEPHIR_CPY_WRT(_5, EG(exception));
		if (zephir_is_instance_of(_5, SL("e") TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

