/* 对应教材 S4.2 编写函数 atof */
#include <ctype.h>
double atof(char str[]);

/* 把字符串 s 转换为相应的双精度浮点数 */
double atof(char s[]) {
    double power, val = 0.0;
    int sign, i = 0;

    while (isspace(s[i]))   i++;            // 除去 space
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')     i++;    // 判断符号
    for (; isdigit(s[i]); i++)          // 整数部分
        val = val * 10 + s[i] - '0';
    if (s[i++] != '.')    return val;     // 判断有无小数部分
    for (power = 1.0; isdigit(s[i]); i++, power *= 10)    // 小数部分
        val = val * 10 + s[i] - '0';
    return sign * val / power;
}