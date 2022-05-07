#include "syscalls.h"

void sc_exit(int status) {
    register int64_t rax __asm__ ("rax") = SYS_exit;
    register int rdi __asm__ ("rdi") = status;

    __asm__ __volatile__ (
        "syscall"
        : "+r" (rax)
        : "r" (rdi)
        : "rcx", "r11", "memory"
    );
}

ssize_t sc_write(int fd, const void *buf, size_t n){
    register int64_t rax __asm__ ("rax") = SYS_write;
    register int rdi __asm__ ("rdi") = fd;
    register const void *rsi __asm__ ("rsi") = buf;
    register size_t rdx __asm__ ("rdx") = n;

    __asm__ __volatile__ (
        "syscall"
        : "+r" (rax)
        : "r" (rdi), "r"(rsi), "r"(rdx)
        : "rcx", "r11", "memory"
    );

    return rax;
} 

ssize_t sc_read(int fd, void *buf, size_t n){
    register int64_t rax __asm__ ("rax") = SYS_read;
    register int rdi __asm__ ("rdi") = fd;
    register void *rsi __asm__ ("rsi") = buf;
    register size_t rdx __asm__ ("rdx") = n;

    __asm__ __volatile__ (
        "syscall"
        : "+r" (rax)
        : "r" (rdi), "r"(rsi), "r"(rdx)
        : "rcx", "r11", "memory"
    );

    return rax;
} 

int sc_memfd_create(const char *name, unsigned int flags){
    register int64_t rax __asm__ ("rax") = SYS_memfd_create;
    register const char *rdi __asm__ ("rdi") = name;
    register unsigned int rsi __asm__ ("rsi") = flags;

    __asm__ __volatile__ (
        "syscall"
        : "+r" (rax)
        : "r" (rdi), "r"(rsi)
        : "rcx", "r11", "memory"
    );

    return rax;
} 

int sc_execveat(int dirfd, const char *pathname, const char *const arg[], const char *const env[], int flags){
    register int64_t rax __asm__ ("rax") = SYS_execveat;
    register int rdi __asm__ ("rdi") = dirfd;
    register const char *rsi __asm__ ("rsi") = pathname;
    register const char *const* rdx __asm__ ("rdx") = arg;
    register const char *const* r10 __asm__ ("r10") = env;
    register int r8 __asm__ ("r8") = flags;

    __asm__ __volatile__ (
        "syscall"
        : "+r" (rax)
        : "r" (rdi), "r"(rsi), "r"(rdx), "r"(r10), "r"(r8)
        : "rcx", "r11", "memory"
    );

    return rax;

} 