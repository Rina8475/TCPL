/* 对应教材 S8.3 利用 UNIX 提供的系统接口编写 copy 程序 将一个文件的内容复制到另一个文件 */
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#define PERMS 0666

void error(int x, char *fmt, ...);

int main(int argc, char *argv[]) {
    char buf[BUFSIZ];
    int fd1, fd2, n;

    if (argc != 3)      error(1, "Usage: cp from to\n");
    if ((fd1 = open(argv[1], O_RDONLY, 0)) == -1)
        error(1, "cp: cannot open file %s\n", argv[1]);
    if ((fd2 = creat(argv[2], PERMS)) == -1)
        error(1, "cp: cannot creat file %s, mod %03o\n", argv[2], PERMS);
    while ((n = read(fd1, buf, BUFSIZ)) > 0)
        if (write(fd2, buf, n) != n)
            error(1, "cp: write error on file %s\n", argv[2]);
    return 0;
}

/* 打印一个出错信息 然后终止程序 */
void error(int x, char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    exit(x);
}