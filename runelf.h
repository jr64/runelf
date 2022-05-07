#define _GNU_SOURCE
#include <sys/types.h>
#include <fcntl.h>

#define ERR_MEMFD_CREATE 10
#define ERR_READ 11
#define ERR_WRITE 12
#define ERR_EXECVEAT 13
#define BUFSIZE 1024*64
#define NULL ((void *)0)