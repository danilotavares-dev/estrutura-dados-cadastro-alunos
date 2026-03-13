#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Aluno {
    char nome[100];
    char sexo;
    int idade;
    float notas[3];
    bool aprovado;
};

int main () {

    int totalAlunos, qtdProvas;
    int somaIdadeAprov = 0, somaIdadeReprov = 0, qtdAlunas = 0;
    int alunasAprov = 0, alunasReprov = 0, alunosAprov = 0, alunosReprov = 0;

    float media, mediaAprov;

    char buffer[100];

    struct Aluno alunos[100];

    printf("Informe o total de alunos na classe: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &totalAlunos);

    printf("Informe a quantidade de provas:  ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &qtdProvas);

    do {
        printf("Informe a média de aprovação: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%f", &mediaAprov);
    } while (mediaAprov < 5.0 || mediaAprov > 8.0);

    for (int i = 0; i < totalAlunos; i++) {

        media = 0.0;

        printf("Informe o nome do %dº aluno: ", i + 1);
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        do {
            printf("Informe o sexo do %dº aluno(a) (M/F): ", i + 1);
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, " %c", &alunos[i].sexo);
        } while (alunos[i].sexo != 'm' && alunos[i].sexo != 'M' &&
                 alunos[i].sexo != 'f' && alunos[i].sexo != 'F');

        if (alunos[i].sexo == 'f' || alunos[i].sexo == 'F') {
            qtdAlunas++;
        }

        do {
            printf("Informe a idade do %dº aluno: ", i + 1);
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%d", &alunos[i].idade);
        } while (alunos[i].idade < 16 || alunos[i].idade > 90);

        for (int j = 0; j < qtdProvas; j++) {

            do {
                printf("Informe a %dª nota de %s: ", j + 1, alunos[i].nome);
                fgets(buffer, sizeof(buffer), stdin);
                sscanf(buffer, "%f", &alunos[i].notas[j]);
            } while (alunos[i].notas[j] < 0 || alunos[i].notas[j] > 10);

            media += alunos[i].notas[j];
        }

        media = media / qtdProvas;

        alunos[i].aprovado = media >= mediaAprov;

        if (alunos[i].aprovado && (alunos[i].sexo == 'F' || alunos[i].sexo == 'f')) {
            alunasAprov++;
            somaIdadeAprov += alunos[i].idade;
        }

        else if (!alunos[i].aprovado && (alunos[i].sexo == 'F' || alunos[i].sexo == 'f')) {
            alunasReprov++;
            somaIdadeReprov += alunos[i].idade;
        }

        else if (alunos[i].aprovado && (alunos[i].sexo == 'M' || alunos[i].sexo == 'm')) {
            alunosAprov++;
            somaIdadeAprov += alunos[i].idade;
        }

        else if (!alunos[i].aprovado && (alunos[i].sexo == 'M' || alunos[i].sexo == 'm')) {
            alunosReprov++;
            somaIdadeReprov += alunos[i].idade;
        }
    }

    printf("\nTotal de alunos do sexo masculino aprovado(s) em porcentagem: %.2f\n", (alunosAprov * 100.0) / totalAlunos);
    printf("Total de alunos do sexo masculino reprovado(s) em porcentagem: %.2f\n", (alunosReprov * 100.0) / totalAlunos);

    printf("Total de alunos do sexo feminino aprovada(s) em porcentagem: %.2f\n\n", (alunasAprov * 100.0) / totalAlunos);
    printf("Total de alunos do sexo feminino reprovada(s) em porcentagem: %.2f\n\n", (alunasReprov * 100.0) / totalAlunos);

    printf("Idade média de alunos aprovados: %.2f\n", (float)somaIdadeAprov / (alunosAprov + alunasAprov));
    printf("Idade média de alunos reprovados: %.2f\n", (float)somaIdadeReprov / (alunosReprov + alunasReprov));

    return 0;
}
