/**
 * @file
 */
#ifndef CTB_CONFIG_H
#define CTB_CONFIG_H

#include <assert.h>

/**
 * @brief User-overridable runtime assertion macro
 *
 * Defaults to the standard assert() macro. Users may define their own
 * ctb_config.h earlier in the include path to override this.
 */
#define ctb_config_assert( \
    expr                   \
)                          \
    assert(expr)

/**
 * @brief User-overridable compile-time assertion macro
 *
 * Defaults to the typedef char trick. Users may define their own
 * ctb_config.h earlier in the include path to override this.
 *
 * @param expr Compile-time constant expression expected to be true
 * @param id   Unique identifier for the typedef
 */
#define ctb_config_staticAssert( \
    expr,                        \
    id                           \
)                                \
    typedef char id[(!!(expr)) * 2 - 1]

#endif // CTB_CONFIG_H
