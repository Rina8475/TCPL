/* 练习 6-1 修改程序 P01-keyword 中的 getword 函数 使之能处理注释等字符
   不能理解为什么答案里面遇到注释会返回 '/' 待补 */
#include <stdio.h>
#include <ctype.h>
#define ISWORDH(x)  (isalpha(x) || (x) == '_')
#define ISDIGIT(x)  (isdigit(x) || (x) == '.')

int getch(void);
void ungetch(int c);

/* 从输入中读取下一个标记 标记包括 单词 字符串常量 预处理控制指令 数字
   单词可以是以字母或 _ 开头的字母和数字串      返回值 WORD
   字符串常量即被 " " 所包裹的所有字符串        返回值 STRING
   预处理控制指令即以 # 开头的一行              返回值 PREC
   数字即由数字和 . 组成 最多包含一个 .         返回值 DIGIT
   其余字符则以单个字符的形式返回               返回值 OTHER
   若为 EOF 则直接返回 EOF
   可以正确处理注释 遇到注释直接略过
   函数返回值可以是单词的第一个字符 文件结束符 EOF 或字符本身 */
int getword(char *s, int lim) {
    int c;

    while (isspace(*s = c = getch()));
    if (c == EOF)   return EOF;
    if (c == '/')               // 如果是注释 则略过
        if ((c = getch()) != '*') {
            ungetch(c);
            return '/';
        } else if (comment() == EOF)   return EOF;
    
    if (ISWORDH(c) || c == '#') {
        while (--lim > 0 && (isalnum(*++s = getch()) || *s == '_'));
        ungetch(*s);
        *s = '\0';
        // return
    }
    if (ISDIGIT(c)) {
        if (isdigit(*s))
            while (--lim > 0 && isdigit(*++s = getch()));
        if (*s == '.')
            while (--lim > 0 && isdigit(*++s = getch()));
        ungetch(*s);
        *s = '\0';
    }
    if (c == '"' || c == '\'') {
        while (--lim > 0 && (*++s = getch()) != c && *s != EOF);
        if (c == EOF)
            printf("error");
    }
    return c;
}

/* 跳过注释的剩余部分 */
int comment(void) {
    int c;

    while ((c = getch()) != EOF)
        if (c == '*')
            if ((c = getch()) != '/')
                ungetch(c);
            else break;
    return c;
}