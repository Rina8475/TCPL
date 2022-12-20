/* 对应教材 S5.4 编写函数 alloc 和 afree 实现一个存储分配程序 */
#define ALLOCSIZE   10000           // 可用空间大小

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

/* 分配大小为 n 的空间 返回空间的首地址 */
void *alloc(int n) {
    void *result = allocp;
    allocp += n;
    return (allocp <= allocbuf + ALLOCSIZE) ? result : 0;
}

/* 释放 p 指向的存储区 */
void afree(void *p) {
    if ((char *) p < allocbuf + ALLOCSIZE && (char *) p >= allocbuf)
        allocp = p;
}