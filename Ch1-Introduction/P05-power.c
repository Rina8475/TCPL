/* 对应教材 S1.7 ~ S1.8 的求幂函数程序 */
#include <stdio.h>

int power(int m, int n);        // 函数声明  函数原型                           

int main(void){
    for (int i = 0; i < 10; i++)
        printf("%d %d %d\n", i, power(2,i), power(-3,i));
        
    return 0;
}

/* power func: 求底数的 n 次幂， 其中 n >= 0 */
int power(int base, int n){
    int p = 1;

    for (int i = 0; i < n; i++)
        p *= base;    
    
    return p;                       // return 表达式
}