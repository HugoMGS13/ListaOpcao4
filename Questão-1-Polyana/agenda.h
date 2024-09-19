//Discente: Polyana dos Santos Moraes - 202311140012
//Discente: Hugo Martins Gaspar da Silva - 202311140020

#ifndef AGENDA_H
#define AGENDA_H

//A estrutura Contato armazena os dados de um contato. que são o nome, o endereço e o número de telefone. Além do ponteiro para a próxima estrutura Contato da lista.
struct Contato { 
    char nome[80];
    int telefone;
    char email[80];
    Contato* prox;

};
// Declarações de funções que vão ser implementadas no agenda.cpp
Contato* criarContato(); // Cria um novo contato e retorna o ponteiro para ele. Sendo esse alocado dinamicamente. 
void adicionarContato(Contato*& lista); // O parametro lista é um ponteiro para o primeiro elemento da lista. Ele é passado por referência para &, permitindo a modificação da lista.
void removerContato(Contato*& lista, int telefone);
void listarContatos(Contato* lista);
void pesquisarContato(Contato* lista, int telefone);
void listarContatos(Contato* lista);
bool verificarRepetidos(Contato* lista, int telefone);
void removerRepetidos(Contato*& lista);

#endif