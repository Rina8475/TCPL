/* 练习 6-3 编写程序 打印输入文档中的所有单词的列表 并且每个单词还有一个列表
   记录出现过该单词的行号 
   此程序在 linux 上能够正常运行 反正就是在 windows 上不能运行 (gdb 调了半天发现程序是正常的)
   md 玄学问题 可能和 windows 下的 shell 有关吧。。 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXWORD 100

struct node {           // 链表节点
    int line;
    struct node *next;
};

struct tnode {
    char *word;
    struct node *list;
    struct tnode *left;
    struct tnode *right;
};

int getword(char *word, int lim);
struct tnode *addtree(struct tnode *root, char *word, int line);
void treeprint(struct tnode *root);

int main(void) {
    struct tnode *root = NULL;
    char word[MAXWORD];
    int line = 1;

    while (getword(word, MAXWORD) != EOF) 
        if (isalpha(word[0]))
            root = addtree(root, word, line);
        else if (word[0] == '\n')  line++;
    treeprint(root);
    return 0;
}

/* 从输入中读取下一个单词 单词可以是以字母开头的字母和数字串 也可以是一个非空白字符
   相比于 P01 中的 getword 函数 此函数可以返回 '\n' 用于计算行号
   函数返回值可以是单词的第一个字符 文件结束符 EOF 或字符本身 */
int getword(char *s, int lim) {
    int c, getch(void);
    void ungetch(int c);
    char *w = s;

    while ((c = getch()) == ' ' || c == '\t');
    if (c != EOF)   *w = c;
    if (!isalpha(c)) {
        *++w = '\0';
        return c;
    }
    while (--lim > 0 && isalnum(*++w = c = getch())); 
    ungetch(c);
    *w = '\0';
    return s[0];
}

/* 将对应结点插入树中 若树中已存在此结点 则在结点的链表中插入元素 */
struct tnode *addtree(struct tnode *p, char *w, int n) {
    int cond;
    void addline(struct tnode *, int);

    if (p == NULL) {
        p = (struct tnode *) malloc(sizeof(struct tnode *));
        p->list = (struct node *) malloc(sizeof(struct node *));
        p->list->line = n;
        p->list->next = NULL;
        p->left = p->right = NULL;
        p->word = strdup(w);
    } else if ((cond = strcmp(w, p->word)) < 0)
        p->left = addtree(p->left, w, n);
    else if (cond > 0)
        p->right = addtree(p->right, w, n);
    else    addline(p, n);
    return p;
}

/* 为结点 p 的链表中插入新的行数 注意 p 的链表不可能为空 */
void addline(struct tnode *p, int n) {
    struct node *ptr = p->list;
    while (ptr->next != NULL && ptr->line != n)
        ptr = ptr->next;
    if (ptr->line != n) {
        ptr->next = (struct node *) malloc(sizeof(struct node *));
        ptr->next->line = n;
        ptr->next->next = NULL;
    }
}

/* 按照中序遍历将树中的所有结点打印出来 包括每个结点的列表 */
void treeprint(struct tnode *p) {
    struct node *temp;
    
    if (p == NULL)  return;
    treeprint(p->left);
    printf("%10s ", p->word);
    for (temp = p->list; temp != NULL; temp = temp->next)
        printf("%4d ", temp->line);
    putchar('\n');
    treeprint(p->right);
}