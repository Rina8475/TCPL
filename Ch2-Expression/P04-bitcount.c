/* 对应教材 S2.10 bitcount 函数 */
int bitcount(unsigned x);

/* 统计 x 中值为 1 的二进制位数 */
int bitcount(unsigned x) {
    int b = 0;
    for (; x != 0; x >>= 1)
        b += (x & 1u);
    return b;
}

/* 表达式 x &= (x-1) 可以删除 x 中最右边值为 1 的一个二进制位 */
int bitcount(unsigned x) {
    int b = 0;
    while (x &= (x-1))   b++;
    return b;
}