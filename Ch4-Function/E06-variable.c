/* 练习 4-6 修改计算器程序 使其能够提供一个变量用于存放最近打印的值
   此处固定该变量名为 ans 此程序仅修改 main 函数 在练习 4-5 的基础上修改 */
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
double ans = 0.0;           // 用于存放最近打印的值 初始值为 0

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
            printf("\t%.8g\n", ans = pop());
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
    else if (strcmp(s, "ans") == 0)  return ans;        // 将变量名用对应的值替代
    else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        return pow(pop(), op2);
    } else {            // 未知函数
        fprintf(stderr, "error: unknown string %s", s);
        exit(1);
    }
}