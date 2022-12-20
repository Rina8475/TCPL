/* 对应于教材 S2.9 编写 getbits 函数 */
#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main(void) {

}

/* 返回 x 中从右边第 p 位开始向右数 n 位的字段
   假定最右边的一位是第 0 位 */
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p-n+1)) & ~(~0 << n);         
}