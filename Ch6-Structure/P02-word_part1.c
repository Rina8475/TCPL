/* 对应教材 S6.5 编写一个程序统计输入中的所有单词的出现次数
   采用数据结构 tree 
   part_1 main 函数实现 */
#include <stdio.h>
#include <ctype.h>
#define MAXWORD 100

struct tnode {
    int count;                  // 单词出现的次数
    char *word;                 // 指向单词的指针
    struct tnode *right;
    struct tnode *left;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int );

int main(void) {
    char word[MAXWORD];
    struct tnode *root = NULL;

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))   
            root = addtree(root, word);
    
    treeprint(root);
    return 0;
}