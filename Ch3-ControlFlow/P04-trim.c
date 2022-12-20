/* 对应教材 S3.7 编写函数 trim */
#include <string.h>
#define ISSPACE(c)      ((c) == ' ' || (c) == '\n' || (c) == '\t')
int trim(char s[]);

/* 删除字符串尾部的空格符 制表符与换行符 */
int trim(char s[]) {
    int i = strlen(s);
    while (--i >= 0 && ISSPACE(s[i]));
    s[i+1] = '\0';
}