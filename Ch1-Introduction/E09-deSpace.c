/* 练习 1-9 将输入文本中的多个空格用一个空格替代 */
#include <stdio.h>

int main(void) {
    int c, space = 0;

    while ((c = getchar()) != EOF) {
        if      (c == ' ')  {space = 1; continue;}     
        else if (space)     {putchar(' '); space = 0;} 
        putchar(c);
    }
    
    return 0;
}