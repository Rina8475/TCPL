/* 练习 4-8 假定最多只能压回一个字符 相应地修改 getch 和 ungetch 函数 */
#include <stdio.h>

void Exit(char err[]);
char buf = 0;

/* 从 stdin 中取一个字符 */
int getch(void) {
    int c = (buf == 0) ? getchar() : buf;
    buf = 0;
    return c;
}

/* 将字符压回缓冲区 */
void ungetch(char c) {
    if (buf != 0)   Exit("buf full");
    buf = c;
}