#include <stdio.h>
#include <string.h>

int main() {
    char nome[100], categoria[20], nomeCopia[100], descricao[150];

    printf("Digite o nome do produto: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite a categoria (HARDWARE ou PERIFERICO): ");
    scanf("%19s", categoria);

    int quantidade = strlen(nome);

    strcpy(nomeCopia, nome);

    strcpy(descricao, "Produto: ");
    strcat(descricao, nomeCopia);

    printf("\nResumo do Cadastro\n");
    printf("Nome: %s\n", nomeCopia);
    printf("Categoria: ");

    if (strcmp(categoria, "HARDWARE") == 0) {
        printf("Hardware\n");
    } else if (strcmp(categoria, "PERIFERICO") == 0) {
        printf("Periferico\n");
    } else {
        printf("Categoria invalida\n");
    }

    printf("Quantidade de caracteres: %d\n", quantidade);
    printf("Descricao: %s\n", descricao);

    return 0;
}