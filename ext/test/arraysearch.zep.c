
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Test_ArraySearch) {

	ZEPHIR_REGISTER_CLASS(Test, ArraySearch, test, arraysearch, test_arraysearch_method_entry, 0);

	return SUCCESS;

}

/** @issue https://github.com/phalcon/zephir/issues/1609 */
PHP_METHOD(Test_ArraySearch, simpleSearch) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool strict;
	zval haystack;
	zval *needle, needle_sub, *haystack_param = NULL, *strict_param = NULL, _0;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&needle_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&haystack);

	zephir_fetch_params(1, 2, 1, &needle, &haystack_param, &strict_param);

	zephir_get_arrval(&haystack, haystack_param);
	if (!strict_param) {
		strict = 0;
	} else {
		strict = zephir_get_boolval(strict_param);
	}


	ZVAL_BOOL(&_0, (strict ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("array_search", NULL, 5, needle, &haystack, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/** @issue https://github.com/phalcon/zephir/issues/1609 */
PHP_METHOD(Test_ArraySearch, searchUsingArrayInsideZephir) {

	zval _0, pos;
	zval itoA64;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZEPHIR_MM_GROW();
	ZVAL_UNDEF(&itoA64);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&pos);


	zephir_create_array(&itoA64, 9, 0);
	ZEPHIR_MM_ADD_ENTRY(&itoA64);
	ZEPHIR_MM_ZVAL_STRING(&_0, ".");
	zephir_array_fast_append(&itoA64, &_0);
	ZEPHIR_MM_ZVAL_STRING(&_0, "/");
	zephir_array_fast_append(&itoA64, &_0);
	ZEPHIR_MM_ZVAL_STRING(&_0, "0");
	zephir_array_fast_append(&itoA64, &_0);
	ZEPHIR_MM_ZVAL_STRING(&_0, "1");
	zephir_array_fast_append(&itoA64, &_0);
	ZEPHIR_MM_ZVAL_STRING(&_0, "2");
	zephir_array_fast_append(&itoA64, &_0);
	ZEPHIR_MM_ZVAL_STRING(&_0, "3");
	zephir_array_fast_append(&itoA64, &_0);
	ZEPHIR_MM_ZVAL_STRING(&_0, "4");
	zephir_array_fast_append(&itoA64, &_0);
	ZEPHIR_MM_ZVAL_STRING(&_0, "value");
	zephir_array_fast_append(&itoA64, &_0);
	ZEPHIR_MM_ZVAL_STRING(&_0, "OtherValue");
	zephir_array_fast_append(&itoA64, &_0);
	ZEPHIR_MM_ZVAL_STRING(&_0, "value");
	ZEPHIR_CALL_FUNCTION(&pos, "array_search", NULL, 5, &_0, &itoA64);
	zephir_check_call_status();
	RETURN_MM_CTOR(&pos);

}

