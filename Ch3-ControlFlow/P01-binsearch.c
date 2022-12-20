/* 对应于教材 S3.3 编写 binsearch 函数 */
int binsearch(int x, int v[], int n);

/* 二分查找 在数组 v 中查找元素 x， n 为数组长度 */
int binsearch(int x, int v[], int n) {
    int lo = 0, hi = n-1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if      (x < v[mid]) hi = mid - 1;
        else if (x > v[mid]) lo = mid + 1;
        else return mid;
    }
    return -1;
}