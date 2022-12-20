/* 对应教材 S2.7 的 atoi 函数 */
#include <stdio.h>
#include <ctype.h>

int atoi(const char str[]);

/* 将字符串整数转换为相应的整型数 */
int atoi(const char s[]) {
    int val = 0;
    for (int i = 0; isdigit(s[i]); i++)
        val = val * 10 + s[i] - '0';
    return val;
}