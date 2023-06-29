#include <iostream>
#include "sort.h"

using namespace std;

// Função para criar um novo nó
struct NodeList* newNodeList(int iPayload)
{
    // Aloca memória para o novo nó
    struct NodeList* newNode = new NodeList; 

    // Atribui o dado ao novo nó
    newNode -> iData = iPayload;

    // Atribui nullptr ao ponteiro para o próximo nó
    newNode -> ptrNext = nullptr;
    return newNode;
}

// Função para criar uma nova lista
struct List* newList()
{
    // Aloca memória para a nova lista
    struct List* newList = new List;

    // Atribui nullptr ao ponteiro para o primeiro nó
    newList -> ptrHead = nullptr;
    return newList;
}

// Função para inserir um novo nó no final da lista
void insertNodeList(struct List* ptrList, int iPayload)
{
    // Cria um novo nó
    struct NodeList* newNode = newNodeList(iPayload);

    // Cria um ponteiro para percorrer a lista
    struct NodeList* ptrCurrent = ptrList -> ptrHead;

    // Se a lista estiver vazia, o novo nó é o primeiro nó da lista
    if (ptrCurrent == nullptr)
    {
        ptrList -> ptrHead = newNode;
    }
    // Caso contrário, percorre a lista até o último nó
    else
    {
        while (ptrCurrent -> ptrNext != nullptr)
        {
            ptrCurrent = ptrCurrent -> ptrNext;
        }
        // Atribui o novo nó ao ponteiro para o próximo nó do último nó da lista
        ptrCurrent -> ptrNext = newNode;
    }
}

// Função para imprimir a lista
void printList(struct List* ptrList)
{
    // Cria um ponteiro para percorrer a lista
    struct NodeList* ptrCurrent = ptrList -> ptrHead;

    // Se a lista estiver vazia, imprime uma mensagem
    if (ptrList -> ptrHead == nullptr)
    {
        cout << "Lista vazia" << endl;
        return;
    }
    // Caso contrário, percorre a lista e imprime os dados
    while (ptrCurrent != nullptr)
    {
        cout << ptrCurrent -> iData << " ";
        ptrCurrent = ptrCurrent -> ptrNext;
    }
    cout << endl;
}