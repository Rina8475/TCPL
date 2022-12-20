/* 练习 7-4 编写 scanf 函数的一个简化版本 minscanf 
   和答案有些不一样 应该是对的吧。。 */
#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#define LOCALFMT  100
#define TEST
#ifdef TEST
void minscanf(char *fmt, ...);
int main(void) {
    int c;
    minscanf("%%");
    minscanf("%c", &c);
    // if ((c = scanf("%d | %d", &a, &a)) == EOF)
    //     Exit(2, "error: no such option %s\n", "-s");
    printf("%c\n", c);
}
#endif

void minscanf(char *fmt, ...) {
    int c, i, *ival;
    va_list ap;
    char *sval, localfmt[LOCALFMT], *p = fmt;
    double *dval;
    unsigned *uval;

    va_start(ap, fmt);
    do {
        while (isspace(c = getchar()));         // 除去空白字符
        while (*p == ' ' || *p == '\t')         // 除去 space 和 \t
            p++; 
        if (*p != '%' && *p != c) {
            ungetc(c, stdin);
            break;
        } else if (*p == '%') {
            ungetc(c, stdin);           // 退回 stdin 留待 scanf 读
            localfmt[0] = '%';
            for (i = 1; *++p != '\0' && !isalpha(*p); i++)
                localfmt[i] = *p;
            localfmt[i++] = *p;
            localfmt[i] = '\0';
            switch (*p) {
            case 'd':
            case 'i':
                ival = va_arg(ap, int *);
                scanf(localfmt, ival);
                break;
            case 'o':
            case 'x':
            case 'X':
            case 'u':
                uval = va_arg(ap, unsigned *);
                scanf(localfmt, uval);
                break;
            case 'c':
            case 's':
                sval = va_arg(ap, char *);
                scanf(localfmt, sval);
                break;
            case 'e':
            case 'f':
            case 'g':
                dval = va_arg(ap, double *);
                scanf(localfmt, dval);
                break;
            default:
                scanf(localfmt);
                break;
            }
        }
    } while ((*p & *++p) != '\0');
    va_end(ap);
}