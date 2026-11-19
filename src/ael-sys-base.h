#ifndef AEL_SYS_BASE_H_
#define AEL_SYS_BASE_H_

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef intmax_t isize;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef uintmax_t usize;

typedef float f32;
typedef double f64;

typedef u8 ael_sys_bool;

#define AEL_SYS_TRUE ((u8)1)
#define AEL_SYS_FALSE ((u8)0)

// fat pointer
// if len=0, raw=NULL
typedef struct ael_sys_str {
    usize len;
    u8 *raw;
} ael_sys_str;

typedef struct ael_sys_node {
    struct ael_sys_sexp *head, *tail; // car, cdr
} ael_sys_node;

typedef enum ael_sys_sexp_type {
    sexpNil, // Nil
    sexpNode,// Linked List; Cons
    sexpInt8, // Integer i8
    sexpInt16, // Integer i16
    sexpInt32, // Integer i32
    sexpInt64, // Integer i64
    sexpIsize, // Integer isize (host-dependent)
    sexpUint8, // Unsigned Integer i8
    sexpUint16, // Unsigned Integer i16
    sexpUint32, // Unsigned Integer i32
    sexpUint64, // Unsigned Integer i64
    sexpUsize, // Unsigned Integer usize (host-dependent)
    sexpFloat32,// Floating Point 32 bit
    sexpFloat64,// Floating Point 64 bit
    sexpBool,// Boolean
    sexpStr, // String
    sexpSym, // Symbol
    sexpKey, // Keyword
} ael_sys_sexp_type;

// tagged union
typedef struct ael_sys_sexp {
    ael_sys_sexp_type t;
    union {
        ael_sys_node *node; // sexpNode
        i8 i8; // sexpInt8
        i16 i16; // sexpInt16
        i32 i32; // sexpInt32
        i64 i64; // sexpInt64
        isize isize; // sexpIsize
        u8 u8; // sexpUint8
        u16 u16; // sexpUint16
        u32 u32; // sexpUint32
        u64 u64; // sexpUint64
        usize usize; // sexpUsize
        f32 f32; // sexpFloat32
        f64 f64; // sexpFloat64
        ael_sys_bool bln; // sexpBool
        ael_sys_str str, sym, key; // sexpStr, sexpSym, sexpKey
    };
} ael_sys_sexp;

#endif