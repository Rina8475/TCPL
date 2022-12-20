/* 练习 4-3 修改 main 函数 增加 % 运算符 
   % 运算符不能运用于 float 或 double 类型 */
#include <stdio.h>
#include <stdlib.h>
#define MAXOP   100     // 操作数或运算符的最大长度

int getop(char s[]);
void push(double f);
double pop(void);
void Exit(int x);

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
            if ((op2 = pop()) == 0.0)   Exit(4);
            push(pop() / op2);
            break;
        case '%':
            if ((int) (op2 = pop()) == 0)   Exit(4);
            push((int) pop() % (int) op2);
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            fprintf(stderr, "error: unknown command %s\n", s);
            Exit(5);
            break;
        }
}