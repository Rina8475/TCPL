/* 练习 7-2 编写一个程序 以八进制或十六进制打印输入流中的控制字符 
   其余字符原样打印 */
#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100     // 每行的最长长度
#define OCTLEN  6       // 每个八进制字符打印后的长度

int inc(int pos, int n);

int main(void) {
    int c, pos = 0;

    while ((c = getchar()) != EOF)
        if (iscntrl(c) || c == ' ') {
            pos = inc(pos, OCTLEN);
            printf(" \\%03o ", c);
        } else {
            pos = inc(pos, 1);
            putchar(c);
        }
    return 0;
}

/* 检测当前行的已有长度 pos 加上当前单词长度 n 后是否会超过最大长度
   超过则输出 '\n'  返回值为 打印单词后 pos 的应有数值 */
int inc(int pos, int n) {
    if (pos + n <= MAXLINE)     return pos + n;
    putchar('\n');
    return n;
}