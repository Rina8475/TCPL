/* 练习 7-3 修改 P01 中的 minprintf 使之能完成 printf 函数的更多功能 */
#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#define LOCALFMT  100

#ifdef TEST
void minprintf(char *fmt, ...);
int main(void) {
    minprintf("Hello world %d %-15.10s %% %c %f", 179394, "Hello world", '\n', 3.1415926);
    return 0;
}
#endif

void minprintf(char *fmt, ...) {
    va_list ap;
    int ival, i;
    unsigned uval;
    char *p, *sval, cval, localfmt[LOCALFMT];
    double dval;

    va_start(ap, fmt);
    for (p = fmt; *p != '\0'; p++)
        if (*p != '%')  putchar(*p);
        else {
            localfmt[0] = '%';
            for (i = 1; *++p != '\0' && !isalpha(*p); i++)
                localfmt[i] = *p;
            localfmt[i++] = *p;
            localfmt[i] = '\0'; 
            switch (*p) {
            case 'd':
            case 'i':
            case 'c':
                ival = va_arg(ap, int);
                printf(localfmt, ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf(localfmt, dval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                printf(localfmt, sval);
                break;
            case 'x':
            case 'X':
            case 'o':
            case 'u':
                uval = va_arg(ap, unsigned);
                printf(localfmt, uval);
                break;
            default:
                printf(localfmt);
                break;
            }
        }
    va_end(ap);
}