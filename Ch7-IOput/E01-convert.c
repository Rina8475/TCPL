/* 练习 7-1 编写一个程序 根据它自身被调用时存放在 argv[0] 中的名字
   实现将大写字母转换为小写字母或将小写字母转换为大写字母的功能 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* lower : 将大写字母转换为小写字母
   upper : 将小写字母转换为大写字母 */
int main(int argc, char *argv[]) {
    int c, (*func)(int);

    func = (strcmp(argv[0], "lower") == 0) ? tolower : toupper;
    while ((c = getchar()) != EOF)
        putchar((*func)(c));
    return 0;
}