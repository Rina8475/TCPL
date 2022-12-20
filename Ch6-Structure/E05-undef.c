/* 练习 6-5 编写函数 undef 对于程序 P03 它将由 lookup 和 install 维护的表中删除一个变量名及其定义 */
#include <stdlib.h>
#include <string.h>
struct node{
    char *name;
    char *defn;
    struct node *next;
};

unsigned hash(char *s);

extern struct node *hashtab[];

/* 在哈希表中查找名字 s 对应的项 并从哈希表中删除该项 */
void undef(char *s) {
    int h = hash(s);
    struct node *temp, *head = hashtab[h];
    struct node *pnode = (struct node *) malloc(sizeof(struct node *));
    pnode->next = head;
    head = pnode;               // 保存 链表的开始位置

    for (; pnode->next != NULL && strcmp(s, pnode->next->name) != 0; pnode = pnode->next);
    if (pnode->next != NULL) {  // 删除链表元素
        temp = pnode->next;
        pnode->next = pnode->next->next;
        free(temp->name);   free(temp->defn); free(temp);
    }
    pnode = head;
    head = head->next;          // 链表现在的头节点
    hashtab[h] = head;
    free(pnode);
}