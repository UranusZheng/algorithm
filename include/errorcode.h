#ifndef _ERRORCODE_H_
#define _ERRORCODE_H_

typedef enum ret_error_type_e {
    RET_OK = 0U,             /* 执行结果正确 */
    RET_ERROR = 1U,          /* 执行结果错误 */
    RET_E_NO_MEMORY = 2U,    /* 内存申请失败 */
    RET_E_PARAM = 3U,        /* 参数错误 */
    RET_E_FULL = 4U,         /* 资源池满 */
    RET_E_EMPTY = 5U,        /* 资源池空 */
    RET_E_EXIT = 6U,         /* 资源已存在 */
    RET_E_NOT_EXIT = 7U,     /* 资源不存在 */
    RET_E_NULL_PTR = 8U,      /* 空指针 */
    RET_E_NOT_SUPPORT = 9U,   /* 不支持 */
    RET_E_TIMEOUT = 10U,      /* 操作超时 */
    RET_E_INVALID = 11U,      /* 数据无效 */
} ret_error_type_t;

#endif /* _ERRORCODE_H_ */