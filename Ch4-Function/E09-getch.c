/* 练习 4-10 编写 getch 与 ungetch 函数 使之能正确处理压回的 EOF
   getch 与 ungetch 是在 P03 的基础上更改的 */
#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 100

static int buf[BUFSIZE];
static int bufp = 0;

/* getch 函数 从 stdin 中读入一个字符 */   
int getch(void) {
    return (bufp == 0) ? getchar() : buf[--bufp];
}

/* ungetch 函数 将一个字符返回缓冲区 */
void ungetch(int c) {
    if (bufp == BUFSIZE)  exit(1);
    buf[bufp++] = c;
}