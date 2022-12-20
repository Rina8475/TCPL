/* 练习 2-1 打印出各个整型的最大最小值
   从这个程序中可以看出 同样的一个整数 在解释方式不同时 所得出的结果不同 详见 CSAPP Ch2
   具体表现为可以将标记的行中的 %u 改为 %d 则会以 signed 的方式来解释该数据 */
#include <stdio.h>

#ifdef USEFILE
#include <limits.h>
int main(void) {
    printf("%-20s    %-20s    %-20s\n", "type", "MAX", "MIN");
    printf("%-20s    %-20d    %-20d\n", "signed char", CHAR_MAX, CHAR_MIN);
    printf("%-20s    %-20u    %-20u\n", "unsigned char", UCHAR_MAX, 0);
    printf("%-20s    %-20d    %-20d\n", "signed int", INT_MAX, INT_MIN);
    printf("%-20s    %-20u    %-20u\n", "unsigned int", UINT_MAX, 0);           /* 我是被标记的 (-_-) */
    printf("%-20s    %-20ld    %-20ld\n", "signed long", LONG_MAX, LONG_MIN);
    printf("%-20s    %-20lu    %-20lu\n", "unsigned long", ULONG_MAX, 0);
    printf("%-20s    %-20lld    %-20lld\n", "signed long long", LLONG_MAX, LLONG_MIN);
    printf("%-20s    %-20llu    %-20llu\n", "unsigned long long", ULLONG_MAX, 0);
}
#else 
/* 使用宏定义实现打印整型变量的边界值 */
#define UCHAR_MIN  ((unsigned char) 0)
#define UCHAR_MAX  ((unsigned char) -1)
#define CHAR_MAX   ((char) (UCHAR_MAX >> 1))
#define CHAR_MIN   (~CHAR_MAX)
#define UINT_MIN   ((unsigned) 0)
#define UINT_MAX   ((unsigned) -1)
#define INT_MAX    ((int) (UINT_MAX >> 1))
#define INT_MIN    (~INT_MAX)
#define ULONG_MIN  ((unsigned long) 0)
#define ULONG_MAX  ((unsigned long) -1)
#define LONG_MAX   ((long) (ULONG_MAX >> 1))
#define LONG_MIN   (~LONG_MAX)
#define ULLONG_MIN ((unsigned long long) 0)
#define ULLONG_MAX ((unsigned long long) -1)
#define LLONG_MAX  ((long long) (ULLONG_MAX >> 1))
#define LLONG_MIN  (~LLONG_MAX)

int main(void) {
    printf("%-20s    %-20s    %-20s\n", "type", "MAX", "MIN");
    printf("%-20s    %-20d    %-20d\n", "signed char", CHAR_MAX, CHAR_MIN);
    printf("%-20s    %-20u    %-20u\n", "unsigned char", UCHAR_MAX, 0);
    printf("%-20s    %-20d    %-20d\n", "signed int", INT_MAX, INT_MIN);
    printf("%-20s    %-20u    %-20u\n", "unsigned int", UINT_MAX, 0);           /* 我是被标记的 (-_-) */
    printf("%-20s    %-20ld    %-20ld\n", "signed long", LONG_MAX, LONG_MIN);
    printf("%-20s    %-20lu    %-20lu\n", "unsigned long", ULONG_MAX, 0);
    printf("%-20s    %-20lld    %-20lld\n", "signed long long", LLONG_MAX, LLONG_MIN);
    printf("%-20s    %-20llu    %-20llu\n", "unsigned long long", ULLONG_MAX, 0);
}
#endif