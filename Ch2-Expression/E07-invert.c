/* 练习 2-7 编写 invert 函数 */
#include <stdio.h>
#define MASK(p, n)  ~(~(~0 << n) << p)          // 取从 p 位开始的 n 个位为 0 其余位为 1

unsigned invert(unsigned x, int p, int n);

int main(void){
    unsigned x = ~0;
    unsigned y = ~0 >> 5;
    unsigned z = 1024;

    printf("Output #01: %#x %#x\n", x, invert(x, 5, 8));
    return 0;
}

/* 将 x 从 p 位开始的 n 个位求反， x 的其余位保持不变 */
unsigned invert(unsigned x, int p, int n) {
    unsigned val = (x >> p) | (~0 << n);
    return (~val << p) | (x & MASK(p, n));
}