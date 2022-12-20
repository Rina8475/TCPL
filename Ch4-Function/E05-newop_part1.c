/* 练习 4-5 修改计算器程序 使之允许新的操作
   part_1 更改 main 函数 使之能根据不同的输入进行不同的处理 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "E05-newop_part2.h"
#define MAXOP   100

void push(double f);        // 外部函数
double pop(void);
void Exit(char err[]);

double func(char s[]);

int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case NAME:
            push(func(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            if ((op2 = pop()) == 0)     Exit("zero divisor");
            push(pop() / op2);
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            fprintf(stderr, "error: unknown command %s\n", s);
            exit(1);
            break;
        }
}

/* 根据字符串 s 中的操作符不同 执行不同的操作 */
double func(char s[]) {
    double op2;

    if      (strcmp(s, "sin") == 0)  return sin(pop());
    else if (strcmp(s, "cos") == 0)  return cos(pop());
    else if (strcmp(s, "exp") == 0)  return exp(pop());
    else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        return pow(pop(), op2);
    } else {            // 未知函数
        fprintf(stderr, "error: unknown string %s", s);
        exit(1);
    }
}