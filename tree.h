// Inclui bibliotecas para indicar o uso de strings
#include <string>
using namespace std;

// Estrutura para um nó da árvore binária de busca
struct Node
{
    // Dado armazenado no nó
    int iData;
    // Ponteiros para os nós filhos
    struct Node* ptrLeft; 
    struct Node* ptrRight;
};

// Função para criar um novo nó a partir de um dado
struct Node* newNode(int iPayload);

// Função para inserir um novo nó na árvore binária de busca
struct Node* insertNode(struct Node* ptrNode,int iPayload);

// Função para imprimir a árvore binária de busca
void printTree(struct Node* ptrNode); 

// Função que, dado uma string separada por vírgulas, cria uma árvore binária de busca
struct Node* stringToTree(struct Node* ptrNode, string iDados);

// Função para criar uma árvore binária de busca a partir de dados digitados pelo usuário
struct Node* arvoreDados();





