/* 练习 6-6 中 文件 E06-preproce_part2.c 的头文件 可作为哈希表的头文件 */
#define HASHSIZE 101        // 哈希表的长度

// 哈希表表项结点
struct node{
    char *name;
    char *defn;
    struct node *next;
};

void install(char *name, char *defn);
struct node *lookup(char *name);
void undef(char *name);