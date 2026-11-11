#include <stdio.h>
#include <string.h>

// definicoes de constantes pra facilitar minha vida e n ter q ficar declarando um monte de variavel
#define MAX_PACIENTES 5
#define TAM_NOME 50
#define NUM_FATORES 13

// exibição do titulo entre "=" igual ao exemplo
void exibirCabecalho(const char titulo[])
{
    printf("\n========================================\n");
    printf("      %s\n", titulo);
    printf("========================================\n\n");
}

// le o nome e os fatores de risco, dps ele recebe a linha da matriz de nomes, de fatores e o numero do paciente p exibir na tela dps
void lerPaciente(char nome[], float fatores[], int numero)
{
    // vetor de strings com as perguntas
    const char *perguntas[NUM_FATORES] = {
        "Idade: ",
        "Pressao arterial sistolica (mmHg): ",
        "Tabagismo (1-Sim / 0-Nao): ",
        "Diabetes (1-Sim / 0-Nao): ",
        "Historico de doenca cardiaca (1-Sim / 0-Nao): ",
        "Colesterol LDL (mg/dL): ",
        "Peso (kg): ",
        "Altura (m): ",
        "Sedentarismo (1-Sim / 0-Nao): ",
        "Alimentacao rica em ultraprocessados (1-Sim / 0-Nao): ",
        "Estresse cronico elevado (1-Sim / 0-Nao): ",
        "Sono inadequado (1-Sim / 0-Nao): ",
        "Sexo biologico masculino (1-Sim / 0-Nao): "
    };
    int i; // gosto de declarar antes do for

    // lê o nome com espaços
    printf("\nPaciente %d: ", numero);
    scanf(" %[^\n]", nome);

    // percorre as perguntas e guarda a resposta na posiçao correta
    for (i = 0; i < NUM_FATORES; i++) {
        printf("  %s", perguntas[i]);
        scanf("%f", &fatores[i]);
    }
}

// calcula o IMC
float calcularIMC(float peso, float altura)
{
    return peso / (altura * altura);
}

// calcula a pontuação total do risco de um paciente
int calcularPontuacao(float fatores[])
{
    int pontuacao = 0;
    int i;

    // fatores criticos
    if (fatores[0] >= 65) pontuacao += 3;
    if (fatores[1] >= 160) pontuacao += 3;
    if (fatores[2] == 1) pontuacao += 3;

    // moderados
    if (fatores[3] == 1) pontuacao += 2;
    if (fatores[4] == 1) pontuacao += 2;
    if (fatores[5] >= 160) pontuacao += 2;
    if (calcularIMC(fatores[6], fatores[7]) >= 30) pontuacao += 2;

    // leves
    for (i = 8; i < NUM_FATORES; i++) {
        if (fatores[i] == 1) pontuacao += 1;
    }

    return pontuacao;
}

// converte a pontuação na classificacao e copia o texto para a string recebida
void classificarRisco(int pontuacao, char classificacao[])
{
    if (pontuacao <= 4) strcpy(classificacao, "Menor de 10%");
    else if (pontuacao <= 9) strcpy(classificacao, "Entre 10% e 20%");
    else if (pontuacao <= 14) strcpy(classificacao, "Entre 20% e 30%");
    else if (pontuacao <= 18) strcpy(classificacao, "Entre 30% e 50%");
    else strcpy(classificacao, "Acima de 50%");
}

// exibe o relatorio final do paciente
void exibirRelatorio(char nomes[][TAM_NOME], float fatores[][NUM_FATORES], int quantidade)
{
    char classificacao[20];
    int i;

    exibirCabecalho("RELATORIO DE RISCO");

    for (i = 0; i < quantidade; i++) {
        classificarRisco(calcularPontuacao(fatores[i]), classificacao);
        printf("Paciente: %s\n", nomes[i]);
        printf("Classificacao: %s\n\n", classificacao);
    }

    printf("========================================\n");
}

int main(void)
{
    // matriz de string para nomes e numerica para fatores de risco
    char nomes[MAX_PACIENTES][TAM_NOME];
    float fatores[MAX_PACIENTES][NUM_FATORES];
    int quantidade, i;

    exibirCabecalho("SISTEMA DE ANALISE DE RISCO");

    // le quantos pacientes serao cadastrados, de 1 a 5
    printf("Quantidade de pacientes: ");
    scanf("%d", &quantidade);

    // cadastra cada paciente, passando a linha correspondente de cada matriz
    for (i = 0; i < quantidade; i++) {
        lerPaciente(nomes[i], fatores[i], i + 1);
    }

    // calcula e mostra o resultado de todos os pacientes
    exibirRelatorio(nomes, fatores, quantidade);

    return 0;
}
