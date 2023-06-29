// Estrutura para um nó de uma lista encadeada
struct NodeList
{
    // Dado armazenado no nó
    int iData;
    // Ponteiro para o próximo nó
    struct NodeList* ptrNext;
};

// Estrutura para uma lista encadeada
struct List
{
    // Ponteiro para o primeiro nó da lista
    struct NodeList* ptrHead;
};

// Função para criar um novo nó
struct NodeList* newNodeList(int iPayload);

// Função para criar uma nova lista
struct List* newList();

// Função para inserir um novo nó no final da lista
void insertNodeList(struct List* ptrList, int iPayload);

// Função para imprimir a lista
void printList(struct List* ptrList);
