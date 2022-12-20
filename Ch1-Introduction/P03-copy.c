/* 对应教材 S1.5 的字符输入输出程序 */
#include <stdio.h>
#define IN      1
#define OUT     0

int main (void){
    int c, nc, nl, nw, flag = OUT;
    nc = 0;         // 初始化  字符数
    nl = 0;         // 行数
    nw = 0;         // 单词数

    for (nc = 0; (c = getchar) != EOF; nc++) {      // c = getchar() 为一个表达式 并且具有一个值  即赋值后左边变量保存的值
        if (c == '\n')      nl++;                   // 注： = 为运算符  注： != 的优先级高于 = 

        if (c == ' ' || c == '\t' || c == '\n')
            flag = OUT;
        else if (flag == OUT){
            flag = IN;
            nw++;
        }
    }

    printf("The value of EOF is %d\n", c);                  // EOF = -1
    printf("The sentences have %d words\n", nc);
    printf("The line number of the article is %d.\n", nl);
    return 0;
} 