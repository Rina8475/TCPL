/* 练习 3-2 编写函数 escape */
#include <stdio.h>
#define SIZE 100

void escape(char des[], char src[]);
void unescape(char des[], char src[]);

/* test */
int main(void) {
    char t1[] = "Hello World";
    char t2[] = "Are you going to fair\tYes\nIs the Christina?";
    char t3[] = "    \n\n\n\n\n\n \t\t\t\t\t\t \b\b\b\b\b\b    ";
    char t4[] = "";
    char s1[SIZE], s2[SIZE], s3[SIZE], s4[SIZE];
    char c1[SIZE], c2[SIZE], c3[SIZE], c4[SIZE];
    unescape(s1, t1);   unescape(s2, t2);
    unescape(s3, t3);   unescape(s4, t4);
    escape(c1, s1);     escape(c2, s2);
    escape(c3, s3);     escape(c4, s4);
    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("%s\n", s3);
    printf("%s\n", s4);
    printf("%s\n", c1);
    printf("%s\n", c2);
    printf("%s\n", c3);
    printf("%s\n", c4);
    
    return 0;
}

/* 将字符串 t 复制到字符串 s 中， 并在复制过程中将不可见字符转换为可见字符 */
void escape(char *s, char *t) {
    while (*s = *(t++)) {
        switch (*s) {
        case '\t':
            *(s++) = '\\';
            *(s++) = 't';
            break;
        case '\n':
            *(s++) = '\\';
            *(s++) = 'n';
            break;
        case '\b':
            *(s++) = '\\';
            *(s++) = 'b';
            break;
        case '\\':
            *(s++) = '\\';
            *(s++) = '\\';
            break;
        default:
            s++;
            break;
        }
    }
}

/* 与 escape 函数功能相反 在复制过程中将转义字符序列转换为实际字符 */
void unescape(char *s, char *t) {
    for (; *s = *t; s++)
        if (*(t++) == '\\')
            switch (*(t++)) {
            case 'n':
                *s = '\n';
                break;
            case 't':
                *s = '\t';
                break;
            case 'b':
                *s = '\b';
                break;
            case '\\':
                *s = '\\';
                break;
            default:
                break;
            }
}