/* 练习 4-7 编写函数 ungets */
#include <stdio.h>
#define BUFSIZE 100

void Exit(char err[]);
int bufp = 0;
char buf[BUFSIZE];

/* 从 stdin 中取一个字符 */
int getch(void) {
    return (bufp == 0) ? getchar() : buf[--bufp];
}

/* 将字符压回缓冲区 */
void ungetch(char c) {
    if (bufp == BUFSIZE)    Exit("buf full");
    buf[bufp++] = c;
}

/* 将整个字符串 s 压回缓冲区 */
void ungets(char s[]) {
    while (*s != '\0')      ungetch(*(s++));
}