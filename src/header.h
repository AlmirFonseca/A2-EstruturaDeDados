# include <chrono>

using namespace std::chrono;

// ====================== ESTRUTURAS ======================
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

// Estrutura para um nó da árvore binária de busca
struct Node
{
    // Dado armazenado no nó
    int iData;
    // Ponteiros para os nós filhos
    struct Node* ptrLeft; 
    struct Node* ptrRight;
};

// Estrutura para armazenar a fila de nós da árvore
struct QueueNode
{
    struct Node* ptrCurrentNode; // Ponteiro para o nó atual da fila
    int iHeight; // Altura do nó atual
    struct QueueNode* ptrNext; // Ponteiro para a próxima posição da fila
};

// Informações sobre a estrutura da árvore
struct TreeStats 
{
    int iNumNodes;     // Número de nós
    int iMinValue;     // Valor mínimo
    int iMaxValue;     // Valor máximo
    int iNumLeaves;    // Número de folhas
};

void printTime(time_point<high_resolution_clock> tpTimeStart, time_point<high_resolution_clock> tpTimeStop); // Exibe o tempo de execução do processo
