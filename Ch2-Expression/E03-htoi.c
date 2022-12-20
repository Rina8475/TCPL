/* 练习 2-3 编写函数 htoi 将十六进制数字组成的字符串转换为对应的整数 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
/* 将 16 进制的字符转换为对应的十进制数字 */
#define HEX2DIGIT(x)    (isdigit(x) ? (x) - '0' : tolower(x) - 'a' + 10)

int htoi(const char s[]);

int main(void) {
    char test1[] = "0xf";       // 15
    char test2[] = "0X1000A";   // 16^4 + 10
    char test3[] = "fffff";     // 2^20 - 1
    char test4[] = "FFffe";     // 2^20 - 2
    printf("%#x ", htoi(test1));
    printf("%#x ", htoi(test2));
    printf("%#x ", htoi(test3));
    printf("%#x ", htoi(test4));
    return 0;
}

int htoi(const char s[]) {
    int i = (tolower(s[1]) == 'x') ? 2 : 0;     // 去除可选前缀
    int val = 0;
    for (; s[i] != '\0'; i++)
        val = val * 16 + HEX2DIGIT(s[i]);
    return val;
}