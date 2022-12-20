/* 练习 5-13 编写程序 tail 将输入中的最后 n 行打印出来
   默认情况下 n 的值为 10 但可以通过一个可选参数改变 n 的值
   写得比较烂 应该还有改进的余地。。 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN  1000    // 每行的最大长度
#define MAXLINE 100     // 所存储的最大行数

int getline(char *string, int limit);
void *Malloc(size_t size);

int main(int argc, char *argv[]) {
    int len, i, c, linep = 0, n = 10;
    char *ptr, line[MAXLEN], *nline[MAXLINE];

    while (--argc > 0 && (*++argv)[0] == '-')           // 识别参数
        if (isdigit(c = *++argv[0]))
            n = atoi(argv[0]);
        else {
            fprintf(stderr, "find: illegal option %c\n", c);
            argc = -1;
        }

    if (argc != 0)   {                                  // 检查参数格式是否正确
        fprintf(stderr, "Usage: find -n pattern\n");
        return 1;
    } 
    if (n > MAXLINE)                                    // 检查参数是否在正确范围内
        fprintf(stderr, "warn: the value of n over the buf\n");

    for (i = 0; i < MAXLINE && (len = getline(line, MAXLEN)) > 0; i++) {        // 读取字符串 第一遍 不用 free
        ptr = Malloc((len + 1) * sizeof(char));
        strcpy(ptr, line);
        nline[linep++] = ptr;
    }
    if (i == MAXLINE)    linep = 0;
    for (; (len = getline(line, MAXLEN)) > 0; linep = (linep + 1) % MAXLINE) {  // 读取字符串 需要 free
        ptr = Malloc((len + 1) * sizeof(char));
        free(nline[linep]);
        strcpy(ptr, line);
        nline[linep] = ptr;
    }
    
    linep = (linep + MAXLINE - (n % MAXLINE)) % MAXLINE;                // 调整开始指针
    for (i = 0; i < n; i++, linep = (linep + 1) % MAXLINE)              // 打印字符串
        printf(nline[linep]);
    return 0;
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

/* wrapped function */
void *Malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL)  
        fprintf(stderr, "error: malloc a null pointer\n");
    return ptr;
}