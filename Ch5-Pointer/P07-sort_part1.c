/* 对应教材 S5.11 编写一个排序程序 在给定参数 -n 的情况下 函数将按照数值大小而非字典顺序对输入行进行排序 
   part_1 编写 main 函数 识别参数及函数主体  */
#include <stdio.h>
#include <string.h>
#define MAXLINES 5000       // 待排序的最大行数

char *lineptr[MAXLINES];    // 指向文本行的指针 

int readlines(char *lineptr[], int nlines);     // 外部函数声明
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right,
           int (*comp)(void *, void *));
int numcmp(const char *s1, const char *s2);

int main(int argc, char *argv[]) {
    int nlines;                     // 读入的输入行数
    int numeric;                    // 若进行数值排序 则 numeric = 1
    
    numeric = (argc > 1 && strcmp(*++argv, "-n") == 0);     // 满足条件即为进行数值排序
    if ((nlines = readlines(lineptr, MAXLINES)) < 0) {
        fprintf(stderr, "error: input too big to sort\n");
        return 1;
    }

    qsort((void **)lineptr, 0, nlines-1, 
        (int (*)(void *, void *)) (numeric ? numcmp : strcmp));   // 函数名即为函数的地址
    writelines(lineptr, nlines);
    return 0;
}