#include <stdio.h>
#include <stdint.h>
#define MAXLINE 1000

int getline(char *str, int length);
void copy(char des[], char src[]);
// int exch(void *ptr1, void *ptr2);

int main(void) {
    int len, max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];
    // char *max, *str, len_1[MAXLINE], len_2[MAXLINE];
    // int len, maxl = 0;
    // max = len_1;
    // str = len_2;

    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > max) {
            copy(longest, line);
            max = len;
        }     
    }

    if (max > 0)   printf("%s", longest);

    return 0;
}

int getline(char *str, int lim) {
    int c, i;
    for (i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; i++)
        str[i] = c;
    while (--i >= 0 && (str[i] == ' ' || str[i] == '\t'));          // 删除 str 末尾的空格符
    if (c == '\n')
        str[++i] = '\n';
    str[++i] = '\0';
    return i;
}

/* 将字符串从 src 中复制到 des 中 */
void copy(char *des, char *src) {
    while ((*(des++) = *(src++)) != '\0');          // 仰望高端玩家
    *des = '\0';
}



// int exch(void *ptr1, void *ptr2) {
//     ptr1 = (int64_t) ptr1 ^ (int64_t) ptr2;
//     ptr2 = (int64_t) ptr1 ^ (int64_t) ptr2;
//     ptr1 = (int64_t) ptr1 ^ (int64_t) ptr2;
// }