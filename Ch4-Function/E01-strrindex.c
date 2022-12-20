/* 练习 4-1 编写函数 strrindex */
#include <stdio.h>
#include <string.h>
int strrindex(char str[], char pat[]);

int main(void) {
    char test1[] = "Hello worldught";
    char test2[] = "oughtttoughoughtasdad";
    char pattern[] = "ought";

    printf("%d\n", strrindex(test1, pattern));
    printf("%s\n", test2 + strrindex(test2, pattern));
    
    return 0;
}

/* 返回字符串 t 在 s 中最右边出现的位置， 如果 s 中不包含 t 则返回 -1 */
int strrindex(char *s, char *t) {
    int i = strlen(s), t_len = strlen(t);       // 未除去 '\0' 的字符串末位下标
    int j, k;
    while (--i >= 0) {
        for (j = t_len-1, k = i; j >= 0 && s[k] == t[j]; k--, j--);
        if (j < 0)  return i - t_len + 1;
    }
    return -1;
}