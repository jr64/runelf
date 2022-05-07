#include "runelf.h"
#include "syscalls.h"

int main(int argc, const char **argv, const char **envp){

    int fd;
    ssize_t res;
    char buf[BUFSIZE]; 

    fd = sc_memfd_create("",0);
    if( fd < 0){
        return ERR_MEMFD_CREATE;
    } 

    do{
        res = sc_read(0, buf, BUFSIZE);
        if(res < 0){
            return ERR_READ;
        }
        res = sc_write(fd, buf, res);
        if(res < 0){
            return ERR_WRITE;
        }
    }while(res > 0);
   
    sc_execveat(fd,"",argv,envp,AT_EMPTY_PATH);

    return ERR_EXECVEAT;
} 

// entrypoint since libc is not linked
// simply convert args + envp passed on stack
// to arguments for main()
__asm__ (
    ".global _start                    \n"
    "_start:                           \n"
    "   xorq %rbp,%rbp                 \n"
    "   movq (%rsp),%rdi               \n" // argc
    "   leaq 8(%rsp),%rsi              \n" // argv
    "   leaq 16(%rsp,%rdi,8),%rdx      \n" // envp
    "   call main                      \n"
    "   movq %rax,%rdi                 \n"
    "   call sc_exit                   \n"
);
