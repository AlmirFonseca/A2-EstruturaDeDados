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
struct ListNode* createListNode(int iPayload)

// Insere um nó no final da lista
void insertList(struct ListNode** ptrHead, int iPayload)

// Deleta toda a lista
void deleteLinkedList(struct ListNode** ptrHead)

// Exibe os elementos da lista
void printList(struct ListNode* ptrHead)