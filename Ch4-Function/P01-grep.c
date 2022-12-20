/* 对应于教材 S4.1 UNIX 程序 grep 的特例 将输入中包含特定字符串的各行打印出来 */
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000        // 最大输入行长度

int getline(char string[], int limit);
int strindex(char string[], char pattern[]);

char pattern[] = "ould";

int main(int argc, char *argv[]) {
    char string[MAXLINE];
    int found = 0;

    while (getline(string, MAXLINE) > 0)
        if (strindex(string, pattern) >= 0) {
            printf("%s", string);
            found++;
        }
    return found;
}

/* 从输入流中读取一行 返回该行的长度 */
int getline(char *str, int lim) {
    int c, i;
    for (i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; i++)
        str[i] = c;
    if (c == '\n')  str[i++] = '\n';
    str[i] = '\0';
    return i;
}

/* 函数返回字符串 ptn 在字符串 str 中出现的起始位置， 若未找到则返回 -1 */
int strindex(char *str, char *ptn) {
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        for (j = 0; ptn[j] != '\0' && str[i+j] == ptn[j]; j++);
        if (ptn[j] == '\0')     return i;
    }
    return -1;
}