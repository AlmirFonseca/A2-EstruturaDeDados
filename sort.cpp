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

// Função que percorre a árvore binária de busca e insere os dados em uma lista
void PercorreLista(struct Node* ptrNode, struct List* ptrList)
{
    // Se o nó for diferente de nullptr, percorre a árvore
    if (ptrNode != nullptr)
    {
        // Percorre a árvore em pós-ordem
        PercorreLista(ptrNode->ptrLeft, ptrList);
        PercorreLista(ptrNode->ptrRight, ptrList);

        // Insere o dado do nó na lista
        insertNodeList(ptrList, ptrNode->iData);
    }
}

// Função que converte uma árvore binária de busca em uma lista encadeada
struct List* converterArvore(struct Node* ptrNode)
{
    // Cria uma nova lista
    struct List* ptrList = newList();

    // Se o nó for nullptr, retorna a lista vazia
    if (ptrNode == nullptr)
    {
        return ptrList;
    }

    // Caso contrário, percorre a árvore e insere os dados na lista
    PercorreLista(ptrNode, ptrList);

    return ptrList;
}
