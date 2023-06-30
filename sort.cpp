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

// Insere um nó após um nó específico
void insertAfter(struct ListNode* ptrPrevNode, int iPayload)
{
    // Se o nó anterior for nulo, não há o que fazer
    if (ptrPrevNode == nullptr)
    {
        cout << "O nó anterior não pode ser nulo" << endl;
        return;
    }

    // Cria um novo nó
    struct ListNode* ptrNewNode = createListNode(iPayload);

    // Atualiza o ponteiro do novo nó para o próximo nó
    ptrNewNode->ptrNext = ptrPrevNode->ptrNext;

    // Atualiza o ponteiro do novo nó para o nó anterior
    ptrNewNode->ptrPrev = ptrPrevNode;

    // Atualiza o ponteiro do nó anterior para o novo nó
    ptrPrevNode->ptrNext = ptrNewNode;

    // Atualiza o ponteiro do próximo nó para o novo nó
    if (ptrNewNode->ptrNext != nullptr)
    {
        ptrNewNode->ptrNext->ptrPrev = ptrNewNode;
    }
}

// Deleta um nó específico a partir do seu ponteiro
void deleteNode(struct ListNode** ptrHead, struct ListNode* ptrDel)
{
    // Se o nó a ser deletado for nulo, não há o que fazer
    if (ptrDel == nullptr)
    {
        cout << "O nó a ser deletado não pode ser nulo" << endl;
        return;
    }

    // Se o nó a ser deletado for o primeiro da lista, atualiza o ponteiro do primeiro nó
    if (*ptrHead == ptrDel)
    {
        *ptrHead = ptrDel->ptrNext;
    }

    // Atualiza o ponteiro do próximo nó para o nó anterior
    if (ptrDel->ptrNext != nullptr)
    {
        ptrDel->ptrNext->ptrPrev = ptrDel->ptrPrev;
    }

    // Atualiza o ponteiro do nó anterior para o próximo nó
    if (ptrDel->ptrPrev != nullptr)
    {
        ptrDel->ptrPrev->ptrNext = ptrDel->ptrNext;
    }

    // Libera a memória do nó a ser deletado
    free(ptrDel);
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

// Troca dois nós de posição numa lista
void swapListNodes(struct ListNode** ptrHead, struct ListNode* ptrNodeA, struct ListNode* ptrNodeB)
{
    // Check if the nodes to be swapped are the same
    if (ptrNodeA == ptrNodeB)
        return;

    // Check if either of the nodes is NULL
    if (ptrNodeA == nullptr || ptrNodeB == nullptr)
        return;

    // Check if the head node needs to be updated
    if (*ptrHead == ptrNodeA)
        *ptrHead = ptrNodeB;
    else if (*ptrHead == ptrNodeB)
        *ptrHead = ptrNodeA;

    // Update the next pointers
    if (ptrNodeA->ptrNext != nullptr)
        ptrNodeA->ptrNext->ptrPrev = ptrNodeB;
    if (ptrNodeB->ptrNext != nullptr)
        ptrNodeB->ptrNext->ptrPrev = ptrNodeA;

    // Update the prev pointers
    if (ptrNodeA->ptrPrev != nullptr)
        ptrNodeA->ptrPrev->ptrNext = ptrNodeB;
    if (ptrNodeB->ptrPrev != nullptr)
        ptrNodeB->ptrPrev->ptrNext = ptrNodeA;

    // Swap the next pointers
    struct ListNode* ptrTemp = ptrNodeA->ptrNext;
    ptrNodeA->ptrNext = ptrNodeB->ptrNext;
    ptrNodeB->ptrNext = ptrTemp;

    // Swap the prev pointers
    ptrTemp = ptrNodeA->ptrPrev;
    ptrNodeA->ptrPrev = ptrNodeB->ptrPrev;
    ptrNodeB->ptrPrev = ptrTemp;
}

// Função para trocar dois nós da lista duplamente encadeada
void swap(struct ListNode** head, struct ListNode* ptrNode1, struct ListNode* ptrNode2)
{
    // Insere os elementos que serão trocados nas posições corretas
    insertAfter(ptrNode1, ptrNode2->iData);
    insertAfter(ptrNode2, ptrNode1->iData);

    // Remove os elementos que foram trocados das posições anteriores
    deleteNode(head, ptrNode1);
    deleteNode(head, ptrNode2);
}

// Converte a árvore numa lista e a converte utilizando o algoritmo de Bubble Sort
struct ListNode* bubbleSort(struct Node* ptrNodeTree)
{

    // Converte a árvore para uma lista encadeada
    struct ListNode* ptrListHead = treeToList(ptrNodeTree);

    // Se a lista estiver vazia ou tiver apenas um elemento, não há o que ordenar
    if (ptrListHead == nullptr || ptrListHead->ptrNext == nullptr)
    {
        return ptrListHead;
    }

    // Cria um booleano para verificar se houve alguma troca na iteração
    bool bSwaped = false;

    // Cria um ponteiro para percorrer a lista
    struct ListNode* ptrCurrentNode = ptrListHead;

    // Cria um ponteiro para indicar até aonde devemos percorrer a lista em cada iteração
    struct ListNode* ptrStopNode = nullptr;

    while(ptrListHead != ptrStopNode)
    {
        // Reinicia o booleano para cada iteração
        bSwaped = false;
        
        // Reinicia o ponteiro para percorrer a lista
        ptrCurrentNode = ptrListHead;

        // Percorre a lista até o elemento anterior ao último elemento percorrido pelo outerLoop
        while (ptrCurrentNode->ptrNext != ptrStopNode)
        {
            // Caso o elemento atual seja maior que o próximo elemento
            if (ptrCurrentNode->iData > ptrCurrentNode->ptrNext->iData)
            {
                // Troca os nós de posição
                swap(&ptrListHead, ptrCurrentNode, ptrCurrentNode->ptrNext);

                // Atualiza o booleano
                bSwaped = true;
            }

            // Avança o ponteiro do innerLoop para o próximo elemento
            ptrCurrentNode = ptrCurrentNode->ptrNext;
        }

        // Atualiza o ponteiro para indicar até aonde devemos percorrer a lista em cada iteração
        ptrStopNode = ptrCurrentNode;

        // Caso a lista esteja ordenada, interrompe o loop
        if (bSwaped == false) return ptrListHead;
    }

    // Retorna o ponteiro da lista ordenada
    return ptrListHead;
}