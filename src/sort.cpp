#include <iostream>
#include "header.h"
#include "sort.h"
#include "tree.h"
#include "draw.h"

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

// Insere um nó antes de um nó específico
void insertBefore(struct ListNode** ptrHead, struct ListNode* ptrNextNode, int iPayload)
{
    // Se a lista for fazia, não há o que fazer, criamos um novo nó e apontamos a head para ele
    if (*ptrHead == nullptr)
    {
        *ptrHead = createListNode(iPayload);
        return;
    }

    // Se o nó seguinte for nulo, inserimos no fim da lista
    if (ptrNextNode == nullptr)
    {
        insertList(ptrHead, iPayload);
        return;
    }

    // Criamos um novo nó
    struct ListNode* newNode = createListNode(iPayload);

    // Atualizamos os ponteiros next e prev do novo nó
    newNode->ptrNext = ptrNextNode;
    newNode->ptrPrev = ptrNextNode->ptrPrev;

    // Atualizamos o ponteiro prev do nó seguinte
    if (ptrNextNode->ptrPrev != nullptr)
        ptrNextNode->ptrPrev->ptrNext = newNode;

    // Atualizamos o ponteiro prev do nó seguinte
    ptrNextNode->ptrPrev = newNode;

    // Se o nó seguinte for a head, atualizamos a head
    if (*ptrHead == ptrNextNode)
        *ptrHead = newNode;
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

// Percorre a lista e encontra o menor e o maior elemento
void getListRange(struct ListNode* ptrHead, int* iListMin, int*iListMax)
{
    // Inicializa as variáveis com o primeiro elemento da lista
    *iListMin = ptrHead->iData;
    *iListMax = ptrHead->iData;

    // Percorre a lista até o seu fim
    while (ptrHead != nullptr)
    {
        // Atualiza o menor elemento
        if (ptrHead->iData < *iListMin)
            *iListMin = ptrHead->iData;

        // Atualiza o maior elemento
        if (ptrHead->iData > *iListMax)
            *iListMax = ptrHead->iData;

        // Avança para o próximo elemento
        ptrHead = ptrHead->ptrNext;
    }
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
void swapListNodes(struct ListNode** ptrHead, struct ListNode** ptrNode1, struct ListNode** ptrNode2, bool bSwitchNodes=false)
{
    // Insere os elementos que serão trocados nas posições corretas
    insertAfter((*ptrNode1), (*ptrNode2)->iData);
    insertAfter((*ptrNode2), (*ptrNode1)->iData);

    // Avança os nós para a posição correta
    (*ptrNode1) = (*ptrNode1)->ptrNext;
    (*ptrNode2) = (*ptrNode2)->ptrNext;

    // Remove os elementos que foram trocados das posições anteriores
    deleteNode(ptrHead, (*ptrNode1)->ptrPrev);
    deleteNode(ptrHead, (*ptrNode2)->ptrPrev);

    // Atualiza os ponteiros
    if (bSwitchNodes)
    {
        struct ListNode* ptrAux = (*ptrNode1);
        (*ptrNode1) = (*ptrNode2);
        (*ptrNode2) = ptrAux;
    }
}

// Converte a árvore numa lista e a converte utilizando o algoritmo de Bubble Sort
struct ListNode* bubbleSort(struct Node* ptrNodeTree, bool bPrintStates=false)
{
    // Converte a árvore para uma lista encadeada
    struct ListNode* ptrListHead = treeToList(ptrNodeTree);

    // Se a lista estiver vazia ou tiver apenas um elemento, não há o que ordenar
    if (ptrListHead == nullptr || ptrListHead->ptrNext == nullptr)
    {
        return ptrListHead;
    }

    // Percorre a lista e encontra o menor e o maior elemento
    int iListMin, iListMax;
    getListRange(ptrListHead, &iListMin, &iListMax);

    // Cria um booleano para verificar se houve alguma troca na iteração
    bool bSwaped = false;

    // Cria um ponteiro para percorrer a lista
    struct ListNode* ptrCurrentNode = ptrListHead;

    // Cria um ponteiro para indicar até aonde devemos percorrer a lista em cada iteração
    struct ListNode* ptrStopNode = nullptr;

    // Percorre a lista até ponteiro que indica o final da parte ainda não ordenada da lista
    while(ptrListHead != ptrStopNode)
    {
        // Reinicia o booleano para cada iteração
        bSwaped = false;
        
        // Reinicia o ponteiro para percorrer a lista
        ptrCurrentNode = ptrListHead;

        // Percorre a lista até o elemento anterior ao último elemento percorrido pelo outerLoop
        while (ptrCurrentNode->ptrNext != ptrStopNode)
        {
            // Imprime o estado atual, onde ptrCurrentNode (azul) e ptrCurrentNode->ptrNext (azul) são os elementos sendo comparados
            if (bPrintStates)
            {
                printListState(ptrListHead, iListMin, iListMax, ptrCurrentNode, 'b', ptrCurrentNode->ptrNext, 'b');
            }

            // Caso o elemento atual seja maior que o próximo elemento
            if (ptrCurrentNode->iData > ptrCurrentNode->ptrNext->iData)
            {
                // Troca os nós de posição
                struct ListNode* ptrAux = ptrCurrentNode->ptrNext;
                swapListNodes(&ptrListHead, &ptrCurrentNode, &ptrAux, false);

                // Imprime o estado atual, onde ptrCurrentNode (verde) e ptrCurrentNode->ptrNext (verde) são os elementos sendo comparados
                if (bPrintStates)
                {
                    printListState(ptrListHead, iListMin, iListMax, ptrCurrentNode, 'g', ptrCurrentNode->ptrNext, 'g');
                }

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

struct ListNode* selectionSort(struct Node* ptrNodeTree, bool bPrintStates=false)
{
    // Converte a árvore para uma lista encadeada
    struct ListNode* ptrListHead = treeToList(ptrNodeTree);

    // Se a lista estiver vazia ou tiver apenas um elemento, não há o que ordenar
    if (ptrListHead == nullptr || ptrListHead->ptrNext == nullptr)
    {
        return ptrListHead;
    }

    // Percorre a lista e encontra o menor e o maior elemento
    int iListMin, iListMax;
    getListRange(ptrListHead, &iListMin, &iListMax);

    // Cria um ponteiro para percorrer a lista (outerLoop)
    struct ListNode* ptrOuterLoop = ptrListHead;

    // Percorre a lista no outerLoop até o seu fim (ptrOuterLoop != nullptr)
    while (ptrOuterLoop != nullptr)
    {
        // Cria um ponteiro para salvar o próximo elemento do outerLoop
        struct ListNode* NextOuter = ptrOuterLoop->ptrNext;
        
        // Cria um ponteiro para percorrer a lista (innerLoop) que se inicia à frente do outerLoop
        struct ListNode* ptrInnerLoop = ptrOuterLoop->ptrNext;

        // Percorre a lista no innerLoop até o seu fim (ptrInnerLoop != nullptr)
        while (ptrInnerLoop != nullptr)
        {
            // Cria um ponteiro para salvar o próximo elemento do innerLoop
            struct ListNode* NextInner = ptrInnerLoop->ptrNext;

            // Imprime o estado atual, onde ptrOuterLoop (vermelho) e ptrInnerLoop (azul) são os elementos sendo comparados
            if (bPrintStates)
            {
                printListState(ptrListHead, iListMin, iListMax, ptrOuterLoop, 'r', ptrInnerLoop->ptrNext, 'b');
            }
                
            // Caso o elemento atual do innerLoop seja menor que o elemento atual do outerLoop
            if (ptrInnerLoop->iData < ptrOuterLoop->iData)
            {
                // Troca os nós de posição, adicionando novos nós e apagando os nós antigos
                insertAfter(ptrInnerLoop, ptrOuterLoop->iData);
                insertAfter(ptrOuterLoop, ptrInnerLoop->iData);
                
                ptrInnerLoop = ptrInnerLoop->ptrNext;
                ptrOuterLoop = ptrOuterLoop->ptrNext;
                
                deleteNode(&ptrListHead, ptrInnerLoop->ptrPrev);

                // Caso o elemento anterior ao outerLoop seja o head da lista, atualiza o head
                if (ptrOuterLoop->ptrPrev == ptrListHead) ptrListHead = ptrOuterLoop;
                deleteNode(&ptrListHead, ptrOuterLoop->ptrPrev);

                
                // Imprime o estado atual, onde ptrOuterLoop (verde) e ptrInnerLoop (verde) são os elementos sendo comparados
                if (bPrintStates)
                {
                    printListState(ptrListHead, iListMin, iListMax, ptrOuterLoop, 'g', ptrInnerLoop, 'g');
                }
            }
            // Avança o ponteiro do innerLoop
            ptrInnerLoop = ptrInnerLoop->ptrNext;
        }
        // Avança o ponteiro do outerLoop
        ptrOuterLoop = ptrOuterLoop->ptrNext;
    }

    // Retorna o ponteiro da lista ordenada
    return ptrListHead;
}

// Converte a árvore numa lista e a converte utilizando o algoritmo de Selection Sort
struct ListNode* insertionSort(struct Node* ptrNodeTree, bool bPrintStates=false)
{
    // Converte a árvore para uma lista encadeada
    struct ListNode* ptrListHead = treeToList(ptrNodeTree);

    // Se a lista estiver vazia ou tiver apenas um elemento, não há o que ordenar
    if (ptrListHead == nullptr || ptrListHead->ptrNext == nullptr)
    {
        // Retorna o ponteiro da lista naturalmente ordenada
        return ptrListHead;
    }

    // Percorre a lista e encontra o menor e o maior elemento
    int iListMin, iListMax;
    getListRange(ptrListHead, &iListMin, &iListMax);

    // Cria um ponteiro para armazenar a parte ordenada da lista
    struct ListNode* ptrSorted = ptrListHead;

    // Cria um ponteiro para percorrer a lista
    struct ListNode* ptrCurrent = ptrListHead->ptrNext;

    // Percorre a lista até o seu fim
    while(ptrCurrent != nullptr)
    {
        // Armazena o próximo nó da lista a ser percorrido
        struct ListNode* ptrCurrentNext = ptrCurrent->ptrNext;

        // Se o nó atual for maior que o último nó da parte ordenada da lista
        if (ptrCurrent->iData >= ptrSorted->iData){
            // Avanço o ponteiro da parte ordenada da lista
            ptrSorted = ptrSorted->ptrNext;
        }
        // Caso o nó atual seja menor que o último nó da parte ordenada da lista
        else{
            // Cria um ponteiro para percorrer a parte ordenada da lista
            struct ListNode* ptrSortedTemp = ptrListHead;

            // Percorre a parte ordenada da lista até o seu fim
            while(ptrSortedTemp != ptrSorted->ptrNext)
            {

                // Imprime o estado atual, onde ptrCurrent (vermelho) e ptrSortedTemp (azul) são os elementos sendo comparados
                if (bPrintStates)
                {
                    printListState(ptrListHead, iListMin, iListMax, ptrCurrent, 'r', ptrSortedTemp, 'b');
                }

                // Caso o nó atual seja menor que o nó da parte ordenada da lista
                if (ptrCurrent->iData < ptrSortedTemp->iData)
                {
                    // Armazena o nó atual
                    int iCurrentPayload = ptrCurrent->iData;

                    // Deleta o nó atual da sua posição original
                    deleteNode(&ptrListHead, ptrCurrent);

                    // Insere o nó atual na sua nova posição
                    insertBefore(&ptrListHead, ptrSortedTemp, iCurrentPayload);

                    // Imprime o estado atual, onde ptrCurrent (verde) e ptrSortedTemp (verde) são os elementos sendo comparados
                    if (bPrintStates)
                    {
                        printListState(ptrListHead, iListMin, iListMax, ptrCurrent, 'g', ptrSortedTemp, 'g');
                    }

                    // Interrompe o loop
                    break;
                }

                // Avança o ponteiro no interior da parte ordenada da lista
                ptrSortedTemp = ptrSortedTemp->ptrNext;
            }
        }

        // Avança o ponteiro da lista
        ptrCurrent = ptrCurrentNext;
    }

    // Retorna o ponteiro da lista ordenada
    return ptrListHead;
}

// Converte a árvore numa lista e a converte utilizando o algoritmo de Shell Sort
struct ListNode* shellSort(struct Node* ptrNodeTree, bool bPrintStates=false)
{
    // Converte a árvore para uma lista encadeada
    struct ListNode* ptrListHead = treeToList(ptrNodeTree);

    // Se a lista estiver vazia ou tiver apenas um elemento, não há o que ordenar
    if (ptrListHead == nullptr || ptrListHead->ptrNext == nullptr)
    {
        return ptrListHead;
    }

    // Percorre a lista e encontra o menor e o maior elemento
    int iListMin, iListMax;
    getListRange(ptrListHead, &iListMin, &iListMax);
    
    // Criamos dois ponteiros temporários para percorrer a lista
    struct ListNode* ptrTempNodeA = ptrListHead;
    struct ListNode* ptrTempNodeB = nullptr;

    // Criamos um inteiro para armazenar o payload do ponteiro temporário
    int iTempPayload = 0;

    // Precisamos medir o comprimento (número de nós) da lista
    // Para isso, iniciamos uma variável acumuladora com valor 0
    int iListSize = 0;
    // E percorremos a lista até o seu fim, incrementando a variável acumuladora
    while (ptrTempNodeA != nullptr)
    {
        iListSize++;
        ptrTempNodeA = ptrTempNodeA->ptrNext;
    }
    
    // Definimos o gap inicial como metade do tamanho da lista
    int iGap = iListSize/2;
    
    // Enquanto o gap for maior que 0
    while (iGap > 0)
    {
        // Avança com o ponteiro A até o nó que está a iGap posições de distância do início da lista
        for (int iIndexA = 0; iIndexA < iListSize - iGap; iIndexA++)
        {
            // Inicia o ponteiro A como a head da lista
            ptrTempNodeA = ptrListHead;

            // Avança o ponteiro A até o índice determinado para essa iteração
            for (int iIndexB = 0; iIndexB < iIndexA; iIndexB++)
            {
                ptrTempNodeA = ptrTempNodeA->ptrNext;
            }

            // Posiciona o ponteiro B iGap posições à frente de A
            ptrTempNodeB = ptrTempNodeA;
            for (int iIndexB = 0; iIndexB < iGap; iIndexB++)
            {
                ptrTempNodeB = ptrTempNodeB->ptrNext;
            }

            // Imprime o estado atual, onde ptrTempNodeA (vermelho) e ptrTempNodeB (azul) são os elementos sendo comparados
            if (bPrintStates)
            {
                printListState(ptrListHead, iListMin, iListMax, ptrTempNodeA, 'r', ptrTempNodeB, 'b');
            }

            // Inicia um loop até que o node B seja maior que o node A
            while (ptrTempNodeB->iData < ptrTempNodeA->iData)
            {

                // Imprime o estado atual, onde ptrTempNodeA (vermelho) e ptrTempNodeB (azul) são os elementos sendo comparados
                if (bPrintStates)
                {
                    printListState(ptrListHead, iListMin, iListMax, ptrTempNodeA, 'r', ptrTempNodeB, 'b');
                }

                swapListNodes(&ptrListHead, &ptrTempNodeA, &ptrTempNodeB, true);

                // Imprime o estado atual, onde ptrTempNodeA (verde) e ptrTempNodeB (verde) são os elementos sendo comparados
                if (bPrintStates)
                {
                    printListState(ptrListHead, iListMin, iListMax, ptrTempNodeA, 'g', ptrTempNodeB, 'g');
                }

                // Posiciona (caso possível) o ponteiro A a iGap posições antes do ponteiro B
                ptrTempNodeA = ptrTempNodeB;
                for (int iIndexB = 0; iIndexB < iGap; iIndexB++)
                {
                    ptrTempNodeA = ptrTempNodeA->ptrPrev;
                    // Se A atingir o início da lista, paramos o loop
                    if (ptrTempNodeA == nullptr)
                    {
                        break;
                    }
                }

                // Se A atingir o início da lista, paramos o loop
                if (ptrTempNodeA == nullptr)
                {
                    break;
                }
            }
        }
        // Após cada iteração de um gap sobre a lista, o próximo gap é reduzido pela metade
        iGap /= 2;
    }

    // Retorna o ponteiro da lista ordenada
    return ptrListHead;
}
