/* 对应教材 S5.11 编写一个排序程序 在给定参数 -n 的情况下 函数将按照数值大小而非字典顺序对输入行进行排序 
   part_2 编写一个所有类型通用的快速排序 */
int partition(void *v[], int lo, int hi, int (*comp)(void *, void *));

/* 所有类型都通用的快速排序 对于不同的类型 只需要重新定义 comp 函数 */
void qsort(void *v[], int lo, int hi, 
           int (*comp) (void *, void *)) {
    if (hi <= lo)   return;
    int mid = partition(v, lo, hi, comp);
    qsort(v, lo, mid-1, comp);
    qsort(v, mid+1, hi, comp);
}

int partition(void *v[], int lo, int hi, 
              int (*comp) (void *, void *)) {
    void *val = v[hi], exch(void *v[], int i, int j);
    int i = lo, j = lo - 1;

    while (++j < hi) 
        if ((*comp)(v[j], val) < 0) 
            exch(v, j, i++);
    exch(v, i, hi);
    return i;
}

void exch(void *v[], int i, int j) {
    void *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}