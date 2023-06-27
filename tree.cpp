#include <iostream>
#include "tree.h" // Inclui funções e estruturas para manipulação de árvores 

using namespace std;


// Função para criar um novo nó
struct Node* newNode(int iPayload)
{
    // Aloca memória para o novo nó
    struct Node* newNode = new Node; 
    // Atribui o dado ao novo nó
    newNode -> iData = iPayload;
    // Atribui nullptr aos ponteiros para os nós filhos
    newNode -> ptrLeft = nullptr; 
    newNode -> ptrRight = nullptr;
    return newNode;
}


// Função para inserir um novo nó na árvore binária de busca
struct Node* insertNode(struct Node* ptrNode,int iPayload)
{
    // Se a árvore estiver vazia, retorna o novo nó
    if (ptrNode==nullptr)
    {
        ptrNode = newNode(iPayload);
        return ptrNode;
    }
    // Caso contrário, percorre a árvore recursivamente até encontrar a posição correta
    else if(iPayload < ptrNode->iData)
    {
        ptrNode->ptrLeft = insertNode(ptrNode->ptrLeft,iPayload);
    }
    else
    {
       ptrNode->ptrRight = insertNode(ptrNode->ptrRight,iPayload); 
    }
    
    return ptrNode;
}

// Função para imprimir a árvore binária de busca
void printTree(struct Node* ptrNode)
{
    // Se o nó inicial não for nulo, imprime o dado e percorre recursivamente a árvore
    if (ptrNode != nullptr)
    {
        cout<<" "<<ptrNode->iData;
        printTree(ptrNode->ptrLeft);
        printTree(ptrNode->ptrRight);
    }
    
}

