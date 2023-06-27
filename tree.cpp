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
