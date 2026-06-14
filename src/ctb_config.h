/**
 * @file
 * @brief User-configurable settings for the ctb library.
 *
 * This header provides safe default definitions for all ctb configurables.
 * Users may place their own `ctb_config.h` earlier in the include path to
 * override these defaults without modifying the library source.
 */
#ifndef CTB_CONFIG_H
#define CTB_CONFIG_H

#include <assert.h>

/**
 * @brief Runtime assertion macro.
 *
 * Defaults to the standard `assert()` macro. Users may define this before
 * including this header to use a custom handler or no-op in constrained
 * environments.
 */
#ifndef ctb_config_assert
#define ctb_config_assert(expr) assert(expr)
#endif

/**
 * @brief Compile-time (static) assertion macro.
 *
 * Defaults to the typedef-char trick which works in C99 without requiring
 * `_Static_assert`. Users may define this before including this header to
 * use a different mechanism (e.g., `_Static_assert` in C11).
 *
 * @param expr  Compile-time integer expression that must evaluate to non-zero.
 * @param id    Unique identifier used to name the internal typedef.
 */
#ifndef ctb_config_staticAssert
#define ctb_config_staticAssert(expr, id) \
    typedef char id[(!!(expr)) * 2 - 1]
#endif

#endif /* CTB_CONFIG_H */
