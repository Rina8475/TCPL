#include <stdio.h>
#include <stdlib.h>

void Exit(char *err, int x);

/* 按字符顺序比较字符串 s1 和 s2 */
int numcmp(char *s1, char *s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if      (v1 < v2)    return -1;
    else if (v1 > v2)   return 1;
    return 0;
}

/* wrapped function */
void *Malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL)    Exit("error: malloc a null ptr\n", 1);
    return ptr;
}

/* wrapped function */
void Exit(char *err, int x) {
    fprintf(stderr, err);
    exit(x);
}