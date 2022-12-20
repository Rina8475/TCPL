/* 对应教材 S8.6 编写程序 fsize 打印命令行参数中所指定的所有文件长度 
   dirent 结构头文件部分 */
#define NAME_MAX    14  /* 最长文件名 由具体的系统决定 */

typedef struct {                /* 可移植的目录项 */
    long ino;                   /* i 结点编号 */
    char name[NAME_MAX+1];      /* 文件名加结束符 '\0' */
} Dirent;

typedef struct {
    int fd;
    Dirent d;
} DIR;

/* opendir: 打开目录供 readdir 函数使用 */
DIR *opendir(char *dirname);
/* readdir: 按顺序读取目录项 */
Dirent *readdir(DIR *dfd);
/* closedir: 关闭由 opendir 函数打开的目录 */
void closedir(DIR *dfd);