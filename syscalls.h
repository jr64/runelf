#include <sys/types.h>
#include <sys/syscall.h>
#include <fcntl.h>

void sc_exit(int status);

ssize_t sc_write(int fd, const void *buf, size_t n);

ssize_t sc_read(int fd, void *buf, size_t n);

int sc_memfd_create(const char *name, unsigned int flags);

int sc_execveat(int dirfd, const char *pathname, const char *const arg[], const char *const env[], int flags);