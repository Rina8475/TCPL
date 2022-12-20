/* 练习 4-4 修改计算器中的栈的操作 需要新增几个命令 */
#define MAXVAL  100     // 栈 val 的最大深度

void Exit(int x);
int sp = 0;
double val[MAXVAL];

/* 把值 f 压入栈中 */
void push(double f) {
    if (sp == MAXVAL)   Exit(1);
    val[sp++] = f;
}

/* 弹出并返回栈顶的值 */
double pop(void) {
    if (sp == 0)    Exit(2);
    return val[--sp];
}

/* 返回栈顶元素 */
double ptop(void) {
    if (sp == 0)    return 0;
    return val[sp-1];
}

/* 交换栈顶两个元素的值 */
void exchtop(void) {
    if (sp < 2)     return;
    double temp = val[sp-2];
    val[sp-2] = val[sp-1];
    val[sp-1] = temp;
}

/* 清空栈 */
void clstack(void) {
    sp = 0;
}