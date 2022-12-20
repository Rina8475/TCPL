/* 对应教材 S3.6 编写 itoa 函数 */
void itoa(int number, char str[]);

/* 将数字 n 转换为字符串并保存到 s 中 */
void itoa(int n, char s[]) {
    int i, sign, j = 0;

    if ((sign = n) < 0)     n = -n;     // n != INT_MIN
    do {                        // 至少能运行一次
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)   s[i++] = '-';
    s[i--] = '\0';

    while (j < i) {         // reverse s
        char temp = s[j];
        s[j++] = s[i];
        s[i--] = temp;
    }
}