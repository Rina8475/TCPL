/* 练习 6-2 编写一个程序 按照字母表顺序分组打印变量名 每组内的各个变量名前六个字符相同 
   此方法与答案不同 采用输出时比较的方法进行输出的更改 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXWORD 100

struct tnode {
    int count;                  // 单词出现的次数
    char *word;                 // 指向单词的指针
    struct tnode *right;
    struct tnode *left;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *, int);
int getword(char *, int);

char *string = "\0";            // 储存每组内的第一个变量名的指针 用于比较 初始值需要与任何可能的字符串不同

int main(int argc, char *argv[]) {
    int n = 6;
    struct tnode *root = NULL;
    char word[MAXWORD];

    if (argc == 2 && isdigit((*++argv)[1]))
        n = atoi(++argv[0]);
    while (getword(word, MAXWORD) != EOF) 
        if (isalpha(word[0]) && strlen(word) >= n) 
            root = addtree(root, word);
    treeprint(root, n);
    return 0;
}

void treeprint(struct tnode *p, int n) {
    if (p == NULL)  return;         // 递归终止条件

    treeprint(p->left, n);
    if (strncmp(string, p->word, n) == 0)
        printf("%4d %s\n", p->count, p->word);
    else {
        printf("**********************\n");
        printf("%4d %s\n", p->count, p->word);
        string = p->word;
    }

    treeprint(p->right, n);
}