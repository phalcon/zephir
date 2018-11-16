
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Test_Integration_Psr_Http_Message_MessageInterfaceEx) {

	ZEPHIR_REGISTER_INTERFACE(Test\\Integration\\Psr\\Http\\Message, MessageInterfaceEx, test, integration_psr_http_message_messageinterfaceex, NULL);

	zend_class_implements(test_integration_psr_http_message_messageinterfaceex_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("psr\\http\\message\\messageinterface")));
	return SUCCESS;

}

