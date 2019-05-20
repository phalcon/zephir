#ifndef ZEPHIR_KERNEL_FCALL_INTERNAL_H
#define ZEPHIR_KERNEL_FCALL_INTERNAL_H
	#define ZEPHIR_CALL_INTERNAL_METHOD_P0(return_value_ptr, object, method) \
		do { \
			ZEPHIR_BACKUP_SCOPE(); \
			ZEPHIR_BACKUP_THIS_PTR(); \
			ZEPHIR_SET_THIS(object); \
			ZEPHIR_SET_SCOPE((Z_OBJ_P(object) ? Z_OBJCE_P(object) : NULL), (Z_OBJ_P(object) ? Z_OBJCE_P(object) : NULL)); \
			ZEPHIR_INIT_VAR((return_value_ptr)); \
			method(0, return_value_ptr, object, 1); \
			ZEPHIR_LAST_CALL_STATUS = EG(exception) ? FAILURE : SUCCESS; \
			ZEPHIR_RESTORE_THIS_PTR(); \
			ZEPHIR_RESTORE_SCOPE(); \
		} while (0)
	
	#define ZEPHIR_CALL_INTERNAL_METHOD_P2(return_value_ptr, object, method, p0, p1) \
		do { \
			ZEPHIR_BACKUP_SCOPE(); \
			ZEPHIR_BACKUP_THIS_PTR(); \
			ZEPHIR_SET_THIS(object); \
			ZEPHIR_SET_SCOPE((Z_OBJ_P(object) ? Z_OBJCE_P(object) : NULL), (Z_OBJ_P(object) ? Z_OBJCE_P(object) : NULL)); \
			zval _p0, _p1; \
			ZEPHIR_INIT_VAR((return_value_ptr)); \
			ZVAL_COPY(&_p0, p0); \
			ZVAL_COPY(&_p1, p1); \
			method(0, return_value_ptr, object, 1, &_p0, &_p1); \
			Z_TRY_DELREF_P(p0); \
			Z_TRY_DELREF_P(p1); \
			ZEPHIR_LAST_CALL_STATUS = EG(exception) ? FAILURE : SUCCESS; \
			ZEPHIR_RESTORE_THIS_PTR(); \
			ZEPHIR_RESTORE_SCOPE(); \
		} while (0)
	
#endif
