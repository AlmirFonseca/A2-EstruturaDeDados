// Inclui bibliotecas para indicar o uso de strings
#include <string>
using namespace std;

// Função que adiciona um ponteiro do nó de uma arvóre em uma fila
void enqueueNode(struct QueueNode** ptrQueue, struct Node* ptrNode, int iLevel);

// Função para imprimir a árvore binária de busca utilizando BFS
void printTreeBFS(struct Node* ptrNode);

// Função para criar um novo nó a partir de um dado
struct Node* newNode(int iPayload);

// Função para inserir um novo nó na árvore binária de busca
struct Node* insertNode(struct Node* ptrNode,int iPayload);

// Função para imprimir a árvore binária de busca
void printTree(struct Node* ptrNode); 

// Função que, dado uma string separada por vírgulas, cria uma árvore binária de busca
struct Node* stringToTree(struct Node* ptrNode, string strTree);

// Função para criar uma árvore binária de busca a partir de dados digitados pelo usuário
struct Node* inputTree();

// Função para criar uma árvore binária de busca a partir de um arquivo .txt
struct Node* txtToTree(string strPath);

// Função que solicita o caminho do arquivo e chama a função para criar a árvore
struct Node* inputTxtTree();

// Função para verificar se uma árvore binária de busca é perfeita
bool isPerfectTree(struct Node* ptrNode);

// Função que permite usuário fornecer um elemento para ser inserido na árvore
struct Node* inputInsertNode(struct Node* ptrNode);

// Função para remover um nó da árvore binária de busca
struct Node* removeNode(struct Node* ptrNode, int iPayload);

// Função que permite usuário fornecer um elemento para ser removido da árvore
struct Node* inputRemoveNode(struct Node* ptrNode);

// Função para deletar a árvore binária de busca
void deleteTree(struct Node* ptrNode);

// Função para calcular a altura da árvore
int calculateHeight(struct Node* ptrNode);

// Função para obter o tamanho da árvore
TreeStats getTreeSize(struct Node* ptrNode);   

// Função que calcula o tamanho da árvore
int calculateSize(struct Node* ptrNode);

// Função que verifica se a árvore é completa
bool isCompleteTree(struct Node* ptrNode);

// Função que busca o endereço de memória de um nó
struct Node* searchNode(struct Node* ptrNode, int iTarget);

// Função que solicita um valor para ser buscado na árvore e retorna o endereço de memória do nó
void inputSearchNode(struct Node* ptrNode);