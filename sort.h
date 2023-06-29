// Estrutura para um nó de uma lista encadeada
struct ListNode
{
    // Dado armazenado no nó
    int iData;
    // Ponteiro para o próximo nó
    struct ListNode* ptrNext;
};

// Estrutura para uma lista encadeada (armazena o ponteiro para o primeiro nó da lista)
struct List
{
    // Ponteiro para o primeiro nó da lista
    struct ListNode* ptrHead;
};

// Função para criar um novo nó
struct ListNode* newListNode(int iPayload);

// Função para criar uma nova lista
struct List* newList();

// Função para inserir um novo nó no final da lista
void insertListNode(struct List* ptrList, int iPayload);

// Função para imprimir a lista
void printList(struct List* ptrList);

// Função que percorre a árvore binária de busca e insere os dados em uma lista
void insertTreeInList(struct Node* ptrNodeTree, struct List* ptrList);

// Função que converte uma árvore binária de busca em uma lista encadeada
struct List* treeToList(struct Node* ptrNodeTree);

// Função que transforma uma árvore binária em lista encadeada e a ordena utilizando Insertion Sort
struct List* insertionSort(struct Node* ptrNodeTree);
