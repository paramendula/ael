#ifndef AEL_SYS_READ_H
#define AEL_SYS_READ_H

#include "ael-sys-read.h"

// internal implementation
typedef struct ael_sys_rr {
    ael_sys_sexp (*next)(struct ael_sys_reader*);
    ael_sys_bool (*has_next)(struct ael_sys_reader*);
    ael_sys_bool (*has_error)(struct ael_sys_reader*, ael_sys_reader_error *into);
    void (*state)(struct ael_sys_reader*, ael_sys_reader_state *into);
    //
    ael_sys_stream_u8 *su8;
    ael_sys_alloc *mem;
    //
    usize total_char;
    usize cur_line;
    usize cur_offset;
} ael_sys_rr;

void ael_sys_rr_state(ael_sys_rr *rr, ael_sys_reader_state *into) {
    into->total_char = rr->total_char;
    into->cur_line = rr->cur_line;
    into->cur_offset = rr->cur_offset;
}

ael_sys_reader *ael_sys_read(ael_sys_stream_u8 *su8, ael_sys_alloc *mem) {
    if (!su8 || !mem) {
        return NULL;
    }

    ael_sys_rr *rr = mem->alloc(mem, sizeof(*rr));
    if(!rr) return NULL;

    rr->state = (void*)ael_sys_rr_state;

    rr->total_char = 0;
    rr->cur_line = 0;
    rr->cur_offset = 0;

    return (ael_sys_reader *)rr;
}

void ael_sys_reader_dispose(ael_sys_reader* r) {
    ael_sys_rr *rr = (ael_sys_rr *)r;
    ael_sys_alloc *mem = rr->mem;

    mem->free(mem, rr);
}

#endif
