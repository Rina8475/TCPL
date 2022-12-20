/* 对应教材 S8.6 编写程序 fsize 打印命令行参数中所指定的所有文件长度 */
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "P03-fsize.h"

void fsize(char *filename);

/* 程序 fsize 打印命令行参数中所指定的所有文件长度 如果其中一个文件是目录
   则程序对此目录递归调用自身 如果命令行中没有任何参数 则程序默认处理当前目录 */
int main(int argc, char *argv[]) {
    if (argc == 1) 
        fsize(".");
    else 
        while (--argc > 0)
            fsize(*++argv);
    return 0;
}

/* 打印输入文件的文件名 */
void fsize(char *name) {
    struct stat buf;

    if (stat(name, &buf) < 0) {         // 文件不存在
        fprintf(stderr, "fsize: cannot access %s\n", name);
        return;
    }
    if ((buf.st_mode & S_IFMT) == S_IFDIR)    // 文件是一个目录
        dirwalk(name, fsize);
    printf("%8ld %s", buf.st_size, name);
}

#include <string.h>
#define MAX_PATH  1024

/* 对 dir 中的所有文件调用函数 fcn */
void dirwalk(char *dir, void (*fcn)(char *)) {
    char name[MAX_PATH];
    Dirent *info;
    DIR *dfd;

    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: cannot open %s\n", dir);
        return;
    }
    while ((info = readdir(dfd)) != NULL) {
        if (strcmp(info->name, ".") == 0 || strcmp(info->name, "..") == 0)      // 跳过自身和父目录
            continue;
        if (strlen(dir) + strlen(info->name) + 2 < sizeof(name)) 
            fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, info->name);
        else {
            sprintf(name, "%s/%s", dir, info->name);
            (*fcn)(name);
        }
    }
    closedir(dfd);
}