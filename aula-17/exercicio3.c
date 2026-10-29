#include <stdio.h>
#include <string.h>

int main() {
    char nome[50], nomeCopia[50], codigo[10], mensagem[100];

    printf("Digite o primeiro nome do estudante: ");
    scanf("%49s", nome);

    printf("Digite o codigo do curso (CC ou SI): ");
    scanf("%9s", codigo);

    int quantidade = strlen(nome);

    strcpy(nomeCopia, nome);

    strcpy(mensagem, "Ola, ");
    strcat(mensagem, nomeCopia);
    strcat(mensagem, "!");

    printf("\nDados do Estudante\n");
    printf("Nome: %s\n", nomeCopia);

    if (strcmp(codigo, "CC") == 0) {
        printf("Curso: Ciencia da Computacao\n");
    } else if (strcmp(codigo, "SI") == 0) {
        printf("Curso: Sistemas de Informacao\n");
    } else {
        printf("Curso invalido\n");
    }

    printf("Quantidade de caracteres do nome: %d\n", quantidade);
    printf("Mensagem: %s\n", mensagem);

    return 0;
}