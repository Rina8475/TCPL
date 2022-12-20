/* 练习 5-1 改写 getint 函数
   应该算是通过测试了吧。。。 */
#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int c);

#ifdef TEST
#define SIZE 5

int main(void) {
    int array[SIZE], getint(int *);
    for (int n = 0; n < SIZE && getint(&array[n]) != EOF; n++);
    for (int i = 0; i < SIZE; i++)
        printf("%d ", array[i]);
}
#endif


/* 能够识别出单个的 + - 符号 并将其重新写回输入流 */
int getint(int *a) {
    int c, sign;

    while (isspace(c = getch()));       // 跳过空格符
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);         // 不是数字
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')   c = getch();
    if (!isdigit(c) && c != EOF) {
        ungetch(c);
        c = (sign == -1) ? '-' : '+';
        ungetch(c);         // 不是数字
        return 0;
    }

    for (*a = 0; isdigit(c); c = getch())
        *a = 10 * *a + c - '0';
    *a *= sign;
    if (c != EOF)   ungetch(c);
    return c;
}
