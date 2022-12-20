/* 练习 2-8 编写函数 rightrot */
#include <stdio.h>
#define LSHIFT  0u                      // 逻辑右移
#define ASHIFT  ~((unsigned) -1 >> 1)   // 算术右移
unsigned rightrot(unsigned x, int n);

int main(void){
    unsigned x = ~0;
    unsigned y = ~0u >> 5;
    unsigned z = 1024;

    printf("Output #01: %#x %#x\n", x, rightrot(x, 5));
    printf("Output #02: %#x %#x\n", y, rightrot(y, 3));
    printf("Output #03: %#x %#x\n", z, rightrot(z, 10));
    return 0;
}

/* 函数返回将 x 循环右移 n 位后所得到的值 */
unsigned rightrot(unsigned x, int n) {
    for (int i = 0; i < n; i++)
        x = (x >> 1) | ((x & 1u) ? ASHIFT : LSHIFT);
    return x;
}