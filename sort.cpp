#include <iostream>
#include "sort.h"

using namespace std;

// Cria um novo nó e carrega o payload
struct ListNode* createListNode(int iPayload)
{
    // Aloca a memória necessária para o novo nó
    struct ListNode* ptrNewNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    
    // Caso a alocação falhe
    if (ptrNewNode == nullptr)
    {
        cout << "Ocorreu um erro na alocação de memória para um novo nó da lista" << endl;
        return nullptr;
    }

    // Caso a alocação tenha sido bem sucedida, carrega o payload e inicializa os ponteiros com valor nulo
    ptrNewNode->iData = iPayload;
    ptrNewNode->ptrNext = nullptr;
    ptrNewNode->ptrPrev = nullptr;
    
    // Retorna o ponteiro para o novo nó
    return ptrNewNode;
}

// Insere um nó no final da lista
void insertList(struct ListNode** ptrHead, int iPayload)
{
    // Cria um novo nó e carrega o seu payload
    struct ListNode* ptrNewNode = createListNode(iPayload);
    
    // Como ele vai ser o último elemento, seu ptrNext = nullptr
    ptrNewNode->ptrNext = nullptr;
    
    // Caso não existisse nenhum nó na lista
    if ((*ptrHead) == nullptr)
    {
        // O ptrPrev do novo nó aponta para nulo
        ptrNewNode->ptrPrev = nullptr;
        // E o ptrHead aponta pra ele
        (*ptrHead) = ptrNewNode; 
    }
    // Caso já existisse algum nó na lista
    else
    {
        //Precisamos de um ponteiro auxiliar para caminhar até o fim da lista
        struct ListNode* ptrTemp = (*ptrHead);
        
        // Atualizamos seu valor até atingir o último nó
        while(ptrTemp->ptrNext != nullptr) 
        {
            ptrTemp = ptrTemp->ptrNext;
        }

        // Atualiza o ponteiro do antigo último elemento 
        ptrTemp->ptrNext = ptrNewNode;
        // Atualiza o ponteiro do atual último elemento
        ptrNewNode->ptrPrev = ptrTemp;
    }
}

// Deleta toda a lista
void deleteList(struct ListNode** ptrHead)
{
    // Criamos 2 ponteiros auxiliares para apontar o nó atual (que será removido) e o nó seguinte
    struct ListNode* ptrCurrentNode = *ptrHead;
    struct ListNode* ptrNextNode;

    // Itera sobre toda a lista
    while (ptrCurrentNode != nullptr)
    {
        // Posiciona o ponteiro ptrCurrentNode à frente do ponteiro ptrCurrentNode
        ptrNextNode = ptrCurrentNode->ptrNext;

        // Libera a memória do ponteiro ptrCurrentNode
        free(ptrCurrentNode);

        // Atualiza o valor de ptrCurrentNode, avançando para o próximo nó
        ptrCurrentNode = ptrNextNode;
    }

    // Por fim, atualiza o valor de ptrHead para nullptr
    *ptrHead = nullptr;
}

// Exibe os elementos da lista
void printList(struct ListNode* ptrHead)
{

    // Se a lista estiver vazia, imprime uma mensagem
    if (ptrHead == nullptr)
    {
        cout << "Lista vazia" << endl;
        return;
    }

    // Se o ponteiro inserido não for o primeiro da lista, imprime uma mensagem
    if (ptrHead->ptrPrev != nullptr)
    {
        cout << "Meio da lista" << endl;
        return;
    }

    // Caso contrário, percorre a lista e imprime os dados
    while (ptrHead != nullptr)
    {
        cout << ptrHead->iData << " ";
        ptrHead = ptrHead->ptrNext;
    }
    cout << endl;
}

// Função que percorre a árvore binária de busca e insere os dados em uma lista
void insertTreeInList(struct Node* ptrNodeTree, struct ListNode** ptrListHead)
{
    // Se o nó for diferente de nullptr, percorre a árvore
    if (ptrNodeTree != nullptr)
    {
        // Percorre a árvore em pós-ordem
        insertTreeInList(ptrNodeTree->ptrLeft, ptrListHead);
        insertTreeInList(ptrNodeTree->ptrRight, ptrListHead);

        // Insere o dado do nó na lista
        insertList(ptrListHead, ptrNodeTree->iData);
    }
}

// Função que converte uma árvore binária de busca em uma lista encadeada
struct ListNode* treeToList(struct Node* ptrNodeTree)
{
    // Cria uma nova lista
    struct ListNode* ptrListHead = nullptr;

    // Se o nó for nullptr, retorna a lista vazia
    if (ptrNodeTree == nullptr)
    {
        return ptrListHead;
    }

    // Caso contrário, percorre a árvore e insere os dados na lista
    insertTreeInList(ptrNodeTree, &ptrListHead);

    // Retorna o ponteiro da lista, agora preenchida com os elementos da árvore
    return ptrListHead;
}