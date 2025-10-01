#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha {
    char tipo;
    struct pilha *next;
} pilha;

pilha* create(char valor) {
    pilha *novo = malloc(sizeof(pilha));
    if (novo == NULL) {
        exit(EXIT_FAILURE);
    }
    novo->tipo = valor;
    novo->next = NULL;
    return novo;
}

void push(char valor, pilha **top) {
    pilha *novo = create(valor);
    novo->next = *top;
    *top = novo;
}

void pop(pilha **top) {
    if (*top == NULL) return;
    pilha *aux = *top;
    *top = aux->next;
    free(aux);
}

void free_all(pilha **top) {
    while (*top != NULL) {
        pop(top);
    }
}

int CheckString(const char *str) {
    pilha *top = NULL;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c == '(') {
            push(c, &top);
        } else if (c == ')') {
            if (top == NULL) {
                free_all(&top);
                return 0;
            }
            pop(&top);
        }
    }

    int result = (top == NULL ? 1 : 0);
    free_all(&top);
    return result;
}

int main() {
    char str[1001];

    while (fgets(str, sizeof(str), stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';

        if (CheckString(str)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
