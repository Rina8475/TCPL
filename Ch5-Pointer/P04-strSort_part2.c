/* 对应教材 S5.6 编写一个从输入流中读取若干个字符串 并对其进行排序的程序
   part_2 readlines writelines 函数编写 */
#include <string.h>
#include <stdio.h>
#define MAXLEN  1000    // 每个输入文本行的最大长度

int getline(char *s, int lim);
void *alloc(int n);

/* readlines 函数：读取输入行 并返回读入的行数 如果输入字符行数超过限定的最大行数则返回 -1 */
int readlines(char *lineptr[], int maxlines) {
    int len, nlines = 0;
    char line[MAXLEN], *p = line;

    while (--maxlines >= 0 && (len = getline(line, MAXLEN)) > 0 && (p = alloc(len + 1)) != NULL) {
        strcpy(p, line);
        lineptr[nlines++] = p;
    } 
    return (maxlines < 0 || p == NULL) ? -1 : nlines;
}

/* writelines 函数：输出排序后的字符行 */
void writelines(char *lineptr[], int maxlines) {
    while (--maxlines >= 0)
        printf(*lineptr++);
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