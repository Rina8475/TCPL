/* 对应于练习 3-3 编写函数 expand 
   应该算得上是编写成功了吧。。。 脑壳痛。。 */
#include <stdio.h>
#include <ctype.h>
#define ISABBR(s)       ((isdigit(*(s-1)) && isdigit(*(s+1))) || (islower(*(s-1)) && islower(*(s+1))) || \
                         (isupper(*(s-1)) && isupper(*(s+1))))

void expand(char src[], char des[]);

int main(void) {
    char test[] = "a-b-c0-9A-Z-v-t";
    char resu[100];
    expand(test, resu);
    printf("%s", resu);
}

/* 将 s1 中类似于 a-z 一类的速记符号在 s2 中扩展为等价的完整列表 abc...xyz */
void expand(char *s1, char *s2) {
    while (*s2 = *s1) {
        if (*s1 == '-' && ISABBR(s1) && *(s1-1) < *(s1+1)) {        // 满足条件则进行扩展
            for (int i = *(s1-1) + 1; i <= *(s1+1); i++)            // 扩展
                *(s2++) = i;
            s1 += 2;                // 将 s1 指针移到接下来应该复制的地方
            if (*s1 == '-') *(s2++) = *(s1++);       // 避免二次扩展
        } else s2++, s1++;
    }
}
