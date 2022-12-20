/* 对应教材 S1.6 的字符统计程序 */
#include <stdio.h>

int main(void) {
    int c, nwhite = 0, nother = 0;
    int ndigit[10];
    for (int i = 0; i < 10; i++)
        ndigit[i] = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') 
            nwhite++;
        else if ('0' <= c && c <= '9') 
            ndigit[c-'0']++;
        else 
            nother++;
    }

    printf("digits =");
    for (int i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d", nwhite, nother);

    return 0;
}