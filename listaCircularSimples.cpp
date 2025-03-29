#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
using std::string;
using std::getline;

// ESTRUTURA PARA A LISTA
typedef struct Telemento { //a estrutura se chama Telemento
    int valor; //valor do elemento(nó)
    struct Telemento *proximo; //ponteiro para o proximo elemento 
} ELEMENTO; //apelido para Telemento

ELEMENTO *listaCircular = NULL; //ponteiro para o primeiro elemento da lista
ELEMENTO *fim = NULL; //ponteiro para o ultimo elemento da lista

// FUNÇÃO PARA CRIAR LISTA
void criarLista() {
    if (listaCircular != NULL) {
        cout << "Ja existe uma lista criada.\n";
    } else {
        listaCircular = (ELEMENTO*)malloc(sizeof(ELEMENTO)); //aloca um espaço na memoria para armazenar o elemento
        if (listaCircular == NULL) {
            cout << "Memória insuficiente.\n";
        } else {
            cout << "Informe um valor para o primeiro elemento: ";
            cin >> listaCircular->valor; //recebe o valor como primeiro elemento da lista
            listaCircular->proximo = listaCircular; //o elemento aponta para ele mesmo(circular)
            fim = listaCircular; //atualiza o ponteiro do ultimo elemento(o primeiro tambem é o ultimo, ja que tem apenas um elemento)
            cout << "Lista criada inicialmente com o valor " << listaCircular->valor << "\n";
        }
    }
}

// FUNÇÃO PARA ADICIONAR ELEMENTO NO INICIO DA LISTA
void adicionarElementoInicio() {
    if (listaCircular == NULL) { 
        criarLista();
    } else {
        ELEMENTO *ptrtemp = (ELEMENTO*)malloc(sizeof(ELEMENTO)); //aloca espaço para o novo elemento
        if (ptrtemp == NULL) {
            cout << "Memória insuficiente.\n";
        } else {
            cout << "Informe um valor: ";
            cin >> ptrtemp->valor; //lê o valor do novo elemento
            ptrtemp->proximo = listaCircular; //o novo elemento aponta para o antigo primeiro elemento
            fim->proximo = ptrtemp; //atualiza o último para apontar para o novo primeiro
            listaCircular = ptrtemp; //atualiza o ponteiro de início da lista
            cout << "Elemento " << ptrtemp->valor << " adicionado no inicio.\n";
        }
    }
}

// FUNÇÃO PARA ADICIONAR UM ELEMENTO NO FIM DA LISTA
void adicionarElementoFim() {
    if (listaCircular == NULL) {
        criarLista();
    } else {
        ELEMENTO *ptrtemp = (ELEMENTO*)malloc(sizeof(ELEMENTO)); //aloca memória para um novo elemento
        if (ptrtemp == NULL) {
            cout << "Memória insuficiente.\n";
        } else {
            cout << "Informe um valor: ";
            cin >> ptrtemp->valor; //le o valor do novo elemento
            ptrtemp->proximo = listaCircular; //o novo nó aponta para o início da lista
            fim->proximo = ptrtemp; //o antigo último aponta para o novo elemento
            fim = ptrtemp; //atualiza o ponteiro fim
            cout << "Elemento " << ptrtemp->valor << " adicionado no fim.\n";
        }
    }
}

// FUNÇÃO PARA REMOVER O PRIMEIRO ELEMENTO DA LISTA
void removerInicio() {
    if (listaCircular == NULL) {
        cout << "A lista esta vazia.\n";
    } else {
        ELEMENTO *temp = listaCircular; //ponteiro temporário para o primeiro elemento
        if (listaCircular == fim) { //se houver apenas um elemento na lista
            cout << "Elemento " << temp->valor << " removido do inicio.\n";
            free(temp); //libera a memória do nó
            listaCircular = fim = NULL;
        } else {
            listaCircular = listaCircular->proximo; //atualiza o início da lista
            fim->proximo = listaCircular; //atualiza o ponteiro do último elemento
            cout << "Elemento " << temp->valor << " removido do inicio.\n";
            free(temp); //libera a memória do nó removido
        }
    }
}

// FUNÇÃO PARA REMOVER O ÚLTIMO ELEMENTO DA LISTA
void removerFim() {
    if (listaCircular == NULL) { //verifica se a lista está vazia
        cout << "A lista esta vazia.\n";
    } else {
        ELEMENTO *temp = fim; //ponteiro temporário para o último elemento
        if (listaCircular == fim) { //se tiver apenas um elemento na lista
            cout << "Elemento " << temp->valor << " removido do fim.\n";
            free(temp); //libera a memória do nó
            listaCircular = fim = NULL; //esvazia a lista
        } else {
            ELEMENTO *anterior = listaCircular; //ponteiro para encontrar o penúltimo elemento
            while (anterior->proximo != fim) { //percorre até encontrar o penúltimo nó
                anterior = anterior->proximo;
            }
            anterior->proximo = listaCircular; //atualiza o ponteiro do penúltimo nó
            fim = anterior; //atualiza o ponteiro do último nó
            cout << "Elemento " << temp->valor << " removido do fim.\n";
            free(temp); //libera a memória do nó removido
        }
    }
}

// FUNÇÃO PARA VERIFICAR O PRIMEIRO ELEMENTO DA LISTA
void primeiroElemento() {
    if (listaCircular == NULL) {
        cout << "A lista esta vazia.\n";
    } else {
        cout << "Primeiro elemento: " << listaCircular->valor << "\n"; // exibe o valor do primeiro elemento
    }
}

// FUNÇÃO PARA VERIFICAR O ÚLTIMO ELEMENTO DA LISTA
void ultimoElemento() {
    if (fim == NULL) {
        cout << "A lista esta vazia.\n";
    } else {
        cout << "Último elemento: " << fim->valor << "\n"; // exibe o valor do ultimo elemento
    }
}

// FUNÇÃO PARA LISTAR TODOS OS ELEMENTOS DA LISTA
void listarElementos() {
    if (listaCircular == NULL) {
        cout << "A lista esta vazia.\n";
    } else {
        ELEMENTO *temp = listaCircular;
        cout << "Elementos da lista: ";
        do {
            cout << temp->valor << " -> ";
            temp = temp->proximo;
        } while (temp != listaCircular); // Percorre até voltar ao primeiro nó
        cout << "(Volta para o inicio)\n";
    }
}
//MENU INTERATIVO COM OPÇÕES DE ESCOLHA 
int main(){
    int opcao;
    do {
        cout << "\n~~~~~~ESCOLHA A OPÇÃO DESEJADA~~~~~~\n";
        cout << "1. Criar lista\n";
        cout << "2. Adicionar elemento no inicio\n";
        cout << "3. Adicionar elemento no fim\n";
        cout << "4. Remover elemento do inicio\n";
        cout << "5. Remover elemento do fim\n";
        cout << "6. Verificar primeiro elemento\n";
        cout << "7. Verificar ultimo elemento\n";
        cout << "8. Listar todos os elementos\n";
        cout << "0. Sair\n";
        cout << "Sua opção: ";
        cin >> opcao;

        if (opcao == 1) criarLista();
        else if (opcao == 2) adicionarElementoInicio();
        else if (opcao == 3) adicionarElementoFim();
        else if (opcao == 4) removerInicio();
        else if (opcao == 5) removerFim();
        else if (opcao == 6) primeiroElemento();
        else if (opcao == 7) ultimoElemento();
        else if (opcao == 8) listarElementos();
        else if (opcao == 0) cout << "INTERAÇÃO COM USUÁRIO FINALIZADA!\n";
        else cout << "OPÇÃO INVÁLIDA, TENTE NOVAMENTE.\n";
    } while (opcao != 0);

    return 0;
}