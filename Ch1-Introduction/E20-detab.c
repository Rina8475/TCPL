/* 练习 1-20 编写函数 detab 将输入中的制表符替换为适当数目的空格符 */
#include <stdio.h>
#define TAB2SPACE 8         // 每个 shift 对应于多少个 space

int tab2space(int index);

int main(void) {
    int c;
    for (int i = 0; (c = getchar()) != EOF; i++) {
        if      (c == '\n')     i = -1;
        else if (c == '\b')     i -= 2;
        else if (c == '\t') {
            i += (tab2space(i)-1);
            continue;
        }
        putchar(c);
    }
        
    return 0;
}

/* 将一个 tab 符转换为若干个 space 
   其中 x 为该行内 tab 符之前的字符数
   返回应补充的 space 符的个数 */
int tab2space(int x) {
    x = TAB2SPACE - x % TAB2SPACE;
    for (int i = 0; i < x; i++)         
        putchar(' ');
    return x;
}