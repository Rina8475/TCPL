/* 对应教材 S6.6 编写一个符号表的 API 包括 install 和 lookup 函数
   此符号表用链表法实现 哈希函数使用取余法实现 */
#include <stdlib.h>
#include <string.h>
#define HASHSIZE 101        // 哈希表的长度

struct node{
    char *name;
    char *defn;
    struct node *next;
};

struct node *hashtab[HASHSIZE];

/* hash 的返回值和函数中的 hashval 必须为 unsigned int 型
   在计算过程中 hashval 可能会越界 如果使用 int 则会生成负值 */
unsigned hash(char *s) {
    unsigned int a;         // hashval

    for (a = 0; *s != '\0'; s++)
        a = *s + 31 * a;
    return a % HASHSIZE;
}

/* 将名字 s 和替换文本 t 记录到哈希表中 在插入之前用 lookup 函数判断待加入的名字是否存在
   如果已存在 则用新的定义代替旧的定义 否则创建一个新表项并插入 
   注：插入时向链表的首位插入  */
void install(char *s, char *t) {
    struct node *np, *temp;

    if ((np = lookup(s)) != NULL) {     // 检查哈希表中是否存在该名字
        free(np->defn);
        np->defn = strdup(t);
        return ;
    } 

    np = hashtab[hash(s)];
    temp = (struct node *) malloc(sizeof(struct node *));

    temp->name = strdup(s);
    temp->defn = strdup(t);
    temp->next = np->next;
    np->next = temp;
}

/* 在哈希表中查找名字 s 若找到 返回指向该处的指针 否则返回 NULL */
struct node *lookup(char *s) {
    struct node *ptr = hashtab[hash(s)];

    while (ptr != NULL && strcmp(ptr->name, s) != 0)
        ptr = ptr->next;
    return ptr;
}