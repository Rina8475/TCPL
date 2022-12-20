/* 对应教材 S4.3 编写一个计算器程序 此程序探讨函数和全局变量的作用域问题及
 * 如何编写多个 C 的源文件使得其能一起编译
 * 外部全局变量和函数在使用之前必须声明 关键字 extern
 * part_1 编写 main 函数 */
#include <stdio.h>
#include <stdlib.h>             // 使用 atof 函数
#define MAXOP   100             // 操作数或运算符的最大长度

int getop(char str[]);          // 外部函数声明
void push(double f);
double pop(void);
void Exit(int x, char *fmt, ...);

/* 逆波兰计算器 */
int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
        switch (type) {
        case '0':
            push(atof(s));
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
            if ((op2 = pop()) == 0.0)   Exit(1, "error: zero divisor\n");
            push(pop() / op2);
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            Exit(1, "error: unknown command %s\n", s);
            break;
        }
}