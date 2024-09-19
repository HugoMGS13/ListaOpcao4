//Discente: Polyana dos Santos Moraes - 202311140012
//Discente: Hugo Martins Gaspar da Silva - 202311140020

#include <iostream>
#include "agenda.h"
using namespace std;

//Na função main, apresenta o ponteiro lista para armazenar a lista encadeada de contatos. O nullptr indica é a lista está vazia.
int main() {
    Contato* lista = nullptr;
    int opcao, telefone; // As duas variaveis que vão entrar são a opcão para menu e o número de telefone.

    do {
        cout << "\nMenu:\n";
        cout << "Selecione a opção no menu:\n";
        cout << "1. Adicionar contato\n";
        cout << "2. Remover contato\n";
        cout << "3. Lista de todos contatos\n";
        cout << "4. Pesquisar contato\n";
        cout << "5. Verificar valores repetidos\n";
        cout << "6. Apagar valores repetidos\n";
        cout << "7. Sair\n";
        cout << "Opção: ";
        cin >> opcao; //Lê a opção do usuário, que é a entrada.

        if (cin.fail()) {
            cin.clear(); // Limpar o que der de erro
            cin.ignore(10000, '\n'); // Ignorar até 10000 caracteres ou até o fim da linha
            cout << "Opção inválida. Tente novamente.\n";
            continue; // Volta para o início do loop
        }

        switch (opcao) { //Controle do que o usuário quer fazer, no caso, qual opção ele quer escolher.
            case 1:
                adicionarContato(lista); //Função para adicionar um Contato a agenda.
                break;
            case 2:
                cout << "Digite o telefone para remover: ";
                cin >> telefone;
                removerContato(lista, telefone); // Faz a remoção do contato da agenda.
                break;
            case 3:
                listarContatos(lista); // Lista todos os contatos da agenda.
                break;
            case 4:
                cout << "Digite o telefone para pesquisar: ";
                cin >> telefone;
                pesquisarContato(lista, telefone); // Pesquisa um contato na agenda, através do telefone.
                break;
            case 5:
                cout << "Lista completa de contatos:\n";
                listarContatos(lista); // Lista todos os contatos da agenda.
                break;
            case 6:
                removerRepetidos(lista); // Remove contatos com valores repetidos.
                cout << "Contatos repetidos removidos!" << endl;
                break;
            case 7:
                cout << "Finalizado" << endl; // Finaliza o programa.
                break;
            default:
                cout << "Opção inválida!" << endl; // Quando um usuario digita uma opção que não existe.
        }
    } while (opcao != 7);

    // Limpar a memória alocada para a lista
    while (lista != nullptr) { //Enquanto a lista não estiver vazia, ele vai apagar os contatos, por meio do loop. Quando a lista for igual a nullptr, o loop termina.
        Contato* temp = lista; //Armazena a posição do primeiro nó da lista.
        lista = lista->prox; // Atualiza a lista para o próximo nó.
        delete temp; // Libera a memória alocada para o nó atual.
    }

    return 0;
}