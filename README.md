# Runelf

Simple program to run ELF files directly from memory without writing them to disk first by using `memfd_create` and `execveat`.

Dependencies:

* should run on any Linux kernel >= 3.19 as long as the aforementioned syscalls are available
* this software does not depend on libc, syscalls are implemented directly

## Build

```sh
make
```

## Usage

Runelf reads the ELF file from stdin, all arguments as well as environment variables are passed on.

```sh
cat /bin/ps | ./runelf aux
```