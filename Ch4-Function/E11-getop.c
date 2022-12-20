/* 练习 4-11 修改 getop 函数 使之不使用 ungetch 函数 而是通过使用一个静态变量来作为代替
   getop 函数在 练习 4-5 的基础上修改 */
#include <stdio.h>
#include <ctype.h>
#include "E05-newop_part2.h"

/* getop 函数 获取下一个运算符或数值操作符
   首先跳过空格与制表符 如果下一个字符不是数字或小数点或字母 则返回
   如果是数字或小数点 则把这些数字字符收集起来 并返回 NUMBER
   如果是字母 则把这些字母字符全部收集起来 并返回 FUNCTION */
int getop(char s[]) {
    static int buf = ' ';
    int c, i = 0;
    if ((s[0] = c = buf) == ' ' || buf == '\t')
        while ((s[0] = c = getchar()) == ' ' || c == '\t');     // 跳过空格符
    s[1] = '\0';
    if (isalpha(c)) {
        while (isalpha(s[++i] = c = getchar()));
        s[i] = '\0';
        buf = c;
        return  NAME;
    }

    if (!isdigit(c) && c != '.')    return c;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getchar()));
    if (c == '.')
        while (isdigit(s[++i] = c = getchar()));
    s[i] = '\0';
    buf = c;
    return NUMBER;
}