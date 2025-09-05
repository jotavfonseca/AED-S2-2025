#include <stdio.h>

int main () {
    int n;
    int x[1000];
    int num;
    int menor;
    int pos;

    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%d", &num);
        x[i] = num;
    }

    menor = x[0];
    pos = 0;
    for (int i = 0; i < n; i++){
        if (menor > x[i]){
            menor = x[i];
            pos = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", pos);  // \n no final, por precaução
    return 0;
}
