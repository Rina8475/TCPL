/* 练习 7-6 编写一个程序 比较两个文件并打印他们第一个不相同的行 
   文件名由命令行输入 nmlgb 读个文件有一半的语句都在判错 判 nmlgder */
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int main(int argc, char *argv[]) {
    FILE *fp1, *fp2;
    void filecomp(FILE *fp1, FILE *fp2);
    char line1[MAXLINE], line2[MAXLINE];

    if (argc != 3) {
        fprintf(stderr, "error: need two file name\n");
        exit(1);
    }

    if ((fp1 = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "error: file %s cannot open\n", argv[1]);
        exit(1);
    } else if ((fp2 = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "error: file %s cannot open\n", argv[2]);
        exit(1);
    }
    filecomp(fp1, fp2);
    fclose(fp1);    fclose(fp2);
    return 0;
}

/* 比较两个文件中的各行 并打印出它们第一个不相同的行 */
void filecomp(FILE *fp1, FILE *fp2) {
    char line1[MAXLINE], line2[MAXLINE];
    char *lp1, *lp2;

    do {
        if (fgets(line1, MAXLINE, fp1) == NULL) {
            printf("end of first file at line\n%s\n", line1);
            exit(1);
        } else if (fgets(line2, MAXLINE, fp2) == NULL) {
            printf("end of second file at line \n%s\n", line2);
            exit(1);
        }
    } while(strcmp(line1, line2) == 0);
    printf("first diffenrence in line\n%s\n", line1);
}