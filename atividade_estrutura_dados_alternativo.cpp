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
    int qtdAlunos;
    float soma, media;
    char buffer[100];
    
    struct Aluno alunos[100];
    
    printf("Informe a quantidade de alunos: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &qtdAlunos);
    
    for (int i = 0; i < qtdAlunos; i++) {
        soma = 0.0;
        
        printf("Informe o nome do %dº aluno: ", i + 1);
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';
        
        printf("Informe o sexo do %dº aluno: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, " %c", &alunos[i].sexo);
        
        printf("Informe a idade do %dº aluno: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &alunos[i].idade);
        
        for (int j = 0; j < 3; j++) {
              
            printf("Informe a %dª nota do %dº aluno: ", j + 1, i + 1);
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%f", &alunos[i].notas[j]);
            
            soma += alunos[i].notas[j];
        }
        
        media = soma / 3.0;
        printf("\nMédia Final: %.1f\n", media);
        
        if (media < 6.0) {
            alunos[i].aprovado = false;
            printf("Vish, Aluno reprovado!\n");
        }
        
        else {
            alunos[i].aprovado = true;
            printf("Parabéns, Aluno aprovado!!\n\n");
        }
    }
    
    return 0;
}
