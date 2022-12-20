/* 对应教材 S6.3 编写一个程序统计一个 C 程序中各个关键字出现的次数
   教材上的 getword 函数貌似有问题 所以自己更改了一下 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXWORD 5
#define NKEYS   (sizeof keytab) / (sizeof keytab[0])

struct key {
    char *word;
    int count;
};

int getword(char *word, int limite);
int binsearch(char *word, struct key tab[], int n);
struct key keytab[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
    {"unsigned", 0},
    {"void", 0},
    {"volatile", 0},
    {"while", 0},
};

int main(void) {
    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF) 
        if (isalpha(word[0]) && (n = binsearch(word, keytab, NKEYS)) >= 0)
            keytab[n].count++;
    for (int i = 0; i < NKEYS; i++)
        if (keytab[i].count > 0)
            printf("%4d %s\n", keytab[i].count, keytab[i].word);
    return 0;
}

/* 从输入中读取下一个单词 单词可以是以字母开头的字母和数字串 也可以是一个非空白字符
   函数返回值可以是单词的第一个字符 文件结束符 EOF 或字符本身 */
int getword(char *s, int lim) {
    int c, getch(void);
    void ungetch(int c);
    char *w = s;

    while (isspace(c = getch()));
    if (c != EOF)   *w = c;
    if (!isalpha(c)) {
        *++w = '\0';
        return c;
    }
    while (--lim > 0 && isalnum(*++w = c = getch()));       // 有问题的地方是这里 ~ 
    ungetch(c);
    *w = '\0';
    return s[0];
}

/* 在 tab[0] 到 tab[n-1] 之间查找单词 采用二分查找 默认关键字列表按升序存储在 tab 中 */
int binsearch(char *word, struct key tab[], int n) {
    int cond, mid, lo = 0, hi = n-1;

    while (lo <= hi) {
        mid = (lo + hi) / 2;
        cond = strcmp(word, tab[mid].word);
        if      (cond < 0)  hi = mid - 1;
        else if (cond > 0)  lo = mid + 1;
        else return mid;
    }
    return -1;
}