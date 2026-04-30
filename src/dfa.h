#pragma once
#include <stdbool.h>

typedef enum {
  DfaOk, // строка разобрана корректно
  DfaErrInvalidChar, // встретился символ, отсутствующий в алфавите
  DfaErrNotAccepting // символ в алфавите есть,
                     // но из текущего состояния нельзя никуда перейти
} DfaStatus;

typedef struct {
  int from; // номер состояния, из которого мы выходим
  char symbol; // символ, при чтении которого происходит переход
  int to; // номер состояния, в которое мы попадаем
} Transition;

typedef struct {
  Transition *transitions; // указатель на массив всех возможных переходов
  int numTransitions; // количество переходов
  int *acceptStates; // указатель на массив подходящих состояний
  int numAcceptStates; // оличество подходящих состояний
  int startState; // номер состояния, с которого всё 
} Dfa;


// dfa - указатель на структуру автомата
// input - проверяемая строка
// status - сообщение о результате работы автомата

bool dfaCheck(const Dfa *dfa, const char *input, DfaStatus *status);
