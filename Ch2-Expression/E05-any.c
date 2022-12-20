/* 练习 2-5 编写函数 any */
#include <stdio.h>

int any(const char s1[], const char s2[]);

int main(void) {
    return 0;
}

/* 将字符串 s2 中的任意字符在字符串 s1 中第一次出现的位置作为结果返回
   如果 s1 中不包括 s2 中的字符 则返回 -1 */
int any(const char s1[], const char s2[]) {
    for (int i = 0; s1[i] != '\0'; i++)
        for (int j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])     return i;
    return -1;
}