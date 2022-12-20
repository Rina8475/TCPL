/* 练习 5-10 编写程序 expr 计算从命令行中输入的逆波兰表达式的值
   其中 每个参数或操作数用一个单独的参数表示 
   注意 命令行参数禁止直接输入 * 在 Linux 下 使用 '*' 作为输入
   至于 windows 下。。 不知道。。 垃圾 windows  */
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define NUMBER  '0'

void push(double f);        // 外部函数声明
double pop(void);
int getop(char *s);

int main(int argc, char *argv[]) {
    double op2;

    while (--argc > 0)
        switch (getop(*++argv)) {
        case NUMBER:
            push(atof(*argv));
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
            if ((op2 = pop()) == 0)     return 1;
            push(pop() / op2);
            break;
        default:
            fprintf(stderr, "error: no such instruction %s\n", *argv);
            return 1;
            break;
        }
    printf("result is %lf\n", pop());
    return 0;
}

/* 判断传入函数的字符串是哪种类型的参数 */
int getop(char *s) {
    return (isdigit(s[0]) || s[0] == '.') ? NUMBER : s[0];
}