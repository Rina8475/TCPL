/* 练习 8-3 设计并编写函数 _flushbuf fflush fclose */
#include <unistd.h>
#include <stdlib.h>
#include "P02-filefunc.h"

/* 分配并刷新缓冲区 如果文件不是以写方式打开或出错 则返回 EOF
   否则返回写入的字符 x */
int _flushbuf(int x, FILE *fp) {
    int bufsize, nc;

    if (fp->flag & (_WRITE | _ERR) != _WRITE)
        return EOF;
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if (fp->base == NULL) {
        if ((fp->base = malloc(bufsize)) == NULL) 
            return EOF;
    } else { 
        nc = fp->ptr - fp->base;
        if (write(fp->fd, fp->base, nc) != nc) {
            fp->flag |= _ERR;
            return EOF;
        }
    }
    fp->cnt = bufsize - 1;
    fp->ptr = fp->base;
    *fp->ptr++ = (char) x;
    return x;
}

/* 将已写到文件缓冲区但尚未写入文件的所有数据写入文件 
   如果在写的过程中出错 则返回 EOF 否则返回 0 */
int fflush(FILE *fp) {
    int rt = 0;

    if (fp->flag & _WRITE)
        rt = _flushbuf(0, fp);
    fp->cnt = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    fp->ptr = fp->base;
    return rt;
}

/* 将所有未写入的数据写入文件中 丢弃缓冲区中所有未读输入数据并释放自动分配的全部缓冲区
   最后关闭 fd 若出错则返回 EOF 否则返回 0 */
int fclose(FILE *fp) {
    int rc;

    if ((rc = fflush(fp)) != EOF) {
        free(fp->base);
        close(fp->fd);
        fp->flag = 0;
    }
    return 0;
}