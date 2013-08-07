
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"


/**
 * Test\Router
 *
 * <p>Test\Router is the standard framework router. Routing is the
 * process of taking a URI endpoint (that part of the URI which comes after the base URL) and
 * decomposing it into parameters to determine which module, controller, and
 * action of that controller should receive the request</p>
 *
 *<code>
 *
 *	$router = new Test\Router();
 *
 *	$router->add(
 *		"/documentation/{chapter}/{name}.{type:[a-z]+}",
 *		array(
 *			"controller" => "documentation",
 *			"action"     => "show"
 *		)
 *	);
 *
 *	$router->handle();
 *
 *	echo $router->getControllerName();
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Test_Router) {

	ZEPHIR_REGISTER_CLASS(Test, Router, router, test_router_method_entry, 0);

	zend_declare_property_null(test_router_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_ce, SL("_uriSource"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_ce, SL("_namespace"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_ce, SL("_module"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_ce, SL("_controller"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_ce, SL("_action"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_ce, SL("_routes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_ce, SL("_matchedRoute"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_ce, SL("_matches"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(test_router_ce, SL("_wasMatched"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_ce, SL("_defaultNamespace"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_ce, SL("_defaultModule"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_ce, SL("_defaultController"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_ce, SL("_defaultAction"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_ce, SL("_defaultParams"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_ce, SL("_removeExtraSlashes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_ce, SL("_notFoundPaths"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Test\Router constructor
 *
 * @param boolean defaultRoutes
 */
PHP_METHOD(Test_Router, __construct) {

	zval *defaultRoutes_param = NULL, *routes, *_0, *_1, *_2, *_3, *_4, *_5, *_6;
	zend_bool defaultRoutes;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &defaultRoutes_param);

	if (!defaultRoutes_param) {
		defaultRoutes = 1;
	} else {
		defaultRoutes = zephir_get_boolval(defaultRoutes_param);
	}


	ZEPHIR_INIT_VAR(routes);
	array_init(routes);

	if ((defaultRoutes == 1)) {
		//missing comment
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, test_router_route_ce);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "#^/([a-zA-Z0-9\\_\\-]+)[/]{0,1}$#", 1);
		ZEPHIR_INIT_VAR(_2);
		array_init(_2);
		add_assoc_long_ex(_2, SS("controller"), 1);
		zephir_call_method_p2_noret(_0, "__construct", _1, _2);

		zephir_array_append(&routes, _0, PH_SEPARATE);

		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, test_router_route_ce);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "#^/([a-zA-Z0-9\\_\\-]+)/([a-zA-Z0-9\\.\\_]+)(/.*)*$#", 1);
		ZEPHIR_INIT_VAR(_5);
		array_init(_5);
		add_assoc_long_ex(_5, SS("controller"), 1);
		add_assoc_long_ex(_5, SS("action"), 2);
		add_assoc_long_ex(_5, SS("params"), 3);
		zephir_call_method_p2_noret(_3, "__construct", _4, _5);

		zephir_array_append(&routes, _3, PH_SEPARATE);

	}

	ZEPHIR_INIT_VAR(_6);
	array_init(_6);
	zephir_update_property_zval(this_ptr, SL("_params"), _6 TSRMLS_CC);

	zephir_update_property_zval(this_ptr, SL("_routes"), routes TSRMLS_CC);

	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Test_Router, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);


}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Test_Router, getDI) {

	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Get rewrite info. This info is read from $_GET['_url']. This returns '/' if the rewrite information cannot be read
 *
 * @return string
 */
PHP_METHOD(Test_Router, getRewriteUri) {

	zval *uriSource, *url = NULL, *urlParts, *realUri, *_GET, *_SERVER, *_0;

	ZEPHIR_MM_GROW();
	//missing comment
	ZEPHIR_OBS_VAR(uriSource);
	zephir_read_property(&uriSource, this_ptr, SL("_uriSource"), PH_NOISY_CC);

	//missing comment
	if (!(zend_is_true(uriSource))) {
		ZEPHIR_OBS_VAR(url);
		zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
		if (zephir_array_isset_string(_GET, SS("_url"))) {
			if (!(zend_is_true(url))) {

				RETURN_CCTOR(url);

			}
		}
	} else {
		//missing comment
		ZEPHIR_OBS_NVAR(url);
		zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
		if (zephir_array_isset_string(_SERVER, SS("REQUEST_URI"))) {
			ZEPHIR_INIT_VAR(urlParts);
			ZEPHIR_INIT_VAR(_0);
			ZVAL_STRING(_0, "?", 1);
			zephir_call_func_p2(urlParts, "explode", _0, url);

			ZEPHIR_OBS_VAR(realUri);
			zephir_array_fetch_long(&realUri, urlParts, 0, PH_NOISY);

			if (!(zend_is_true(realUri))) {

				RETURN_CCTOR(realUri);

			}
		}
	}

	RETURN_MM_STRING("/", 1);


}

/**
 * Sets the URI source. One of the URI_SOURCE_* constants
 *
 *<code>
 *	$router->setUriSource(Router::URI_SOURCE_SERVER_REQUEST_URI);
 *</code>
 *
 * @param string uriSource
 * @return Test\Router
 */
PHP_METHOD(Test_Router, setUriSource) {

	zval *uriSource;

	zephir_fetch_params(0, 1, 0, &uriSource);



	zephir_update_property_zval(this_ptr, SL("_uriSource"), uriSource TSRMLS_CC);

	RETURN_THISW();


}

/**
 * Set whether router must remove the extra slashes in the handled routes
 *
 * @param boolean remove
 * @return Test\Router
 */
PHP_METHOD(Test_Router, removeExtraSlashes) {

	zval *remove;

	zephir_fetch_params(0, 1, 0, &remove);



	zephir_update_property_zval(this_ptr, SL("_removeExtraSlashes"), remove TSRMLS_CC);

	RETURN_THISW();


}

/**
 * Sets the name of the default namespace
 *
 * @param string namespaceName
 * @return Test\Router
 */
PHP_METHOD(Test_Router, setDefaultNamespace) {

	zval *namespaceName;

	zephir_fetch_params(0, 1, 0, &namespaceName);



	zephir_update_property_zval(this_ptr, SL("_defaultNamespace"), namespaceName TSRMLS_CC);

	RETURN_THISW();


}

/**
 * Sets the name of the default module
 *
 * @param string moduleName
 * @return Test\Router
 */
PHP_METHOD(Test_Router, setDefaultModule) {

	zval *moduleName;

	zephir_fetch_params(0, 1, 0, &moduleName);



	zephir_update_property_zval(this_ptr, SL("_defaultModule"), moduleName TSRMLS_CC);

	RETURN_THISW();


}

/**
 * Sets the default controller name
 *
 * @param string controllerName
 * @return Test\Router
 */
PHP_METHOD(Test_Router, setDefaultController) {

	zval *controllerName;

	zephir_fetch_params(0, 1, 0, &controllerName);



	zephir_update_property_zval(this_ptr, SL("_defaultController"), controllerName TSRMLS_CC);

	RETURN_THISW();


}

/**
 * Sets the default action name
 *
 * @param string actionName
 * @return Test\Router
 */
PHP_METHOD(Test_Router, setDefaultAction) {

	zval *actionName;

	zephir_fetch_params(0, 1, 0, &actionName);



	zephir_update_property_zval(this_ptr, SL("_defaultAction"), actionName TSRMLS_CC);

	RETURN_THISW();


}

/**
 * Sets an array of default paths. If a route is missing a path the router will use the defined here
 * This method must not be used to set a 404 route
 *
 *<code>
 * $router->setDefaults(array(
 *		'module' => 'common',
 *		'action' => 'index'
 * ));
 *</code>
 *
 * @param array defaults
 * @return Test\Router
 */
PHP_METHOD(Test_Router, setDefaults) {

	zval *defaults, *namespaceName, *module, *controller, *action, *params;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaults);



	if (Z_TYPE_P(defaults) == IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_STR(test_router_exception_ce, "Defaults must be an array");
		return;
	}
	//missing comment
	ZEPHIR_OBS_VAR(namespaceName);
	if (zephir_array_isset_string(defaults, SS("namespace"))) {

		zephir_update_property_zval(this_ptr, SL("_defaultNamespace"), namespaceName TSRMLS_CC);

	}
	//missing comment
	ZEPHIR_OBS_VAR(module);
	if (zephir_array_isset_string(defaults, SS("module"))) {

		zephir_update_property_zval(this_ptr, SL("_defaultModule"), module TSRMLS_CC);

	}
	//missing comment
	ZEPHIR_OBS_VAR(controller);
	if (zephir_array_isset_string(defaults, SS("controller"))) {

		zephir_update_property_zval(this_ptr, SL("_defaultController"), controller TSRMLS_CC);

	}
	//missing comment
	ZEPHIR_OBS_VAR(action);
	if (zephir_array_isset_string(defaults, SS("action"))) {

		zephir_update_property_zval(this_ptr, SL("_defaultAction"), action TSRMLS_CC);

	}
	//missing comment
	ZEPHIR_OBS_VAR(params);
	if (zephir_array_isset_string(defaults, SS("params"))) {

		zephir_update_property_zval(this_ptr, SL("_defaultParams"), params TSRMLS_CC);

	}

	RETURN_THIS();


}

/**
 * Handles routing information received from the rewrite engine
 *
 *<code>
 * //Read the info from the rewrite engine
 * $router->handle();
 *
 * //Manually passing an URL
 * $router->handle('/posts/edit/1');
 *</code>
 *
 * @param string uri
 */
PHP_METHOD(Test_Router, handle) {

	HashTable *_5, *_18;
	HashPosition _4, _17;
	zval *uri = NULL, *realUri, *request = NULL, *currentHostName = NULL, *routeFound = NULL, *parts, *params = NULL, *matches, *notFoundPaths, *vnamespace, *module, *controller, *action, *paramsStr, *strParams, *paramsMerge, *route, *methods = NULL, *dependencyInjector = NULL, *hostname = NULL, *regexHostName = NULL, *matched = NULL, *pattern = NULL, *handledUri, *beforeMatch = NULL, *paths = NULL, *converters = NULL, *part, *position, *matchPosition = NULL, *_0, *_1, *_2, *_3, **_6, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, **_19, *_20, *_21, *_22, *_23, *_24, *_25, *_26, *_27, *_28, *_29, *_30, *_31, *_32, *_33, *_34, *_35, *_36;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		ZEPHIR_INIT_VAR(uri);
	}


	if (!(zend_is_true(uri))) {
		//missing comment
		ZEPHIR_INIT_VAR(realUri);
		zephir_call_method(realUri, this_ptr, "getrewriteuri");

	} else {

		ZEPHIR_CPY_WRT(realUri, uri);

	}
	//missing comment
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, this_ptr, SL("_removeExtraSlashes"), PH_NOISY_CC);
	if (zend_is_true(_0)) {
		ZEPHIR_INIT_VAR(handledUri);
		zephir_call_func_p1(handledUri, "removeextraslashes", realUri);

	} else {

		ZEPHIR_CPY_WRT(handledUri, realUri);

	}

	ZEPHIR_INIT_VAR(request);
	ZVAL_NULL(request);

	ZEPHIR_INIT_VAR(currentHostName);
	ZVAL_NULL(currentHostName);

	ZEPHIR_INIT_VAR(routeFound);
	ZVAL_BOOL(routeFound, 0);

	ZEPHIR_INIT_VAR(parts);
	array_init(parts);

	ZEPHIR_INIT_VAR(params);
	array_init(params);

	ZEPHIR_INIT_VAR(matches);
	ZVAL_NULL(matches);

	ZEPHIR_INIT_VAR(_1);
	zephir_update_property_zval(this_ptr, SL("_wasMatched"), _1 TSRMLS_CC);

	ZEPHIR_INIT_VAR(_2);
	zephir_update_property_zval(this_ptr, SL("_matchedRoute"), _2 TSRMLS_CC);

	//missing comment
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, this_ptr, SL("_routes"), PH_NOISY_CC);
	zephir_is_iterable(_3, &_5, &_4, 0, 1);
	while (zend_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS) {
		ZEPHIR_GET_HVALUE(route, _6);
		//missing comment
		ZEPHIR_INIT_NVAR(methods);
		zephir_call_method(methods, route, "gethttpmethods");

		if (Z_TYPE_P(methods) == IS_NULL) {
			//missing comment
			if (Z_TYPE_P(request) == IS_NULL) {
				ZEPHIR_OBS_NVAR(dependencyInjector);
				zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);

				if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
					ZEPHIR_THROW_EXCEPTION_STR(test_router_exception_ce, "A dependency injection container is required to access the 'request' service");
					return;
				}
				ZEPHIR_INIT_NVAR(request);
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_STRING(_7, "request", 1);
				zephir_call_method_p1(request, dependencyInjector, "getshared", _7);

			}
			//missing comment
			ZEPHIR_INIT_NVAR(_8);
			zephir_call_method_p1(_8, request, "ismethod", methods);
			if (ZEPHIR_IS_FALSE(_8)) {
				continue;
			}
		}
		//missing comment
		ZEPHIR_INIT_NVAR(hostname);
		zephir_call_method(hostname, route, "gethostname");

		if (Z_TYPE_P(hostname) == IS_NULL) {
			//missing comment
			if (Z_TYPE_P(request) == IS_NULL) {
				ZEPHIR_OBS_NVAR(dependencyInjector);
				zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);

				if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
					ZEPHIR_THROW_EXCEPTION_STR(test_router_exception_ce, "A dependency injection container is required to access the 'request' service");
					return;
				}
				ZEPHIR_INIT_NVAR(request);
				ZEPHIR_INIT_NVAR(_9);
				ZVAL_STRING(_9, "request", 1);
				zephir_call_method_p1(request, dependencyInjector, "getshared", _9);

			}
			//missing comment
			if (Z_TYPE_P(currentHostName) != IS_OBJECT) {
				ZEPHIR_INIT_NVAR(currentHostName);
				zephir_call_method(currentHostName, request, "gethttphost");

			}
			//missing comment
			if (Z_TYPE_P(currentHostName) != IS_NULL) {
				continue;
			}
			//missing comment
			ZEPHIR_INIT_NVAR(_10);
			ZEPHIR_INIT_NVAR(_11);
			ZVAL_STRING(_11, "(", 1);
			zephir_call_func_p2(_10, "memchr", hostname, _11);
			if (zend_is_true(_10)) {
				ZEPHIR_INIT_NVAR(_12);
				ZEPHIR_INIT_NVAR(_13);
				ZVAL_STRING(_13, "#", 1);
				zephir_call_func_p2(_12, "memchr", hostname, _13);
				if (zend_is_true(_12)) {

					ZEPHIR_INIT_NVAR(regexHostName);
					ZVAL_NULL(regexHostName);

				} else {

					ZEPHIR_CPY_WRT(regexHostName, hostname);

				}
				ZEPHIR_INIT_NVAR(matched);
				zephir_call_func_p2(matched, "preg_match", regexHostName, currentHostName);

			} else {

				ZEPHIR_INIT_NVAR(matched);
				ZVAL_BOOL(matched, ZEPHIR_IS_EQUAL(currentHostName, hostname));

			}
			if (!(zend_is_true(matched))) {
				continue;
			}
		}
		//missing comment
		ZEPHIR_INIT_NVAR(pattern);
		zephir_call_method(pattern, route, "getcompiledpattern");

		ZEPHIR_INIT_NVAR(_14);
		ZEPHIR_INIT_NVAR(_15);
		ZVAL_STRING(_15, "^", 1);
		zephir_call_func_p2(_14, "memchr", pattern, _15);
		if (zend_is_true(_14)) {
			ZEPHIR_INIT_NVAR(routeFound);
			zephir_call_func_p3(routeFound, "preg_match", pattern, handledUri, matches);

		} else {

			ZEPHIR_INIT_NVAR(routeFound);
			ZVAL_BOOL(routeFound, ZEPHIR_IS_EQUAL(pattern, handledUri));

		}
		//missing comment
		if (zend_is_true(routeFound)) {
			ZEPHIR_INIT_NVAR(beforeMatch);
			zephir_call_method(beforeMatch, route, "getbeforematch");

			if (Z_TYPE_P(beforeMatch) == IS_NULL) {
				//missing comment
				ZEPHIR_INIT_NVAR(_16);
				zephir_call_func_p1(_16, "is_callable", beforeMatch);
				if (zend_is_true(_16)) {
					ZEPHIR_THROW_EXCEPTION_STR(test_router_exception_ce, "Before-Match callback is not callable in matched route");
					return;
				}
				//missing comment
				//missing comment
			}
		}
		if (zend_is_true(routeFound)) {
			//missing comment
			ZEPHIR_INIT_NVAR(paths);
			zephir_call_method(paths, route, "getpaths");

			ZEPHIR_CPY_WRT(parts, paths);

			//missing comment
			if (Z_TYPE_P(matches) != IS_ARRAY) {
				//missing comment
				ZEPHIR_INIT_NVAR(converters);
				zephir_call_method(converters, route, "getconverters");

				zephir_is_iterable(paths, &_18, &_17, 0, 1);
				while (zend_hash_get_current_data_ex(_18, (void**) &_19, &_17) == SUCCESS) {
					ZEPHIR_GET_HKEY(part, _18, _17);
					ZEPHIR_GET_HVALUE(position, _19);
					ZEPHIR_OBS_NVAR(matchPosition);
					if (zephir_array_isset(matches, position)) {
						//missing comment
						if (Z_TYPE_P(converters) == IS_ARRAY) {
							if (zephir_array_isset(converters, part)) {
								//missing comment
								//missing comment
								//missing comment
								//missing comment
								continue;
							}
						}
						//missing comment

						zephir_array_update_zval(&parts, part, &matchPosition, PH_COPY | PH_SEPARATE);

					} else {
						//missing comment
						if (Z_TYPE_P(converters) == IS_ARRAY) {
							if (zephir_array_isset(converters, part)) {
								//missing comment
								//missing comment
								//missing comment
								//missing comment
							}
						}
					}
				}
				//missing comment

				zephir_update_property_zval(this_ptr, SL("_matches"), matches TSRMLS_CC);

			}

			zephir_update_property_zval(this_ptr, SL("_matchedRoute"), route TSRMLS_CC);

			break;
		}
	}
	//missing comment
	if (zend_is_true(routeFound)) {

		ZEPHIR_INIT_VAR(_20);
		zephir_update_property_zval(this_ptr, SL("_wasMatched"), _20 TSRMLS_CC);

	} else {

		ZEPHIR_INIT_VAR(_21);
		zephir_update_property_zval(this_ptr, SL("_wasMatched"), _21 TSRMLS_CC);

	}
	//missing comment
	if (!(zend_is_true(routeFound))) {
		ZEPHIR_OBS_VAR(notFoundPaths);
		zephir_read_property(&notFoundPaths, this_ptr, SL("_notFoundPaths"), PH_NOISY_CC);

		if (Z_TYPE_P(notFoundPaths) == IS_NULL) {

			ZEPHIR_CPY_WRT(parts, notFoundPaths);

			ZEPHIR_INIT_NVAR(routeFound);
			ZVAL_BOOL(routeFound, 1);

		}
	}
	if (zend_is_true(routeFound)) {
		//missing comment
		ZEPHIR_OBS_VAR(vnamespace);
		if (zephir_array_isset_string(parts, SS("namespace"))) {
			ZEPHIR_INIT_VAR(_22);
			zephir_call_func_p1(_22, "is_numeric", vnamespace);
			if (!(zend_is_true(_22))) {

				zephir_update_property_zval(this_ptr, SL("_namespace"), vnamespace TSRMLS_CC);

			}
			//missing unset
		} else {
			ZEPHIR_OBS_VAR(_23);
			zephir_read_property(&_23, this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);

			zephir_update_property_zval(this_ptr, SL("_namespace"), _23 TSRMLS_CC);

		}
		//missing comment
		ZEPHIR_OBS_VAR(module);
		if (zephir_array_isset_string(parts, SS("module"))) {
			ZEPHIR_INIT_VAR(_24);
			zephir_call_func_p1(_24, "is_numeric", module);
			if (!(zend_is_true(_24))) {

				zephir_update_property_zval(this_ptr, SL("_module"), module TSRMLS_CC);

			}
			//missing unset
		} else {
			ZEPHIR_OBS_VAR(_25);
			zephir_read_property(&_25, this_ptr, SL("_defaultModule"), PH_NOISY_CC);

			zephir_update_property_zval(this_ptr, SL("_module"), _25 TSRMLS_CC);

		}
		//missing comment
		ZEPHIR_OBS_VAR(controller);
		if (zephir_array_isset_string(parts, SS("controller"))) {
			ZEPHIR_INIT_VAR(_26);
			zephir_call_func_p1(_26, "is_numeric", controller);
			if (!(zend_is_true(_26))) {

				zephir_update_property_zval(this_ptr, SL("_controller"), controller TSRMLS_CC);

			}
			//missing unset
		} else {
			ZEPHIR_OBS_VAR(_27);
			zephir_read_property(&_27, this_ptr, SL("_defaultController"), PH_NOISY_CC);

			zephir_update_property_zval(this_ptr, SL("_controller"), _27 TSRMLS_CC);

		}
		//missing comment
		ZEPHIR_OBS_VAR(action);
		if (zephir_array_isset_string(parts, SS("action"))) {
			ZEPHIR_INIT_VAR(_28);
			zephir_call_func_p1(_28, "is_numeric", action);
			if (!(zend_is_true(_28))) {

				zephir_update_property_zval(this_ptr, SL("_action"), action TSRMLS_CC);

			}
			//missing unset
		} else {
			ZEPHIR_OBS_VAR(_29);
			zephir_read_property(&_29, this_ptr, SL("_defaultAction"), PH_NOISY_CC);

			zephir_update_property_zval(this_ptr, SL("_action"), _29 TSRMLS_CC);

		}
		//missing comment
		ZEPHIR_OBS_VAR(paramsStr);
		if (zephir_array_isset_string(parts, SS("params"))) {
			ZEPHIR_INIT_VAR(strParams);
			ZEPHIR_INIT_VAR(_30);
			ZVAL_LONG(_30, 1);
			zephir_call_func_p2(strParams, "substr", paramsStr, _30);

			if (zend_is_true(strParams)) {
				ZEPHIR_INIT_NVAR(params);
				ZEPHIR_INIT_VAR(_31);
				ZVAL_STRING(_31, "/", 1);
				zephir_call_func_p2(params, "explode", _31, strParams);

			}
			//missing unset
		}
		if (zephir_fast_count_ev(params TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(paramsMerge);
			zephir_call_func_p2(paramsMerge, "array_merge", params, parts);

		} else {

			ZEPHIR_CPY_WRT(paramsMerge, parts);

		}

		zephir_update_property_zval(this_ptr, SL("_params"), paramsMerge TSRMLS_CC);

	} else {
		//missing comment
		ZEPHIR_OBS_VAR(_32);
		zephir_read_property(&_32, this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);

		zephir_update_property_zval(this_ptr, SL("_namespace"), _32 TSRMLS_CC);

		ZEPHIR_OBS_VAR(_33);
		zephir_read_property(&_33, this_ptr, SL("_defaultModule"), PH_NOISY_CC);

		zephir_update_property_zval(this_ptr, SL("_module"), _33 TSRMLS_CC);

		ZEPHIR_OBS_VAR(_34);
		zephir_read_property(&_34, this_ptr, SL("_defaultController"), PH_NOISY_CC);

		zephir_update_property_zval(this_ptr, SL("_controller"), _34 TSRMLS_CC);

		ZEPHIR_OBS_VAR(_35);
		zephir_read_property(&_35, this_ptr, SL("_defaultAction"), PH_NOISY_CC);

		zephir_update_property_zval(this_ptr, SL("_action"), _35 TSRMLS_CC);

		ZEPHIR_OBS_VAR(_36);
		zephir_read_property(&_36, this_ptr, SL("_defaultParams"), PH_NOISY_CC);

		zephir_update_property_zval(this_ptr, SL("_params"), _36 TSRMLS_CC);

	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a route to the router without any HTTP constraint
 *
 *<code>
 * $router->add('/about', 'About::index');
 *</code>
 *
 * @param string pattern
 * @param string/array paths
 * @param string httpMethods
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router, add) {

	zval *pattern, *paths = NULL, *httpMethods = NULL, *route;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern, &paths, &httpMethods);

	if (!paths) {
		ZEPHIR_INIT_VAR(paths);
	}
	if (!httpMethods) {
		ZEPHIR_INIT_VAR(httpMethods);
	}


	//missing comment
	ZEPHIR_INIT_VAR(route);
	object_init_ex(route, test_router_route_ce);
	zephir_call_method_p3_noret(route, "__construct", pattern, paths, httpMethods);

	//missing object-property-append

	RETURN_CCTOR(route);


}

/**
 * Adds a route to the router that only match if the HTTP method is GET
 *
 * @param string pattern
 * @param string/array paths
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router, addGet) {

	zval *pattern, *paths = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern, &paths);

	if (!paths) {
		ZEPHIR_INIT_VAR(paths);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "GET", 1);
	zephir_call_method_p3(_0, this_ptr, "add", pattern, paths, _1);
	RETURN_CCTOR(_0);


}

/**
 * Adds a route to the router that only match if the HTTP method is POST
 *
 * @param string pattern
 * @param string/array paths
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router, addPost) {

	zval *pattern, *paths = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern, &paths);

	if (!paths) {
		ZEPHIR_INIT_VAR(paths);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "POST", 1);
	zephir_call_method_p3(_0, this_ptr, "add", pattern, paths, _1);
	RETURN_CCTOR(_0);


}

/**
 * Adds a route to the router that only match if the HTTP method is PUT
 *
 * @param string pattern
 * @param string/array paths
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router, addPut) {

	zval *pattern, *paths = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern, &paths);

	if (!paths) {
		ZEPHIR_INIT_VAR(paths);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "PUT", 1);
	zephir_call_method_p3(_0, this_ptr, "add", pattern, paths, _1);
	RETURN_CCTOR(_0);


}

/**
 * Adds a route to the router that only match if the HTTP method is PATCH
 *
 * @param string pattern
 * @param string/array paths
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router, addPatch) {

	zval *pattern, *paths = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern, &paths);

	if (!paths) {
		ZEPHIR_INIT_VAR(paths);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "PATCH", 1);
	zephir_call_method_p3(_0, this_ptr, "add", pattern, paths, _1);
	RETURN_CCTOR(_0);


}

/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 *
 * @param string pattern
 * @param string/array paths
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router, addDelete) {

	zval *pattern, *paths = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern, &paths);

	if (!paths) {
		ZEPHIR_INIT_VAR(paths);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "DELETE", 1);
	zephir_call_method_p3(_0, this_ptr, "add", pattern, paths, _1);
	RETURN_CCTOR(_0);


}

/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 *
 * @param string pattern
 * @param string/array paths
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router, addOptions) {

	zval *pattern, *paths = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern, &paths);

	if (!paths) {
		ZEPHIR_INIT_VAR(paths);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "OPTIONS", 1);
	zephir_call_method_p3(_0, this_ptr, "add", pattern, paths, _1);
	RETURN_CCTOR(_0);


}

/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 *
 * @param string pattern
 * @param string/array paths
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router, addHead) {

	zval *pattern, *paths = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern, &paths);

	if (!paths) {
		ZEPHIR_INIT_VAR(paths);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "HEAD", 1);
	zephir_call_method_p3(_0, this_ptr, "add", pattern, paths, _1);
	RETURN_CCTOR(_0);


}

/**
 * Mounts a group of routes in the router
 *
 * @param Test\Router\Group route
 * @return Test\Router
 */
PHP_METHOD(Test_Router, mount) {

	HashTable *_1, *_5;
	HashPosition _0, _4;
	zval *group, *groupRoutes, *beforeMatch, *hostname, *routes, *route, **_2, *_3 = NULL, **_6, *_7 = NULL, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group);



	if (Z_TYPE_P(group) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_STR(test_router_exception_ce, "The group of routes is not valid");
		return;
	}
	ZEPHIR_INIT_VAR(groupRoutes);
	zephir_call_method(groupRoutes, group, "getroutes");

	if (!(zephir_fast_count_ev(groupRoutes TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(test_router_exception_ce, "The group of routes does not contain any routes");
		return;
	}
	//missing comment
	ZEPHIR_INIT_VAR(beforeMatch);
	zephir_call_method(beforeMatch, group, "getbeforematch");

	if (Z_TYPE_P(beforeMatch) == IS_NULL) {
		zephir_is_iterable(groupRoutes, &_1, &_0, 0, 1);
		while (zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS) {
			ZEPHIR_GET_HVALUE(route, _2);
			ZEPHIR_INIT_NVAR(_3);
			zephir_call_method_p1(_3, route, "beforematch", beforeMatch);
		}
	}
	//missing comment
	ZEPHIR_INIT_VAR(hostname);
	zephir_call_method(hostname, group, "gethostname");

	if (Z_TYPE_P(hostname) == IS_NULL) {
		zephir_is_iterable(groupRoutes, &_5, &_4, 0, 1);
		while (zend_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS) {
			ZEPHIR_GET_HVALUE(route, _6);
			ZEPHIR_INIT_NVAR(_7);
			zephir_call_method_p1(_7, route, "sethostname", hostname);
		}
	}
	ZEPHIR_OBS_VAR(routes);
	zephir_read_property(&routes, this_ptr, SL("_routes"), PH_NOISY_CC);

	if (Z_TYPE_P(routes) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_8);
		zephir_call_func_p2(_8, "array_merge", routes, groupRoutes);

		zephir_update_property_zval(this_ptr, SL("_routes"), _8 TSRMLS_CC);

	} else {

		zephir_update_property_zval(this_ptr, SL("_routes"), groupRoutes TSRMLS_CC);

	}

	RETURN_THIS();


}

/**
 * Set a group of paths to be returned when none of the defined routes are matched
 *
 * @param array paths
 * @return Test\Router
 */
PHP_METHOD(Test_Router, notFound) {

	zval *paths;

	zephir_fetch_params(0, 1, 0, &paths);



	if (Z_TYPE_P(paths) != IS_ARRAY) {
		if (Z_TYPE_P(paths) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_STRW(test_router_exception_ce, "The not-found paths must be an array or string");
			return;
		}
	}

	zephir_update_property_zval(this_ptr, SL("_notFoundPaths"), paths TSRMLS_CC);

	RETURN_THISW();


}

/**
 * Removes all the pre-defined routes
 */
PHP_METHOD(Test_Router, clear) {

	zval *_0;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_zval(this_ptr, SL("_routes"), _0 TSRMLS_CC);

	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the processed namespace name
 *
 * @return string
 */
PHP_METHOD(Test_Router, getNamespaceName) {

	RETURN_MEMBER(this_ptr, "_namespace");

}

/**
 * Returns the processed module name
 *
 * @return string
 */
PHP_METHOD(Test_Router, getModuleName) {

	RETURN_MEMBER(this_ptr, "_module");

}

/**
 * Returns the processed controller name
 *
 * @return string
 */
PHP_METHOD(Test_Router, getControllerName) {

	RETURN_MEMBER(this_ptr, "_controller");

}

/**
 * Returns the processed action name
 *
 * @return string
 */
PHP_METHOD(Test_Router, getActionName) {

	RETURN_MEMBER(this_ptr, "_action");

}

/**
 * Returns the processed parameters
 *
 * @return array
 */
PHP_METHOD(Test_Router, getParams) {

	RETURN_MEMBER(this_ptr, "_params");

}

/**
 * Returns the route that matchs the handled URI
 *
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router, getMatchedRoute) {

	RETURN_MEMBER(this_ptr, "_matchedRoute");

}

/**
 * Returns the sub expressions in the regular expression matched
 *
 * @return array
 */
PHP_METHOD(Test_Router, getMatches) {

	RETURN_MEMBER(this_ptr, "_matches");

}

/**
 * Checks if the router macthes any of the defined routes
 *
 * @return bool
 */
PHP_METHOD(Test_Router, wasMatched) {

	RETURN_MEMBER(this_ptr, "_wasMatched");

}

/**
 * Returns all the routes defined in the router
 *
 * @return Test\Router\Route[]
 */
PHP_METHOD(Test_Router, getRoutes) {

	RETURN_MEMBER(this_ptr, "_routes");

}

/**
 * Returns a route object by its id
 *
 * @param string id
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router, getRouteById) {

	HashTable *_2;
	HashPosition _1;
	zval *id, *route, *_0, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, this_ptr, SL("_routes"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 1);
	while (zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS) {
		ZEPHIR_GET_HVALUE(route, _3);
		ZEPHIR_INIT_NVAR(_4);
		zephir_call_method(_4, route, "getrouteid");
		if (ZEPHIR_IS_EQUAL(_4, id)) {

			RETURN_CCTOR(route);

		}
	}

	RETURN_MM_BOOL(0);


}

/**
 * Returns a route object by its name
 *
 * @param string name
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router, getRouteByName) {

	HashTable *_2;
	HashPosition _1;
	zval *name, *route, *_0, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, this_ptr, SL("_routes"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 1);
	while (zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS) {
		ZEPHIR_GET_HVALUE(route, _3);
		ZEPHIR_INIT_NVAR(_4);
		zephir_call_method(_4, route, "getname");
		if (ZEPHIR_IS_EQUAL(_4, name)) {

			RETURN_CCTOR(route);

		}
	}

	RETURN_MM_BOOL(0);


}

