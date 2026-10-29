#include <stdio.h>
#include <string.h>

int main()
{
    char nome[50];
    char perfil[20];
    char confirmacao[50];
    char descricaoPerfil[30];
    char mensagem[100] = "Bem-vindo(a), ";
    int tamanho;

    printf("CADASTRO DE USUARIOS");

    printf("Digite seu nome: ");
    scanf("%49s", nome);

    printf("Digite seu perfil: ");
    scanf("%19s", nome);

    tamanho = strlen(nome);

    if (strcmp(perfil, "ADMIN") == 0) {
        strcpy(descricaoPerfil, "Administrador");
    } else if (strcmp(perfil, "COMUM") == 0) {
        strcpy(descricaoPerfil, "Usuario Comum");
    } else {
        printf("\nPerfil invalido! Use ADMIN ou COMUM.\n");
        return 1;
    }

    strcpy(confirmacao, nome);

    strcat(mensagem, confirmacao);
    strcat(mensagem, "!");

    printf("DADOS CADASTRADOS");
    printf("Nome: %s\n", confirmacao);
    printf("Quantidade de caracters: %d", tamanho);
    printf("Perfil: %s", descricaoPerfil);

    printf("\n%s\n", mensagem);
    printf("Cadastro realizado com sucesso!\n");

    return 0;
}