/* 练习 2-4 编写函数 squeeze */
#include <stdio.h>
#include <string.h>

void squeeze(char s1[], const char s2[]);
static int isSubstr(const char str[], const char sub[]);

int main(void) {
    char s1[] = "Hello world";
    char s2[] = "o";
    squeeze(s1, s2);
    printf("%s", s1);
}

/* 将字符串 s1 中任何与字符串 s2 匹配的字符删除 */
void squeeze(char s1[], const char s2[]) {
    int j = 0, step = strlen(s2);
    for (int i = 0; s1[i] != '\0'; i++) 
        if (isSubstr(s1+i, s2))     i += (step-1);
        else                        s1[j++] = s1[i];
    s1[j] = '\0';
}

/* 判断 sub 是否是 str 的从首位开始的子串 */
static int isSubstr(const char str[], const char sub[]) {
    while (*sub != '\0')
        if (*(str++) != *(sub++))     return 0;
    return 1;
}