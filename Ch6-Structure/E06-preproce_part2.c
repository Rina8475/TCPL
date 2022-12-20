/* 练习 6-6 编写一个适合 C 语言的 #define 预处理器的简单版本 (无参数)
   part_2 哈希表实现 为了将之前几个程序中的有关哈希表的函数组合起来 故新建此文件 */
#include <stdlib.h>
#include <string.h>
#include "E06-preproce.h"
#define HASHSIZE 101

static struct node *hashtab[HASHSIZE];

static unsigned hash(char *s);

/* hash 的返回值和函数中的 hashval 必须为 unsigned int 型
   在计算过程中 hashval 可能会越界 如果使用 int 则会生成负值 */
static unsigned hash(char *s) {
    unsigned val;

    for (val = 0; *s != '\0'; s++)
        val = *s + val * 31;
    return val % HASHSIZE;
}

/* 将名字 s 和替换文本 t 记录到哈希表中 在插入之前用 lookup 函数判断待加入的名字是否存在
   如果已存在 则用新的定义代替旧的定义 否则创建一个新表项并插入 
   注：插入时向链表的首位插入  */
void install(char *s, char *t) {
    struct node *np, *temp;
    int h = hash(s);

    if ((np = lookup(s)) != NULL) {     // 检查哈希表中是否存在该名字
        free(np->defn);
        np->defn = strdup(t);
        return;
    } 

    np = hashtab[h];
    temp = (struct node *) malloc(sizeof(struct node *));

    temp->name = strdup(s);
    temp->defn = strdup(t);
    temp->next = np;
    hashtab[h] = temp;
}

/* 在哈希表中查找名字 s 若找到 返回指向该处的指针 否则返回 NULL */
struct node *lookup(char *s) {
    struct node *ptr = hashtab[hash(s)];
    for (; ptr != NULL && strcmp(s, ptr->name) != 0; ptr = ptr->next);
    return ptr;
}

/* 在哈希表中查找名字 s 对应的项 并从哈希表中删除该项 */
void undef(char *s) {
    int h = hash(s);
    struct node *ptr = hashtab[hash(s)];
    struct node *prev = NULL;

    for (; ptr != NULL && strcmp(s, ptr->name) != 0; prev = ptr, ptr = ptr->next);
    if (ptr != NULL) {              // 已查找到元素
        if (prev == NULL)   hashtab[h] = ptr->next;     // 元素为链表头结点
        else         prev->next = prev->next->next;     // 
        free(ptr->name);    free(ptr->defn);    free(ptr);
    }        
}