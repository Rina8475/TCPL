/* 对应教材 S4.3 编写一个计算器程序 
   part_2 实现一个栈及 pop push 函数 */
#define MAXVAL  100         // 栈 val 的最大深度

void Exit(int x, char *fmt, ...);
int sp = 0;
double val[MAXVAL];

/* 将一个元素压入栈 val 中 */
void push(double f) {
    if (sp == MAXVAL)   Exit(1, "error: stack full\n");    // 栈满错误
    val[sp++] = f;
}

/* 将栈 val 栈顶的元素返回 */
double pop(void) {
    if (sp == 0)        Exit(1, "error: stack empty\n");    // 栈空错误
    return val[--sp];
}