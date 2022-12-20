/* 练习 1-22 编写一个程序 把较长的行"折"成短一些的行 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLINE 100
#define N 30    // 在第 N 列之前折叠

// while (getline(string, limit) > 0) 
//     if (wrap(string, length) < 0)
//         exit(1);

int getline(char line[], int limite);
int wrap(char line[], int length);

int main(void) {
    int len, rem;
    char line[N+1];

    while ((len = getline(line+rem, N-rem)) > 0) {
        if ((rem = wrap(line, len)) < 0)
            exit(1);
    }
    return 0;
}

/* 从输入读入字符 写入字符串 s 中，  lim 为字符串的长度
   返回字符串 s 所写入的字符个数 */
int getline(char *s, int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return i;
}

/* 在字符串 s 中 以 N 个元素为一行 从每行的末尾向前查找第一个空格符前的非空格符 并在那之后断行 
   len 为字符串的长度 函数返回处理完后字符串 s 中剩余的字符个数 */
int wrap(char *s, int len) {
    for (int i = 0; i < len; i += N) {
        int j = i+N;

        while (--j >= 0 && !isspace(s[j]));
        while (--j >= 0 && isspace(s[j]));
    }
    // int i = N - 1;

    // while (--i >= 0 && !isspace(s[i]));
    // if (i < 0) {
    //     fprintf(stderr, "error: line over length\n");
    //     exit(1);
    // }
    // while (--i >= 0 && isspace(s[i]));       // 跳过空格符 
    // s[i+1] = '\0';
    // printf("%s\n%s", s, s+i+2);
    // return 0;
}