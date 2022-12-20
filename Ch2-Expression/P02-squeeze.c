/* 对应教材 S2.8 squeeze函数和 strcat 函数 */
#include <stdio.h>

void squeeze(char str[], char c);
void strcat(char des[], char src[]);

/* 从字符串 s 中删除字符 c */
void squeeze(char s[], char c) {
    int j = 0;
    for (int i = 0; s[i] != 0; i++) 
        if (s[i] != c)  s[j++] = s[i];
    s[j] = '\0';
}

/* 将字符串 t 连接到字符串 s 的尾部  不检查 s 的空间是否足够 */
void strcat(char *s, char *t) {
    int i = 0, j = 0;
    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0');
}