/* 对应教材 S1.9 的字符数组程序 */
#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char des[], char src[]);

int main(void) {
    int len, max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) 
        if (len > max) {
            copy(longest, line);
            max = len;
        }
    
    if (max > 0)                // 如果存在这样的行
        printf("%s", longest);
    return 0;
}

/* lim 为数组 s 的长度 */
int getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; i++)
        s[i] = c;
    if (c == '\n') 
        s[i++] = '\n';
    
    s[i] = '\0';
    return i;
}

/* 将字符串从 src 中复制到 des 中 */
void copy(char *des, char *src) {
    while ((*(des++) = *(src++)) != '\0');          // 仰望高端玩家
    *des = '\0';
}