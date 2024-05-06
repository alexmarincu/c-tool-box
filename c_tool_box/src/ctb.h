/*----------------------------------------------------------------------------*/
#ifndef CTB_H
#define CTB_H
/*----------------------------------------------------------------------------*/
#define ctb_arr(itemType, length) \
    ((itemType[length]){ 0 })
/*----------------------------------------------------------------------------*/
#define ctb_obj(type) \
    ((type){ 0 })
/*----------------------------------------------------------------------------*/
#define ctb_lengthOf(arr) \
    (sizeof(arr) / sizeof(arr[0]))
/*----------------------------------------------------------------------------*/
#define ctb_containerOf(ptr, type, member) \
    ((type *)((char *)(ptr)-offsetof(type, member)))

// #ifdef __GNUC__
// #define member_type(type, member) __typeof__ (((type *)0)->member)
// #else
// #define member_type(type, member) const void
// #endif

// #define container_of(ptr, type, member) ((type *)((char *)(member_type(type, member) *){ ptr } - offsetof(type, member)))

/*----------------------------------------------------------------------------*/
#define ctb_staticAssert(expression, identifier) \
    typedef char identifier[(!!(expression)) * 2 - 1]

#endif // CTB_H
