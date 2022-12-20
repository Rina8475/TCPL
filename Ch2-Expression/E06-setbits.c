/* 练习 2-6 编写 setbits 函数 */
#include <stdio.h>
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void){
    unsigned x = ~0;
    unsigned y = ~0 >> 5;
    unsigned z = 1024;

    printf("Output #01: %#x %#x\n", x, setbits(x, 5, 8, z));
    printf("Output #02: %#x %#x\n", 0u >> 1, ~0u >> 1);
    printf("Output #03: %#x %#x\n", 0 >> 1, ~0 >> 1);       // 后缀不添加u时会被解释为 signed int类型
    return 0;
}

/* 将 x 中从第 p 位开始的 n 个位设置为 y 中最右边 n 位的值
   x 的其余各位保持不变 */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned mask = (y & ~(~0 << n)) << p;
    unsigned val = x & ~(~(~0 << n) << p);
    return val | mask;
}