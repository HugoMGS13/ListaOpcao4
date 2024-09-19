//Discente: Polyana dos Santos Moraes - 202311140012
//Discente: Hugo Martins Gaspar da Silva - 202311140020

#include <iostream>
#include <string>
#include "agenda.h"
using namespace std;

// A função CriaContato é responsável por criar um novo contato e retornar um ponteiro para ela. Ela aloca memória para a estrutura Contato e preenche seus campos.
Contato* criarContato() {
    Contato* novo = new Contato;
    cout << "Nome: ";
    cin.ignore();  // Ignorar o caractere de nova linha
    cin.getline(novo->nome, 80);
    cout << "Telefone: ";
    cin >> novo->telefone;
    cout << "Email: ";
    cin.ignore();  // Ignorar o caractere de nova linha
    cin.getline(novo->email, 80);
    novo->prox = nullptr; // O próximo contato vai ser inicializado como nullptr.
    return novo;
}

// Função para adicionar um contato à lista encadeada.  
void adicionarContato(Contato*& lista) {
    Contato* novo = criarContato();
    novo->prox = lista; // O novo contato aponta para o primeiro contato da lista.
    lista = novo; // Agora ele tem um novo contato
    cout << "Contato adicionado com sucesso!" << endl;
}

// Função para remover um contato pelo telefone
void removerContato(Contato*& lista, int telefone) {
    Contato* atual = lista; 
    Contato* anterior = nullptr;
    // Percorre a lista até encontrar o contato com o telefone fornecido.
    while (atual != nullptr && atual->telefone != telefone) {
        anterior = atual; // Armazena o contato anterior
        atual = atual->prox; // Avança para o próximo contato
    }
    // Se o contato foi encontrado for nullptr, quer dizer que o contato não foi encontrado.
    if (atual == nullptr) {
        cout << "Contato não encontrado!" << endl;
        return;
    }
    // Se o contato a ser removido for o primeiro da lista, atualiza a lista para o próximo contato.
    if (anterior == nullptr) { // O contato está na cabeça da lista
        lista = atual->prox; // Atualiza a lista para o próximo contato
    } else {
        anterior->prox = atual->prox; // Atualiza o próximo do contato anterior para o próximo do contato atual.
    }

    delete atual;
    cout << "Contato removido com sucesso!" << endl;
}

// Função para listar todos os contatos na agenda.
void listarContatos(Contato* lista) {
    if (lista == nullptr) {
        cout << "Nenhum contato encontrado!" << endl;
        return;
    }
    // Mostra todos os dados do contato atual e avança para o próximo contato, até o final da lista.
    Contato* atual = lista;
    while (atual != nullptr) {
        cout << "Nome: " << atual->nome << ", Telefone: " << atual->telefone << ", Email: " << atual->email << endl;
        atual = atual->prox;
    }
}

// Função para pesquisar um contato pelo telefone.
void pesquisarContato(Contato* lista, int telefone) {
    bool encontrado = false;
    Contato* atual = lista;
    // Percorre a lista até encontrar o contato com o telefone fornecido.
    while (atual != nullptr) {
        if (atual->telefone == telefone) {
            cout << "Nome: " << atual->nome << ", Telefone: " << atual->telefone << ", Email: " << atual->email << endl;
            encontrado = true; // Se achar ele é true
        }
        atual = atual->prox; // Atualiza o contato atual para o próximo contato.
    }

    if (!encontrado) {
        cout << "Nenhum contato encontrado com o telefone: " << telefone << endl;
    }
}


// Função para verificar se existem valores repetidos
bool verificarRepetidos(Contato* lista, int telefone) {
    Contato* atual = lista;
    int contagem = 0;
    // Percorre a lista até encontrar o contato com o telefone fornecido, se tiver mais de uma contagem, ele retorna true. Se o telefone aparecer mais de uma vez, ele vai tentar verificar. 
    while (atual != nullptr) {
        if (atual->telefone == telefone) {
            contagem++;
        }
        atual = atual->prox;// Atualiza o contato atual para o próximo contato.
    }

    return (contagem > 1);
}

// Função para remover contatos com valores repetidos
void removerRepetidos(Contato*& lista) {
    Contato* atual = lista;
    while (atual != nullptr) {
        if (verificarRepetidos(lista, atual->telefone)) { // Percorre a lista até encontrar o contato com o telefone fornecido.
            Contato* contatoParaRemover = atual;
            atual = atual->prox;
            removerContato(lista, contatoParaRemover->telefone); // Remove o contato atual da lista.
        } else {
            atual = atual->prox; // Atualiza o contato atual para o próximo contato.
        }
    }
}
