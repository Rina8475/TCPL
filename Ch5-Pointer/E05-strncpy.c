/* 练习 5-5 实现库函数 strncpy strncat strncmp */

/* 将指针 t 指向的字符串中最多 n 个字符复制到指针 s 指向的位置 假设 s 的空间足够 */
void strncpy(char *s, char *t, int n) {
    while (--n >= 0 && (*s++ = *t++));
}

/* 将字符串 t 中最多 n 个字符连接到字符串 s 的尾部 s 必须要有足够大的空间 */
void strncat(char *s, char *t, int n) {
    while (*s != '\0')  s++;
    while (--n >= 0 && (*s++ = *t++));
}

/* 比较字符串 s 和 t 最多前 n 个字符 
   根据 s 按照字典顺序小于 等于或大于 t 的结果分别返回 负整数 0 正整数 */
int strncmp(char *s, char *t, int n) {
    int c;
    while (--n >= 0 &&  (c = *s - *t++) == 0 && *s++ != '\0');
    return c;
}