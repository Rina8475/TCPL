/* 练习 6-6 编写一个适合 C 语言的 #define 预处理器的简单版本 (无参数)
   part_1 main 函数 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "E06-preproce.h"
#define MAXWORD 100
#define STRUCT 256      // 这些常数的值不能和已有的 ASCII 码重复
#define STRING 257

int getch(void);
void ungetch(int c);

int getword(char *name, int lim);
void comment(void);

int main(void) {
   struct node *ptr;
   char word[MAXWORD];
   char defn[MAXWORD];
   int c;

   while ((c = getword(word, MAXWORD)) != EOF) 
      if (c == STRUCT) {
         if (strcmp(word, "define") == 0 && getword(word, MAXWORD) == STRING && getword(defn, MAXWORD) == STRING) 
            install(word, defn);
      } else if (c == STRING) 
         if ((ptr = lookup(word)) != NULL)   // printf(((ptr = lookup(word)) == NULL) ? word : ptr->defn);
            printf(ptr->defn);               // 不行 三元操作符并不是短路的
         else printf(word);
      else putchar(c);
   return 0;
}

/* 重新编辑的版本 识别输入流中的字符串或预处理器指令 以及其他字符 */
int getword(char *s, int m) {
   int c, d;

   while (isspace(*s = c = getch()));     // 除去空白符
   if (c == '/')                          // 判断是否是注释
      if ((d = getch()) == '*') {
         comment();              // 去除注释
         return getword(s, m);
      } else ungetch(d); 
   else if (c == '#') {                // 是预指令
      for (; isalpha(*s = c = getch()); s++);
      *s = '\0';
      ungetch(c);
      return STRUCT;
   } else if (isalpha(c)) {            // 是字符串
      while (isalpha(*++s = c = getch()));
      *s = '\0';
      ungetch(c);
      return STRING;
   } else return c;
}

/* 出去输入流中的注释 */
void comment(void) {
   int c;

   while ((c = getch()) != EOF)
      if (c == '*')
         if ((c = getch()) == '/')
            break;
         else ungetch(c);
   if (c == EOF)  ungetch(c);
}