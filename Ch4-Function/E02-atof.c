/* 练习 4-2 编写扩充后的 atof 函数 */
#include <stdio.h>
#include <ctype.h>
// double atof(char str[]);

int main(void) {
    char test1[] = "1234";
    char test2[] = "134.521";
    char test3[] = "0.123";
    char test4[] = "123.45E2";
    char test5[] = "11.3e-4";
    double atof(char []);

    printf("%10s    %10f\n", test1, atof(test1));
    printf("%10s    %10f\n", test2, atof(test2));
    printf("%10s    %10f\n", test3, atof(test3));
    printf("%10s    %10f\n", test4, atof(test4));
    printf("%10s    %10f\n", test5, atof(test5));
    
    return 0;
}

/* 可以处理科学计数法的浮点数 eg 123.45E-6 */
double atof(char s[]) {
    double pow, val = 0.0;
    int sign, i_sign, i = 0, i_val = 0;

    while(isspace(s[i]))    i++;                 // 跳过空格
    sign = (s[i] == '-') ? -1 : 1;          // 处理符号
    if (s[i] == '-' || s[i] == '+')  i++;
    for (; isdigit(s[i]); i++)
        val = val * 10.0 + s[i] - '0';
    if (s[i++] != '.')    return val;                       // 判断有无小数
    for (pow = 1.0; isdigit(s[i]); i++, pow *= 10.0)        // 处理小数
        val = val * 10.0 + s[i] - '0';
    val = val / pow;
    
    if (tolower(s[i]) != 'e')   return val;                 // 判断有无指数
    i_sign = (s[++i] == '-') ? -1 : 1;                      // 处理指数
    if (s[i] == '-' || s[i] == '+')  i++;
    for (; isdigit(s[i]); i++)
        i_val = i_val * 10 + s[i] - '0';
    for (pow = 1.0; --i_val >= 0; pow *= 10);

    return (i_sign == 1) ? val * pow : val / pow;
}