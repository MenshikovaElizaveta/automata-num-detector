#include "dfa.h"

bool dfaCheck(const Dfa *dfa, const char *input, DfaStatus *status) {
    int currentState = dfa->startState;
    *status = DfaOk;

    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        bool found = false;

        for (int j = 0; j < dfa->numTransitions; j++) {
            if (dfa->transitions[j].from == currentState && dfa->transitions[j].symbol == c) {
                currentState = dfa->transitions[j].to;
                found = true;
                break;
            }
        }

        if (!found) {
            *status = DfaErrInvalidChar;
            return false;
        }
    }

    for (int i = 0; i < dfa->numAcceptStates; i++) {
        if (currentState == dfa->acceptStates[i]) {
            return true;
        }
    }

    return false;
}
