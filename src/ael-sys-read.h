#ifndef AEL_SYS_READ_H_
#define AEL_SYS_READ_H_

#include "ael-sys-base.h"

typedef struct ael_sys_reader_error {
    usize code;
    usize msg_len;
    u8 *const msg;
} ael_sys_reader_error;

typedef struct ael_sys_reader_state {
    usize total_char;
    usize cur_line;
    usize cur_offset;
} ael_sys_reader_state;

typedef struct ael_sys_reader {
    ael_sys_sexp (*next)(struct ael_sys_reader*);
    ael_sys_bool (*has_next)(struct ael_sys_reader*);
    ael_sys_bool (*has_error)(struct ael_sys_reader*, ael_sys_reader_error *into);
    void (*state)(struct ael_sys_reader*, ael_sys_reader_state *into);
} ael_sys_reader;

// caller owns *su8 and *mem
ael_sys_reader *ael_sys_read(ael_sys_stream_u8 *su8, ael_sys_alloc *mem);

// all internal resources and *r are free'd with *mem
void ael_sys_reader_dispose(ael_sys_reader* r);

#endif
