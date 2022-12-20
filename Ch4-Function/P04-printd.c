/* 对应于教材 S4.10 编写函数 printd */
#include <stdio.h>

/* printd函数 打印十进制数 n */
void printd(int n) {
    if (n == 0) return;
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    printd(n / 10);
    putchar(n % 10 + '0');
}