/* 对应教材 S5.2 编写函数 getint 
   scanf 以相同的方式实现 */
#include <stdio.h>
#include <ctype.h>

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

/* 将输入中的下一个整型数赋值给 *a 
   输入流中 对应的数字之前允许若干个空白符 */
int getint(int *a) {
    int c, sign;

    while (isspace(c = getch()));       // 跳过空白符
    if (!isdigit(c) && c != EOF && c != '-' && c != '+') {
        ungetch(c);             // 不是一个数字
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+')   c = getch();
    for (*a = 0; isdigit(c); c = getch())
        *a = 10 * *a + c - '0';
    *a *= sign;
    if (c != EOF)   ungetch(c);
    return c;                   // EOF 从这里返回
}