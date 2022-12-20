/* 对应教材 S1.2 ~ S1.4 的温度转换程序 */
#include <stdio.h>
#define LOWER 0             //符号常量
#define UPPER 300
#define STEP  20
// #define WHILE


/* 当 fahr = 0, 20, ..., 300 时，分别
   打印华氏温度与摄氏温度对照表 */
#ifdef WHILE
int main(void){
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = upper;                                   //此处 lower 值会在转换为浮点数后再赋值给 fahr  下一行 while 的比较语句同样
    printf("********%%*********\n");                //  %%  表示  %
    while (fahr >= lower)                           //循环语句  不是函数
    {
        celsius = 5 * (fahr-32) / 9;                //除 = 外 其余运算符均为由左至右进行运算
        printf("%3.0f\t%6.1f\n", fahr, celsius);      //不能用 %d 输出浮点数     浮点数和整数储存方式不同
        fahr -= step;
    }

    return 0;
}
#else
int main(void) {
    for (int fahr = LOWER; fahr <= UPPER; fahr += STEP) 
        printf("%3d %6.1f \n", fahr, (5.0/9.0)*(fahr-32));
    return 0;
}
#endif 