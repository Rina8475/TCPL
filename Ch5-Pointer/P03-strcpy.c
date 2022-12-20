/* 对应教材 S5.5 编写函数 strcpy 和 strcmp */

/* 将指针 t 指向的字符串复制到指针 s 指向的位置 假设 s 的空间足够 */
void strcpy(char *s, char *t) {
    while (*s++ = *t++);    
}

/* 比较字符串 s 和 t， 根据 s 按照字典顺序小于 等于或大于 t 的结果分别返回 负整数 0 正整数 */
int strcmp(char *s, char *t) {
    int c;
    while ((c = *s - *t++) == 0 && *s++ != '\0');
    return c;
}