#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int reverse(char *str);
int exch(char *s, int i, int j);

int main(void) {
    char line[] = "Hello world!";
    reverse(line);
    printf("%s", line);
    return 0;
}

int reverse(char *str) {
    int i = 0, j = strlen(str)-1;
    while (i < j)
        exch(str, i++, j--);
}

int exch(char *s, int i, int j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}