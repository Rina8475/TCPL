/* 练习 5-14 修改程序 P07-sort 使之能处理 -r 标记 
   该标记表明以逆序方式排序 -r -n 能组合在一起使用 
   part_2 readlines writelines 函数编写 */
#include <string.h>
#include <stdio.h>
#define MAXLEN  1000    // 每个输入文本行的最大长度

int getline(char *s, int lim);
void *Malloc(size_t size);

/* readlines 函数：读取输入行 并返回读入的行数 如果输入字符行数超过限定的最大行数则返回 -1 */
int readlines(char *lineptr[], int maxlines) {
    int len, nlines = 0;
    char line[MAXLEN], *p = line;

    while (--maxlines >= 0 && (len = getline(line, MAXLEN)) > 0) {
        p = Malloc(len + 1);
        strcpy(p, line);
        lineptr[nlines++] = p;
    } 
    return maxlines < 0 ? -1 : nlines;
}

/* writelines 函数：输出排序后的字符行 如果 decr 为 1 则按照逆序打印 */
void writelines(char *lineptr[], int maxlines, int decr) {
    for (int i = 0; i < maxlines; i++)
        printf(decr ? lineptr[maxlines-i-1] : lineptr[i]);
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