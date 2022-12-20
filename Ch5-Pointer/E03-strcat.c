/* 练习 5-3 编写函数 strcat 
   此处定义的 strcat 函数与 C 标准库产生冲突 使用 GCC 参数 -fno-builtin 不使用标准库函数 */
#ifdef TEST
#include <stdio.h>

int main(void){
    char s[20] = "Hello ";
    char t[] = "World!";
    void strcat(char *s, char *t);

    strcat(s, t);
    printf("%s\n", s);
    return 0;
}
#endif

/* 将字符串 t 连接到字符串 s 的尾部 s 必须要有足够大的空间 */
void strcat(char *s, char *t) {
    while (*s != '\0')  s++;
    while (*s++ = *t++);
}