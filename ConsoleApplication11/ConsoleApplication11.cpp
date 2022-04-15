#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    int rfind(char* s, char* pattern, int l, int r) {
    int i, j;
    for (i = r; i >= l; i--) {
        for (j = 0; pattern[j]; j++) {
            if (s[i] == pattern[j]) {
                return i;
            }
        }
    }
    return -1;
}

int f(char* s, int l, int r) {
    int i;
    if (((i = rfind(s, "+-", l, r)) >= 0) || (i = rfind(s, "*/", l, r)) >= 0) {
        if (s[i] == '+') {
            return f(s, l, i - 1) + f(s, i + 1, r);
        }
        else if (s[i] == '-') {
            return f(s, l, i - 1) - f(s, i + 1, r);
        }
        else if (s[i] == '*') {
            return f(s, l, i - 1) * f(s, i + 1, r);
        }
        else { // '/'
            return f(s, l, i - 1) / f(s, i + 1, r);
        }
    }
    s[r + 1] = 0;
    return atoi(&s[l]);
}

int calculate(char* s) {
    return f(s, 0, strlen(s) - 1);
}

int main(int argc, char** argv) {
    if (argc < 2) { return -1; }
    printf("answer: %d\n", calculate(argv[1]));
}