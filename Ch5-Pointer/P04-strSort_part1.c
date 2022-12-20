/* 对应教材 S5.6 编写一个从输入流中读取若干个字符串 并对其进行排序的程序
   part_1 main 函数编写 */
#include <stdio.h>
#include <string.h>
#define MAXLINES    5000        // 进行排序的最大文本行数

char *lineptr[MAXLINES];        // 指向文本的指针数组

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
int partition(char *lineptr[], int left, int right);

int main(void) {
    int len = readlines(lineptr, MAXLINES);
    if (len == -1) {
        fprintf(stderr, "error: input too big to sort\n");
        return 1;
    }
    qsort(lineptr, 0, len-1);
    writelines(lineptr, len);
    return 0;
}

void qsort(char *v[], int lo, int hi) {
    if (hi <= lo)   return;
    int mid = partition(v, lo, hi);
    qsort(v, lo, mid-1);
    qsort(v, mid+1, hi);
}

int partition(char *v[], int lo, int hi) {
    char *p = v[hi];
    int i = lo, j = lo-1;
    void exch(char *v[], int i, int j);

    while (++j < hi) 
        if (strcmp(v[j], p) < 0)    
            exch(v, j, i++);
    exch(v, hi, i);
    return i;
}

void exch(char *v[], int i, int j) {
    char *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}