#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

struct Aluno {
    std::string nome;
    char sexo;
    int idade;
    std::vector<float> notas;
    bool aprovado;
};

int main () {
    int qtdAlunos;
    float soma, media;
    const int qtdNotas = 3;
    
    std::cout << "Informe a quantidade de alunos: ";
    std::cin >> qtdAlunos;
    std::cin.ignore();
    
    std::vector<Aluno> alunos(qtdAlunos);
    
    for (int i = 0; i < qtdAlunos; i++) {
        soma = 0.0f;
        
        alunos[i].notas.resize(qtdNotas);
        
        std::cout << "\nInforme o nome do " << i + 1 << "º aluno: ";
        std::getline(std::cin, alunos[i].nome);
        
        std::cout << "Informe o sexo do " << i + 1 << "º aluno: ";
        std::cin >> alunos[i].sexo;
        
        std::cout << "Informe a idade do " << i + 1 << "º aluno: ";
        std::cin >> alunos[i].idade;
        
        for (int j = 0; j < qtdNotas; j++) {
            std::cout << "Informe a " << j + 1 << "ª nota do " << i + 1 << "º aluno: ";
            std::cin >> alunos[i].notas[j];
            
            soma += alunos[i].notas[j];
        }
        
        std::cin.ignore();
        
        media = soma / float(qtdNotas);
        
        std::cout << "\nMédia Final: " << std::fixed << std::setprecision(1) << media << '\n';
        
        if (media < 6.0) {
            alunos[i].aprovado = false;
            std::cout << "Vish, Aluno reprovado!\n";
        }
        
        else {
            alunos[i].aprovado = true;
            std::cout << "Parabéns, Aluno aprovado\n";
        }
    }
    
    return 0;
}