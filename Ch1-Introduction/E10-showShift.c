/* 练习 1-10 将输入输出到输出 并将其中的部分转义符显示出来 */
#include <stdio.h>

int main(void) {
    int c, flag;

    while ((c = getchar()) != EOF) 
        switch (c)
        {
        case '\n':
            printf("\\n");
            break;
        case '\t':
            printf("\\t");
            break;
        case '\b':
            printf("\\b");
            break;
        case '\\':
            printf("\\\\");
            break;
        default:
            putchar(c);
            break;
        }

    return 0;
}