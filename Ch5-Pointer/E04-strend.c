/* 练习 5-4 编写函数 strend */
#ifdef TEST
#include <stdio.h>

int main(void){
    char s1[] = "Hello World!";
    char s2[] = "World!";
    char s3[] = "Hello ";
    int strend(char *, char *);
    
    if (strend(s1, s2) && !strend(s1, s3))
        printf("test access!\n");        
    return 0;
}
#endif

/* 如果字符串 t 出现在字符串 s 的尾部 则函数返回 1 否则返回 0 */
int strend(char *s, char *t) {
    char *p = t;

    while (*s != '\0')  s++;
    while (*t != '\0')  t++;
    while (--t >= p && *--s == *t);
    return (t+1 == p) ? 1 : 0;
}