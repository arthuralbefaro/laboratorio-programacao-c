#include <stdio.h>

int main(void) {
    int assentos[3][4] = {
        {1, 0, 1, 1},
        {0, 0, 1, 0},
        {1, 1, 0, 0}
    };
    int ocupados = 0;
    int disponiveis = 0;

    printf("Mapa dos assentos (0 = disponivel, 1 = ocupado):\n");
    for (int i = 0; i < 3; i++) {
        printf("Fileira %d: ", i + 1);
        for (int j = 0; j < 4; j++) {
            printf("%d ", assentos[i][j]);

            if (assentos[i][j] == 1) {
                ocupados++;
            } else {
                disponiveis++;
            }
        }
        printf("\n");
    }

    printf("\nAssentos ocupados: %d\n", ocupados);
    printf("Assentos disponiveis: %d\n", disponiveis);

    return 0;
}
