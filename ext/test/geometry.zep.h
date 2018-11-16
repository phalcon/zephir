
extern zend_class_entry *test_geometry_ce;

ZEPHIR_INIT_CLASS(Test_Geometry);

PHP_METHOD(Test_Geometry, run);
PHP_METHOD(Test_Geometry, runOptimize);
PHP_METHOD(Test_Geometry, distanceStatic);

ZEND_BEGIN_ARG_INFO_EX(arginfo_test_geometry_run, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, list, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_test_geometry_runoptimize, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, list, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_geometry_distancestatic, 0, 4, IS_DOUBLE, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test_geometry_distancestatic, 0, 4, IS_DOUBLE, NULL, 0)
#endif
	ZEND_ARG_TYPE_INFO(0, x1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y2, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(test_geometry_method_entry) {
	PHP_ME(Test_Geometry, run, arginfo_test_geometry_run, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Test_Geometry, runOptimize, arginfo_test_geometry_runoptimize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Test_Geometry, distanceStatic, arginfo_test_geometry_distancestatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
