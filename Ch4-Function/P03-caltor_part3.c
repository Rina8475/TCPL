/* 对应教材 S4.3 编写一个计算器程序 
   part_3 编写函数 getop */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#define NUMBER '0'

int getch(void);            // 外部函数声明
void ungetch(char c);

/* getop 函数 获取下一个运算符或数值操作符
   首先跳过空格与制表符 如果下一个字符不是数字或小数点 则返回
   否则把这些数字字符收集起来 并返回 NUMBER */
int getop(char s[]) {
    int c, i = 0;

    while ((s[0] = c = getch()) == ' ' || c == '\t');       // 跳过 space 与 \t  注意 isspace 函数判断是否是空白符 而不是仅判断 space 
    s[1] = '\0';            // 仰望高端玩家
    if (!isdigit(c) && c != '.')    return c;

    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()));              // 收集整数部分
    if (c == '.') 
        while (isdigit(s[++i] = c = getch()));              // 收集小数部分
    
    s[i] = '\0';
    ungetch(c);
    return NUMBER;
}

/* wraped function of exit */
void Exit(int x, char *fmt, ...) {
    va_list ap;

    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    exit(1);
}