#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float salario;
} Funcionario;

int main() {
    Funcionario funcionario1, funcionario2;
    float diferenca;

    printf("Cadastro do Funcionario 1\n");
    printf("Nome: ");
    scanf(" %49[^\n]", funcionario1.nome);
    printf("Idade: ");
    scanf("%d", &funcionario1.idade);
    printf("Salario: ");
    scanf("%f", &funcionario1.salario);

    printf("Cadastro do Funcionario 2\n");
    printf("Nome: ");
    scanf(" %49[^\n]", funcionario2.nome);
    printf("Idade: ");
    scanf("%d", &funcionario2.idade);
    printf("Salario: ");
    scanf("%f", &funcionario2.salario);

    printf("\nDados cadastrados\n");
    printf("Funcionario 1: %s | Idade: %d | Salario: %.2f\n", funcionario1.nome, funcionario1.idade, funcionario1.salario);
    printf("Funcionario 2: %s | Idade: %d | Salario: %.2f\n", funcionario2.nome, funcionario2.idade, funcionario2.salario);

    printf("\nResultado\n");
    if (funcionario1.salario > funcionario2.salario) {
        diferenca = funcionario1.salario - funcionario2.salario;
        printf("%s possui o maior salario\n", funcionario1);
        printf("Diferenca salarial: R$ %.2f", diferenca);
    } else if (funcionario2.salario > funcionario1.salario) {
        diferenca = funcionario2.salario - funcionario1.salario;
        printf("%s possui o maior salario\n", funcionario2);
        printf("Diferenca salarial: R$ %.2f", diferenca);
    } else {
        printf("Os dois funcionarios recebem o mesmo salario\n");
    }

    return 0;
}