/* 对应教材 S8.5 标准函数库中 fopen 和 getc 函数的实现 */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "P02-filefunc.h"
#define PERMS 0666

FILE _iob[OPEN_MAX] = {
    {0, (char *) 0, (char *) 0, _READ,  0},
    {0, (char *) 0, (char *) 0, _WRITE, 1},
    {0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2}
};

/* fopen 函数：打开文件 并返回文件指针 当前版本仅识别 "r" "a" "w" 三种模式 */
FILE *fopen(char *name, char *mode) {
    int fd;
    FILE *fp;

    if (mode[0] != 'r' || mode[0] != 'w' || mode[0] != 'a')
        return NULL;
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if (fp->flag & (_READ | _WRITE) == 0)
            break;
    if (fp >= _iob + OPEN_MAX)  return NULL;

    if (mode[0] == 'a') {
        if ((fd = open(name, O_WRONLY, 0)) < 0) 
            fd = creat(name, PERMS);
        lseek(fd, 0L, 2);
    } else if (mode[0] == 'w') 
        fd = creat(name, PERMS);
    else 
        fd = open(name, O_RDONLY, 0);
    if (fd == -1)   return NULL;            // 仰望高端玩家 不能访问名字
    fp->fd = fd;
    fp->base = NULL;
    fp->cnt = 0;
    fp->flag = (*mode == 'r') ? _READ : _WRITE;
    return fp;
}

/* 分配并充填缓冲区 如果文件不是以读方式打开 则返回 EOF */
int _fillbuf(FILE *fp) {
    int bufsize;

    if (fp->flag & (_READ | _EOF | _ERR) != _READ) 
        return EOF;
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if (fp->base == NULL && (fp->base = (char *) malloc(bufsize)) == NULL)
        return EOF;
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->base, bufsize);
    if (--fp->cnt < 0) {
        fp->flag |= (fp->cnt == -1) ? _EOF : _ERR;
        fp->cnt = 0;
        return EOF; 
    }
    return (unsigned char) *fp->ptr++;
}