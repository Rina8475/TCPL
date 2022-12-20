/* 对应教材 S7.3 实现函数 printf 的一个简单版本 */
#include <stdio.h>
#include <stdarg.h>

/* 带有可变参数表的简化的 printf 函数 */
void minprintf(char *fmt, ...) {
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);
    for (p = fmt; *p != '\0'; p++)
        if (*p == '%') 
            switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval != '\0'; sval++)
                    putchar(*sval);
                break;
            default:
                putchar(*p);
                break;
            }
        else putchar(*p);
    va_end(ap);
}