/* 练习 8-1 通过 UNIX 系统提供的系统调用代替标准库中功能等价的函数 重写 CH7 的 P02 cat 程序 */
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void error(int x, char *fmt, ...);
void filecopy(int fd1, int fd2);

int main(int argc, char *argv[]) {
    int fd;

    if (argc == 1) {
        filecopy(1, 0);
        return 0;
    }
    while (--argc > 0) {
        if ((fd = open(*++argv, O_RDONLY, 0)) == -1)
            error(1, "cat: cannot read file %s\n", *argv);
        filecopy(1, fd);
        close(fd);
    }
    return 0;
}

/* 将文件 src 复制到文件 des 中 */
void filecopy(int des, int src) {
    char buf[BUFSIZ];
    int n;

    while ((n = read(src, buf, BUFSIZ)) > 0)
        if (write(des, buf, n) != n)
            error(1, "cat: write error\n");
}

/* 打印一个出错信息 然后终止程序 */
void error(int x, char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    exit(x);
}