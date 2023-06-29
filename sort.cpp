#include <iostream>
#include "sort.h"

using namespace std;

// Função para criar um novo nó
struct ListNode* newListNode(int iPayload)
{
    // Aloca memória para o novo nó
    struct ListNode* newNode = new struct ListNode; 

    // Atribui o dado ao novo nó
    newNode->iData = iPayload;

    // Atribui nullptr ao ponteiro para o próximo nó
    newNode->ptrNext = nullptr;
    return newNode;
}

// Função para criar uma nova lista
struct List* newList()
{
    // Aloca memória para a nova lista
    struct List* newList = new List;

    // Atribui nullptr ao ponteiro para o primeiro nó
    newList->ptrHead = nullptr;
    return newList;
}

// Função para inserir um novo nó no final da lista
void insertListNode(struct List* ptrList, int iPayload)
{
    // Cria um novo nó
    struct ListNode* newNode = newListNode(iPayload);

    // Cria um ponteiro para percorrer a lista
    struct ListNode* ptrCurrent = ptrList->ptrHead;

    // Se a lista estiver vazia, o novo nó é o primeiro nó da lista
    if (ptrCurrent == nullptr)
    {
        ptrList->ptrHead = newNode;
    }
    // Caso contrário, percorre a lista até o último nó
    else
    {
        while (ptrCurrent->ptrNext != nullptr)
        {
            ptrCurrent = ptrCurrent->ptrNext;
        }
        // Atribui o novo nó ao ponteiro para o próximo nó do último nó da lista
        ptrCurrent->ptrNext = newNode;
    }
}

// Função para imprimir a lista
void printList(struct List* ptrList)
{
    // Cria um ponteiro para percorrer a lista
    struct ListNode* ptrCurrent = ptrList->ptrHead;

    // Se a lista estiver vazia, imprime uma mensagem
    if (ptrList->ptrHead == nullptr)
    {
        cout << "Lista vazia" << endl;
        return;
    }
    // Caso contrário, percorre a lista e imprime os dados
    while (ptrCurrent != nullptr)
    {
        cout << ptrCurrent->iData << " ";
        ptrCurrent = ptrCurrent->ptrNext;
    }
    cout << endl;
}

// Função que percorre a árvore binária de busca e insere os dados em uma lista
void insertTreeInList(struct Node* ptrNodeTree, struct List* ptrList)
{
    // Se o nó for diferente de nullptr, percorre a árvore
    if (ptrNodeTree != nullptr)
    {
        // Percorre a árvore em pós-ordem
        insertTreeInList(ptrNodeTree->ptrLeft, ptrList);
        insertTreeInList(ptrNodeTree->ptrRight, ptrList);

        // Insere o dado do nó na lista
        insertListNode(ptrList, ptrNodeTree->iData);
    }
}

// Função que converte uma árvore binária de busca em uma lista encadeada
struct List* treeToList(struct Node* ptrNodeTree)
{
    // Cria uma nova lista
    struct List* ptrList = newList();

    // Se o nó for nullptr, retorna a lista vazia
    if (ptrNodeTree == nullptr)
    {
        return ptrList;
    }

    // Caso contrário, percorre a árvore e insere os dados na lista
    insertTreeInList(ptrNodeTree, ptrList);

    return ptrList;
}

// Função que ordena uma lista utilizando Insertion Sort
struct List* insertionSort(struct Node* ptrNodeTree)
{
    // Converte a árvore binária de busca em uma lista encadeada
    struct List* ptrList = treeToList(ptrNodeTree);

    // Cria um ponteiro para percorrer a lista não ordenada
    struct ListNode* ptrCurrent = ptrList->ptrHead;

    // Caso a lista esteja vazia ou tenha só um elemento, retorna ela mesma
    if (ptrCurrent == nullptr || ptrCurrent->ptrNext == nullptr)
    {
        return ptrList;
    }

    // Caso contrário, cria uma nova lista vazia para armazenar a lista ordenada
    struct List* ptrOrderedList = newList();
    
    // Percorre a lista não ordenada
    while (ptrCurrent != nullptr) 
    {
        // Cria um ponteiro para o próximo nó da lista não ordenada
        struct ListNode* ptrNextNode = ptrCurrent -> ptrNext;

        // Caso a lista ordenada esteja vazia ou o dado do nó atual seja menor que o dado do primeiro nó da lista ordenada
        if (ptrOrderedList->ptrHead == nullptr || ptrCurrent->iData < ptrOrderedList->ptrHead->iData)
        {
            // Insere o nó no início da lista ordenada
            ptrCurrent->ptrNext = ptrOrderedList->ptrHead;
            ptrOrderedList->ptrHead = ptrCurrent;
        }
        else
        {
            // Cria um ponteiro para percorrer a lista ordenada
            struct ListNode* ptrTemp = ptrOrderedList->ptrHead;

            // Percorre a lista ordenada até encontrar a posição correta para inserir o nó
            while (ptrTemp->ptrNext != nullptr && ptrCurrent->iData >= ptrTemp->ptrNext->iData)
            {
                ptrTemp = ptrTemp->ptrNext;
            }
            // Insere o nó na posição correta da lista ordenada
            ptrCurrent->ptrNext = ptrTemp->ptrNext;
            ptrTemp->ptrNext = ptrCurrent;
        }
        // Atualiza o ponteiro para o próximo nó da lista não ordenada
        ptrCurrent = ptrNextNode;
    }

    // Atualiza o ponteiro head da lista para a lista ordenada
    ptrList->ptrHead = ptrOrderedList->ptrHead;

    return ptrList;
}
