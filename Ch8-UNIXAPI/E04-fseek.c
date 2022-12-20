/* 练习 8-4 设计标准库函数 fseek */
#include <unistd.h>
#include "P02-filefunc.h"

/* fseek 函数设置流 fp 的文件位置 后续的读写操作将从新位置开始 
   函数出错则返回一个非 0 值 */
int fseek(FILE *fp, long offset, int orgin) {
    off_t rc = 0;
    
    if (fp->flag & _READ) {
        if (orgin == SEEK_CUR) 
            offset -= fp->cnt;          // 仰望高端玩家        
        rc = lseek(fp->fd, offset, orgin);
        fp->cnt = 0;
    } else if (fp->flag & _WRITE) {
        rc |= _flushbuf(0, fp);
        rc |= lseek(fp->fd, offset, orgin);
    }
    return (int) rc;
}