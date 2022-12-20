/* 练习 5-2 编写 getfloat 函数 */
#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int c);

#ifdef TEST
#define SIZE 5

int main(void) {
    double array[SIZE];
    int getfloat(double *);

    for (int n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++);
    for (int i = 0; i < SIZE; i++)
        printf("%lf ", array[i]);
}
#endif

/* 将输入中的下一个浮点数赋值给 *a */
int getfloat(double *a) {
    int c, sign;
    double pow = 1.0;

    while (isspace(c = getch()));
    if (!isdigit(c) && c != '.' && c != EOF && c != '-' && c != '+') {
        ungetch(c);             // not a number
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+')   c = getch();
    for (*a = 0.0; isdigit(c); c = getch())         // 整数部分
        *a = *a * 10.0 + c - '0';
    if (c == '.')
        for (; isdigit(c = getch()); pow *= 10.0)
            *a = *a * 10.0 + c - '0';
    *a = sign * *a / pow;
    if (c != EOF)   ungetch(c);
    return c;
}