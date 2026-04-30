#include "dfa.h"
#include <stdio.h>
#include <string.h>

int main() {
    Transition ts[150];
    int n = 0;

    for (int c = '0'; c <= '9'; c++) {
        ts[n++] = (Transition) { 0, (char)c, 2 };
        ts[n++] = (Transition) { 1, (char)c, 2 };
        ts[n++] = (Transition) { 2, (char)c, 2 };
        ts[n++] = (Transition) { 3, (char)c, 4 };
        ts[n++] = (Transition) { 4, (char)c, 4 };
        ts[n++] = (Transition) { 5, (char)c, 7 };
        ts[n++] = (Transition) { 6, (char)c, 7 };
        ts[n++] = (Transition) { 7, (char)c, 7 };
    }

    ts[n++] = (Transition) { 0, '+', 1 };
    ts[n++] = (Transition) { 0, '-', 1 };
    ts[n++] = (Transition) { 0, '.', 3 };
    ts[n++] = (Transition) { 1, '.', 3 };
    ts[n++] = (Transition) { 2, '.', 4 };
    ts[n++] = (Transition) { 2, 'E', 5 };
    ts[n++] = (Transition) { 2, 'e', 5 };
    ts[n++] = (Transition) { 4, 'E', 5 };
    ts[n++] = (Transition) { 4, 'e', 5 };
    ts[n++] = (Transition) { 5, '+', 6 };
    ts[n++] = (Transition) { 5, '-', 6 };

    int accept[] = { 2, 4, 7 };
    Dfa myDfa = { ts, n, accept, 3, 0 };

    char input[100];
    if (fgets(input, sizeof(input), stdin)) {
        input[strcspn(input, "\r\n")] = 0;

        DfaStatus status;
        if (dfaCheck(&myDfa, input, &status)) {
            printf("Это число :D\n");
        } else {
            printf("Это не число :(\n");
        }
    }

    return 0;
}
