/* 对应教材 S4.3 编写一个计算器程序 
   part_4 编写 getch 和 ungetch 函数 */
#include <stdio.h>
#define BUFSIZE 100     // 缓冲区长度

void Exit(int x, char *fmt, ...);
char buf[BUFSIZE];
int bufp = 0;

/* getch 函数 从 stdin 中读入一个字符 */   
int getch(void) {
    return (bufp == 0) ? getchar() : buf[--bufp];
}

/* ungetch 函数 将一个字符返回缓冲区 */
void ungetch(char c) {
    if (bufp == BUFSIZE)        Exit(1, "error: buff overflow\n");        // 缓冲区满
    buf[bufp++] = c;
}