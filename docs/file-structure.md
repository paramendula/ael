LICENSE
README.md
.gitignore
docs/ - documentation
docs/file-structure.md - describes what each file/dir does and means
src/ - source code
src/ael-sys-config.h - header containing config definitions changing ael-sys behavior
src/ael-sys-base.h - common header for ael-sys libraries and C code produced by ael-sys (runtime)
src/ael-sys-read.h - header with structs and functions related to reading Sexp external representations
src/ael-sys-read.c - implementation of ael-sys-read.h
src/ael-sys-error.h - header with functions and structs related to error/aborts/panic/mayhem/cataclysm/annihilation
src/ael-sys.h - header for ael-sys core library
src/ael-sys.c - implementation of ael-sys.h
src/ael-sys-exe.c - CLI executable for ael-sys, compiler toolchain, etc.
