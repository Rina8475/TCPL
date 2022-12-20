/* 对应教材 S5.10 编写程序 对应 Ch4 的程序 P01-grep.c 使之更为通用
   可带参数 -x 和 -n 且参数可以以任意顺序出现  参数需要在模式之前
   -x : 打印所有与模式不匹配的文本行
   -n : 表示显示打印行号 */
#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

int getline(char *line, int limit);

/* 打印与第一个参数指定的模式匹配的行 */
int main(int argc, char *argv[]) {
    char line[MAXLEN];
    long lineno = 0;
    int c, found = 0, number = 0, except = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0]) 
            switch (c) {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }
    if (argc != 1) {
        printf("Usage: find -x -n pattern\n");
        return found;
    }
    while (getline(line, MAXLEN) > 0) {
        lineno++; 
        if ((strstr(line, argv[0]) != NULL) != except) {
            if (number) printf("%ld:", lineno);
            printf(line);
            found++;
        }
    }
    return found;
}