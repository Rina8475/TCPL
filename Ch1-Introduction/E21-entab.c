/* 练习 1-21 编写程序 entab 将空格串替换为最少数量的制表符和空格符 
   且保持单词之间的间隔不变 */
#include <stdio.h>
#define TAB2SPACE 8
#define IN  1
#define OUT 0
#define UPROUND(x, y)   ((x) + (y) - 1) / (y)       // x / y 取上整

int space2tab(int index, int amount);
int putChar(char c, int times);
// int main(void) {
//     int c;
//     for (int i = 0; (c = getchar()) != EOF; i++) 
//         if      (c == '\n')     i = -1;
//         else if (c == '\b')     i -= 2;
//         else if (c == ' ')      
// }

int main(void) {
    int c, i = 0, cnt;

    do {
        for (cnt = 0; (c = getchar()) == ' ' && c != EOF; cnt++, i++);
        ungetc(c, stdin);
        space2tab(i, cnt);
        while ((c = getchar()) != ' ' && c != EOF) {
            if      (c == '\n')     i = -1;
            else if (c == '\b')     i -= 2;
            putchar(c);
            i++;
        }
        ungetc(c, stdin);
    } while (c != EOF);
    return 0;
}

int space2tab(int idx, int amn) {
    int min = (idx / TAB2SPACE + 1) * TAB2SPACE;      // 当前位置 tab 一次所到的位置
    if (amn < min-idx)  {                   // 输出对应 space
        putChar(' ', amn);
        return 0;
    }
    int tab = (amn + idx - min) / TAB2SPACE;
    int space = (amn + idx - min) - tab * TAB2SPACE;
    putChar('\t', tab+1);
    putChar(' ', space);
}

int putChar(char c, int x) {
    for (int i = 0; i < x; i++)
        putchar(c);
}