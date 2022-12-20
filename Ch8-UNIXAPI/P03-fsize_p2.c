/* 对应教材 S8.6 编写程序 fsize 打印命令行参数中所指定的所有文件长度 
   part 2 dirent 结构实现 */
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/dir.h>
#include "P03-fsize.h"

DIR *opendir(char *name) {
    int fd;
    struct stat stbuf;
    DIR *dp;

    if ((fd = open(name, O_RDONLY)) == -1 
      || fstat(fd, &stbuf) < 0
      || (stbuf.st_mode & S_IFMT) != S_IFDIR
      || (dp = (DIR *) malloc(sizeof(DIR))) == NULL)
        return NULL;
    dp->fd = fd;
    return dp;
}

Dirent *readdir(DIR *dp) {
    struct direct dirbuf;       // 操作系统提供的本地目录结构
    static Dirent d;            // 返回可移植的目录结构

    while (read(dp->fd, &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf)) {
        if (dirbuf.d_ino == 0)          // 目录位置未使用
            continue;
        d.ino = dirbuf.d_ino;
        strncpy(d.name, dirbuf.d_name, NAME_MAX);
        d.name[NAME_MAX] = '\0';
        return &d;                      // 仰望高端玩家
    }
    return NULL;
}

void closedir(DIR *dp) {
    if (dp == NULL) return; 
    close(dp->fd);
    free(dp);
}