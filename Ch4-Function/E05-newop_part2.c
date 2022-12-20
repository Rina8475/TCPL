/* 练习 4-5 修改计算器程序 使之允许新的操作
   part_2 修改 getop 函数 是指能够识别输入中的字符串 */
#include <ctype.h>
#include "E05-newop_part2.h"

int getch(void);
void ungetch(char c);

/* getop 函数 获取下一个运算符或数值操作符
   首先跳过空格与制表符 如果下一个字符不是数字或小数点或字母 则返回
   如果是数字或小数点 则把这些数字字符收集起来 并返回 NUMBER
   如果是字母 则把这些字母字符全部收集起来 并返回 FUNCTION */
int getop(char s[]) {
    int c, i = 0;

    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isalpha(c) && !isdigit(c) && c != '.')     return c;

    if (isalpha(c)) {           // 收集函数名
        while (isalpha(s[++i] = c = getch()));
        s[i] = '\0';
        ungetch(c);
        return NAME;
    }

    if (isdigit(c))             // 收集数字
        while (isdigit(s[++i] = c = getch()));
    if (c == '.')
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    ungetch(c);
    return NUMBER;
}