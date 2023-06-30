// Estrutura para um nó de uma lista encadeada
struct ListNode
{
    // Dado armazenado no nó
    int iData;
    // Ponteiro para o próximo nó
    struct ListNode* ptrNext;
    // Ponteiro para o nó anterior
    struct ListNode* ptrPrev;
};

// Cria um novo nó e carrega o payload
struct ListNode* createListNode(int iPayload);

// Insere um nó no final da lista
void insertList(struct ListNode** ptrHead, int iPayload);

// Deleta toda a lista
void deleteList(struct ListNode** ptrHead);

// Exibe os elementos da lista
void printList(struct ListNode* ptrHead);

// Função que percorre a árvore binária de busca e insere os dados em uma lista
void insertTreeInList(struct Node* ptrNodeTree, struct ListNode** ptrListHead);

// Função que converte uma árvore binária de busca em uma lista encadeada
struct ListNode* treeToList(struct Node* ptrNodeTree);
