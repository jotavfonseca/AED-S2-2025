#include <stdio.h>

int main() {
    int nc;
    scanf("%d", &nc);

    while (nc--) {
        int n, h;
        int cont[231] = {0};

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &h);
            cont[h]++;
        }

        int printed = 0;
        for (int i = 20; i <= 230; i++) {
            while (cont[i]--) {
                if (printed++) printf(" ");
                printf("%d", i);
            }
        }
        printf("\n");
    }

    return 0;
}
