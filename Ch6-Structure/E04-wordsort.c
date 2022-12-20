/* 练习 6-4 编写程序读取输入流中的单词 并按照单词出现频率降序打印出来 
   调试到的玄学问题：
   如果各个文件中使用了同一结构体 则必须保持结构体完全相同 否则在指向其域时偏移量会不同
   ps. 再度说明了将结构体放到头文件的重要性。。。 */
#include <stdio.h>
#include <ctype.h>
#define MAXWORD  100
#define DISTINCT 1000   // 最大所能排序的单词数目

struct tnode {
    int count;                  // 单词出现的次数
    char *word;                 // 指向单词的指针
    struct tnode *right;
    struct tnode *left;
};

int getword(char *, int);
struct tnode *addtree(struct tnode *, char *);
void treestore(struct tnode *);
void listsort(void);

struct tnode *treelist[DISTINCT];
int listp = 0;

int main(void) {
    struct tnode *root = NULL;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF) 
        if (isalpha(word[0])) 
            root = addtree(root, word);
    treestore(root);
    listsort();
    for (int i = 0; i < listp; i++)
        printf("%4d %10s\n", treelist[i]->count, treelist[i]->word);
    return 0;
}

/* 将树中的所有节点存储到一个列表中 */
void treestore(struct tnode *p) {
    if (p == NULL) return;
    treestore(p->left);
    treelist[listp++] = p;
    treestore(p->right);
}

/* 对 treelist 进行排序 数组长度由 listp 给出 */
void listsort(void) {
    int compare(struct tnode *, struct tnode *);
    void qsort(void *[], int, int, int (*)(void *, void *));

    qsort((void **) treelist, 0, listp-1, (int (*)(void *, void *)) compare);
}

void qsort(void *a[], int lo, int hi, int (*comp)(void *, void *)) {
    int mid, partition(void *[], int, int, int (*)(void *, void *));

    if (hi <= lo)   return;
    mid = partition(a, lo, hi, comp);
    qsort(a, lo, mid-1, comp);
    qsort(a, mid+1, hi, comp);
}

int partition(void *a[], int lo, int hi, int (*comp)(void *, void *)) {
    void *val = a[hi], exch(void *[], int, int);
    int i = lo, j = lo-1;

    while (++j < hi) 
        if ((*comp)(a[j], a[hi]) < 0) 
            exch(a, j, i++);
    exch(a, i, hi);
    return i;
}

void exch(void *v[], int i, int j) {
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int compare(struct tnode *m, struct tnode *n) {
    return m->count - n->count;
}