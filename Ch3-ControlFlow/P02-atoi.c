/* 对应于教材 S3.5 函数 atoi 的编写 */
#include <ctype.h>
int atoi(char s[]);

/* 将数字字符串更改为对应的整型
   可处理可选的前导空白以及可选的 + 或 - */
int atoi(char s[]) {
    int sign, val = 0, i = 0;
    while (isspace(s[i]))   i++;            // 跳过空白符
    sign = (s[i] == '-') ? -1 : 1;  
    if (s[i] == '+' || s[i] == '-') i++;    // 跳过符号
    for (; isdigit(s[i]); i++)
        val = val * 10 + s[i] - '0';
    return sign * val;
}