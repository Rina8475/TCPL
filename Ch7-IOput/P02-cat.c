/* 对应教材 S7.5 编写程序 cat 将命令行中输入的多个文件连接到一起 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    void filecopy(FILE *, FILE *);

    if (argc == 1) filecopy(stdout, stdin);
    else 
        while (--argc > 0) {
            if ((fp = fopen((++argv)[0], "r")) == NULL) {
                fprintf(stderr, "error: cannot open file %s\n", argv[0]);
                exit(1);
            }
            filecopy(stdout, fp);
            fclose(fp);
        }
    return 0;
}

/* 将文件 src 复制到 des */
void filecopy(FILE *des, FILE *src) {
    int c;

    while ((c = getc(src)) != EOF) 
        putc(c, des);
}