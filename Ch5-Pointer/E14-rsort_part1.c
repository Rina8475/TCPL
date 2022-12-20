/* 练习 5-14 修改程序 P07-sort 使之能处理 -r 标记 
   该标记表明以逆序方式排序 -r -n 能组合在一起使用 
   part_1 编写 main 函数 */
#include <stdio.h>
#include <string.h>
#define MAXLINES 5000       // 待排序的最大行数
#define NUMERIC 1           // 是否使用 -n 标记
#define DECR    2           // 是否使用 -r 标记

char *lineptr[MAXLINES];    // 指向文本行的指针 

int readlines(char *lineptr[], int nlines);     // 外部函数声明
void writelines(char *lineptr[], int nlines, int decr);
void qsort(void *lineptr[], int left, int right,
           int (*comp)(void *, void *));
int numcmp(const char *s1, const char *s2);
void Exit(char *err, int x);

static char option = 0;

int main(int argc, char *argv[]) {
    int nlines;                     // 读入的输入行数
    int c;

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c) {
            case 'n':
                option |= NUMERIC;
                break;
            case 'r':
                option |= DECR;
                break;
            default:
                argc = -1;
                break;
            }
    if (argc)   Exit("Usage: find -n -r pattern\n", 1);     // 错误检测
    if ((nlines = readlines(lineptr, MAXLINES)) < 0)   
        Exit("error: input too big to sort\n", 1);

    qsort((void **)lineptr, 0, nlines-1, 
        (int (*)(void *, void *)) ((option & NUMERIC) ? numcmp : strcmp));   // 函数名即为函数的地址
    writelines(lineptr, nlines, option & DECR);
    return 0;
}