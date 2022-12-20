/* 练习 4-13 编写一个递归版本的 reverse 函数 */
#include <string.h>
void reverse(char s[]);
void recursive(char s[], int i, int j);

#ifdef TEST
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2)  exit(0);
    char *test = argv[1];
    reverse(test);
    printf("%s\n", test);
}
#endif

/* 递归版本的 reverse 函数 以将字符串 s 倒置 */
void reverse(char *s) {
    recursive(s, 0, strlen(s)-1);
}

/* 递归部分 */
void recursive(char *s, int i, int j) {
    if (j <= i) return;
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    recursive(s, i+1, j-1);
}