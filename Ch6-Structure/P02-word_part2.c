/* 对应教材 S6.5 编写一个程序统计输入中的所有单词的出现次数
   采用数据结构 tree 
   part_2 树的插入 树的遍历等函数实现 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
    int count;                  // 单词出现的次数
    char *word;                 // 指向单词的指针
    struct tnode *right;
    struct tnode *left;
};

/* 向树中插入节点包含字符串 s 如果已有该字符串则将对应节点的 count 域 + 1
   否则新建该节点并插入树中 
   注： 树的插入标准代码见 algorithms 4e */
struct tnode *addtree(struct tnode *p, char *s) {
    int cond;

    if (p == NULL) {                // 递归结束条件
        p = (struct tnode *) malloc(sizeof(struct tnode));
        p->word = strdup(s);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(s, p->word)) < 0)      
        p->left = addtree(p->left, s);
    else if (cond > 0)      p->right = addtree(p->right, s);
    else                    p->count++;
    return p;
}

#ifndef EXERCISE        // E02 编译时使用参数 -DEXERCISE
// /* 遍历整颗树 将所有节点打印出来 */
// void treeprint(struct tnode *p) {
//     if (p == NULL)  return;
//     treeprint(p->left);
//     printf("%4d %s\n", p->count, p->word);
//     treeprint(p->right);
// }
/* 遍历整颗树 将所有节点打印出来 */
void treeprint(struct tnode *p) {
    while (p != NULL) {                 // 采用尾递归实现
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        p = p->right;
    }
}
#endif

/* 从输入中读取下一个单词 单词可以是以字母开头的字母和数字串 也可以是一个非空白字符
   函数返回值可以是单词的第一个字符 文件结束符 EOF 或字符本身 */
int getword(char *s, int lim) {
    int c, getch(void);
    void ungetch(int c);
    char *w = s;

    while (isspace(c = getch()));
    if (c != EOF)   *w = c;
    if (!isalpha(c)) {
        *++w = '\0';
        return c;
    }
    while (--lim > 0 && isalnum(*++w = c = getch()));       // 有问题的地方是这里 ~ 
    ungetch(c);
    *w = '\0';
    return s[0];
}