/* 对应于教材  S1.10 的输出最大行的程序
   对于外部变量 要么加 extern 关键字 要么就不声明 */
#include <stdio.h>

#define MAXLINE 1000

/* 全局变量 */
char line[MAXLINE];
char longest[MAXLINE];

int getline(void);
void copy(void);

int main(void) {
    int len, max = 0;
    // extern char longest[];
    while ((len = getline()) > 0)
        if (len > max) {
            max = len;
            copy();
        }
    if (max > 0)    
        printf("%s", longest);
    return 0;
}

int getline(void) {
    int c, i;
    extern char line[];
    for (i = 0; i < MAXLINE-1 && (c = getchar()) != '\n' && c != EOF; i++)
        line[i] = c;
    if (c == '\n')    
        line[i++] = '\n';
    line[i] = '\0';
    return i;
}

void copy(void) {
    extern char line[];
    extern char longest[];

    for (int i = 0; line[i] != '\0'; i++)
        longest[i] = line[i];
}