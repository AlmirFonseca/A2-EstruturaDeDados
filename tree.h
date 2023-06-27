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




