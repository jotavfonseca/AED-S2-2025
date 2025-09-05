#include <stdio.h>

int main () {
    int n;
    int x[1000];
    int *ptr = x;  // ponteiro para o início do vetor
    int menor;
    int pos;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", ptr + i);  // leitura diretamente com ponteiro
    }

    menor = *ptr;  // valor do primeiro elemento
    pos = 0;

    for (int i = 0; i < n; i++) {
        if (*(ptr + i) < menor) {
            menor = *(ptr + i);
            pos = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", pos);

    return 0;
}
