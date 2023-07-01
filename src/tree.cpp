#include <iostream>
#include <string>
#include <chrono> // Para usar o tempo de execução
#include <fstream> // Para usar arquivos .txt
#include <regex> // Para usar expressões regulares
#include "header.h"
#include "tree.h" // Inclui funções e estruturas para manipulação de árvores 

using namespace std;
using namespace std::chrono; // Para usar o tempo de execução

// Inicializa as variáveis de tempo
time_point<high_resolution_clock> tpStartTree;
time_point<high_resolution_clock> tpStopTree;


// Função para criar um novo nó
struct Node* newNode(int iPayload)
{
    // Aloca memória para o novo nó
    struct Node* ptrNewNode = new struct Node; 
    // Atribui o dado ao novo nó
    ptrNewNode->iData = iPayload;
    // Atribui nullptr aos ponteiros para os nós filhos
    ptrNewNode->ptrLeft = nullptr; 
    ptrNewNode->ptrRight = nullptr;
    return ptrNewNode;
}


// Função para inserir um novo nó na árvore binária de busca
struct Node* insertNode(struct Node* ptrNode, int iPayload)
{
    // Se a árvore estiver vazia, retorna o novo nó
    if (ptrNode == nullptr)
    {
        ptrNode = newNode(iPayload);
        return ptrNode;
    }
    // Caso contrário, percorre a árvore recursivamente até encontrar a posição correta
    else if(iPayload < ptrNode->iData)
    {
        ptrNode->ptrLeft = insertNode(ptrNode->ptrLeft, iPayload);
    }
    else
    {
        ptrNode->ptrRight = insertNode(ptrNode->ptrRight, iPayload); 
    }
    
    return ptrNode;
}

// Função para imprimir a árvore binária de busca
void printTree(struct Node* ptrNode)
{
    // Se o nó inicial não for nulo, imprime o dado e percorre recursivamente a árvore
    if (ptrNode != nullptr)
    {
        cout << " " << ptrNode->iData;
        printTree(ptrNode->ptrLeft);
        printTree(ptrNode->ptrRight);
    }
    
}

// Função que, dado uma string separada por espaços, cria uma árvore binária de busca
Node* stringToTree(Node* ptrNode, string strTree)
{
    // Verificar se a string está vazia
    if (strTree.empty())
    {
        return nullptr;
    }
    
    // Expressão regular para separar os elementos entre espaços
    regex separator("\\s");
    sregex_token_iterator iterator(strTree.begin(), strTree.end(), separator, -1);
    sregex_token_iterator srtiEndIterator;
    
    
    // Percorrer os elementos separados e inserir na árvore
    while (iterator != srtiEndIterator) 
    {
        // Verificar se o elemento é válido
        if (isdigit(*iterator->str().begin()))
        {
            // Converter o elemento para inteiro
            int iElement = stoi(*iterator);
            
            // Inserir o elemento na árvore
            ptrNode = insertNode(ptrNode, iElement);
        }
        else
        {
            cout << "Erro: a árvore deve conter apenas números inteiros." << endl;
            return nullptr;
        }
        
        
        ++iterator;
    }

    return ptrNode;
}



// Função para criar uma árvore binária de busca a partir de dados digitados
struct Node* inputTree()
{
    // Cria um ponteiro para o nó raiz e o inicializa como nulo
    struct Node* ptrRoot = nullptr;

    // Variável para armazenar os dados digitados
    string strTree;

    // Solicita os dados ao usuário
    cout << "Digite os dados da sua árvore separados por espaço: ";
    cin >> strTree;


    // Chama a função para criar a árvore
    ptrRoot = stringToTree(ptrRoot, strTree);
    
    return ptrRoot;
}



// Função para criar uma árvore binária de busca a partir de um arquivo .txt
struct Node* txtToTree(string strPath)
{
    // Inicia a contagem do tempo de execução
    tpStartTree = high_resolution_clock::now(); 

    // Cria um ponteiro para o nó raiz e o inicializa como nulo
    struct Node* ptrRoot = nullptr;

    // Variável para armazenar o conteúdo do arquivo
    ifstream ifsInputFile;

    // Abre o arquivo   
    ifsInputFile.open(strPath);

    // Verifica se o arquivo foi aberto corretamente
    if (ifsInputFile.is_open()) 
    {
        // Variável para armazenar o conteúdo do arquivo
        string strConteudo((istreambuf_iterator<char>(ifsInputFile)), (istreambuf_iterator<char>()));

        // Fecha o arquivo
        ifsInputFile.close();

        // Chama a função para criar a árvore a partir do conteúdo do arquivo
        ptrRoot = stringToTree(ptrRoot, strConteudo);

    } 
    // Caso contrário, exibe uma mensagem de erro
    else 
    {
        cout << "Erro ao abrir o arquivo." << endl;
    }

    // Finaliza a contagem do tempo de execução
    tpStopTree = high_resolution_clock::now(); 
    
    // Imprime o tempo de execução
    printTime(tpStartTree, tpStopTree);

    return ptrRoot;
}

// Função que solicita o caminho do arquivo e chama a função para criar a árvore
struct Node* inputTxtTree()
{
    // Variável para armazenar o caminho do arquivo
    string strPath;

    // Solicita o caminho do arquivo ao usuário
    cout << "Digite o caminho do arquivo: ";
    cin >> strPath;

    // Chama a função para criar a árvore a partir do arquivo
    return txtToTree(strPath);
}

// Função para verificar se uma árvore binária de busca é perfeita (se todos os nós tem 0 ou 2 filhos)
bool isPerfectTree(struct Node* ptrNode)
{
    // Se a árvore estiver vazia, retorna falso
    if (ptrNode == nullptr)
    {
        return false;
    }
    // Se o nó não tiver filhos, retorna verdadeiro
    else if (ptrNode->ptrLeft == nullptr && ptrNode->ptrRight == nullptr)
    {
        return true;
    }
    // Se o nó tiver apenas um filho, retorna falso
    else if (ptrNode->ptrLeft == nullptr || ptrNode->ptrRight == nullptr)
    {
        return false;
    }
    // Se o nó tiver dois filhos, verifica recursivamente se os filhos também são perfeitos
    else
    {
        // Caso um dos filhos não seja perfeito, retorna falso
        return isPerfectTree(ptrNode->ptrLeft) && isPerfectTree(ptrNode->ptrRight);
    }
    
}


// Função que permite usuário fornecer um elemento para ser inserido na árvore
struct Node* inputInsertNode(struct Node* ptrNode)
{
    // Variável para armazenar o elemento a ser inserido
    int iPayload;

    // Solicita o elemento ao usuário
    cout << "Digite o elemento a ser inserido: ";
    cin >> iPayload;

    // Verifica se o elemento é válido
    if (cin.fail())
    {
        cout << "Erro: o elemento deve ser um número inteiro." << endl;
        return ptrNode;
    }

    // Inicia a contagem do tempo de execução
    tpStartTree = high_resolution_clock::now(); 

    // Chama a função para inserir o elemento na árvore
    ptrNode = insertNode(ptrNode, iPayload);

    // Finaliza a contagem do tempo de execução
    tpStopTree = high_resolution_clock::now();

    // Imprime o tempo de execução
    printTime(tpStartTree, tpStopTree);

    return ptrNode;
}

// Função para remover um nó da árvore binária de busca
struct Node* removeNode(struct Node* ptrNode, int iPayload)
{
    // Se a árvore estiver vazia, retorna o novo nó
    if (ptrNode == nullptr)
    {
        return ptrNode;
    }

    // Se o valor do nó atual é igual ao valor a ser removido
    else if(iPayload == ptrNode->iData)
    {
        // Se o nó não tiver filhos
        if (ptrNode->ptrLeft == nullptr && ptrNode->ptrRight == nullptr)
        {
            // Exclui o nó e retorna nulo 
            free(ptrNode);
            return nullptr;
        }

        // Se o nó tiver apenas o filho direito
        else if (ptrNode->ptrLeft == nullptr)
        {
            // Cria um ponteiro para armazenar temporariamente o filho direito do nó que será excluído
            struct Node* ptrRightTemp = ptrNode->ptrRight;

            // Exclui o nó
            delete ptrNode;

            // Retorna o filho direito do nó excluído
            return ptrRightTemp;
        }

        // Se o nó tiver apenas o filho esquerdo
        else if (ptrNode->ptrRight == nullptr)
        {
            // Cria um ponteiro para armazenar temporariamente o filho esquerdo do nó que será excluído
            struct Node* ptrLeftTemp = ptrNode->ptrLeft;

            // Exclui o nó
            delete ptrNode;

            // Retorna o filho esquerdo do nó excluído
            return ptrLeftTemp;
        }
        
        // Se o nó tiver dois filhos, retorna o nó com o menor valor da subárvore direita
        else
        {
            // Cria um ponteiro para o nó com o menor valor da subárvore direita
            struct Node* ptrMinRight = ptrNode->ptrRight;

            // Percorre a subárvore direita até o nó mais à esquerda (menor valor)
            while (ptrMinRight->ptrLeft != nullptr) ptrMinRight = ptrMinRight->ptrLeft;

            // Atribui o valor do nó com o menor valor da subárvore direita ao nó atual
            ptrNode->iData = ptrMinRight->iData;

            // Remove o nó com o menor valor da subárvore direita
            ptrNode->ptrRight = removeNode(ptrNode->ptrRight, ptrMinRight->iData);

            return ptrNode;
        }
    }

    // Se o elemento a ser removido for menor que o elemento do nó atual, percorre a árvore recursivamente até encontrar a posição correta
    else if(iPayload < ptrNode->iData)
    {
        ptrNode->ptrLeft = removeNode(ptrNode->ptrLeft, iPayload);
    }

    // Se o elemento a ser removido for maior que o elemento do nó atual, percorre a árvore recursivamente até encontrar a posição correta
    else 
    {
        ptrNode->ptrRight = removeNode(ptrNode->ptrRight, iPayload); 
    }
    
    return ptrNode;
}

// Função que permite usuário fornecer um elemento para ser removido da árvore
struct Node* inputRemoveNode(struct Node* ptrNode)
{
    // Variável para armazenar o elemento a ser removido
    int iPayload;

    // Solicita o elemento ao usuário
    cout << "Digite o elemento a ser removido: ";
    cin >> iPayload;

    // Verifica se o elemento é válido
    if (cin.fail())
    {
        cout << "Erro: o elemento deve ser um número inteiro." << endl;
        return ptrNode;
    }

    // Inicia a contagem do tempo de execução
    tpStartTree = high_resolution_clock::now();

    // Chama a função para remover o elemento da árvore
    ptrNode = removeNode(ptrNode, iPayload);

    // Finaliza a contagem do tempo de execução
    tpStopTree = high_resolution_clock::now();

    // Imprime o tempo de execução
    printTime(tpStartTree, tpStopTree);

    return ptrNode;
}

// Função para deletar a árvore binária de busca
void deleteTree(struct Node* ptrNode) 
{
    if (ptrNode != nullptr) 
    {
    // Deletar recursivamente a sub-árvore esquerda
    deleteTree(ptrNode->ptrLeft);

    // Deletar recursivamente a sub-árvore direita
    deleteTree(ptrNode->ptrRight);

    // Deletar o nó atual
    ptrNode->ptrLeft = nullptr;
    ptrNode->ptrRight = nullptr;
    ptrNode = nullptr;
    delete ptrNode;
    }
}


// Função auxiliar para obter o mínimo entre dois valores inteiros
int getMin(int a, int b) 
{
    return (a < b) ? a : b;
}

// Função auxiliar para obter o máximo entre dois valores inteiros
int getMax(int a, int b) 
{
    return (a > b) ? a : b;
}

// Função que calcula a altura da árvore
int calculateHeight(struct Node* ptrNode) 
{
    if (ptrNode == nullptr)
        return 0;
    else {
        // Calcula a altura das subárvores esquerda e direita
        int iLeftHeight = calculateHeight(ptrNode->ptrLeft);
        int iRightHeight = calculateHeight(ptrNode->ptrRight);
        
        // Retorna a altura do nó atual somada à altura da subárvore mais alta
        return 1 + getMax(iLeftHeight, iRightHeight);
    }
}

// Função auxiliar para calcular as estatísticas da árvore
void calculateTreeStats(struct Node* ptrNode, TreeStats& tsStats) 
{
    if (ptrNode == nullptr) return;

    // Atualiza as estatísticas com base no nó atual
    tsStats.iNumNodes++;
    tsStats.iMinValue = getMin(tsStats.iMinValue, ptrNode->iData);
    tsStats.iMaxValue = getMax(tsStats.iMaxValue, ptrNode->iData);

    // Verifica se o nó atual é uma folha
    if (ptrNode->ptrLeft == nullptr && ptrNode->ptrRight == nullptr) 
    {
        tsStats.iNumLeaves++;
    }

    // Calcula as estatísticas das subárvores esquerda e direita recursivamente
    calculateTreeStats(ptrNode->ptrLeft, tsStats);
    calculateTreeStats(ptrNode->ptrRight, tsStats);
}

// Inicializa as estatísticas da árvore
TreeStats getTreeSize(Node* ptrNode) 
{
    TreeStats tsStats;
    tsStats.iNumNodes = 0;
    tsStats.iMinValue = ptrNode->iData;
    tsStats.iMaxValue = ptrNode->iData;
    tsStats.iNumLeaves = 0;

    // Calcula as estatísticas da árvore
    calculateTreeStats(ptrNode, tsStats);

    return tsStats;
}

// Função que calcula o tamanho da árvore
int calculateSize(struct Node* ptrNode) 
{
    // Verifica se o nó atual é nulo, indicando o final da subárvore
    if (ptrNode == nullptr) return 0;

    // Calcula o tamanho das subárvores esquerda e direita recursivamente
    int iLeftSize = calculateSize(ptrNode->ptrLeft);
    int iRightSize = calculateSize(ptrNode->ptrRight);

    // Retorna o tamanho da subárvore atual somado ao tamanho das subárvores esquerda e direita
    return iLeftSize + iRightSize + 1;
}

// Função auxiliar para verificar se a árvore é completa
bool isCompleteTree(struct Node* ptrNode, int iIndex, int iSize) 
{
    // Verifica se o nó atual é nulo, indicando o final da subárvore
    if (ptrNode == nullptr) return true;

    //Verifica se o índice atual ultrapassou o tamanho total da árvore, indicando que a subárvore não é completa
    if (iIndex >= iSize) return false;

    return isCompleteTree(ptrNode->ptrLeft, 2 * iIndex + 1, iSize) &&
           isCompleteTree(ptrNode->ptrRight, 2 * iIndex + 2, iSize);
}

// Função que verifica se a árvore é completa
bool isCompleteTree(struct Node* ptrNode) 
{
    int iSize = calculateSize(ptrNode);

    return isCompleteTree(ptrNode, 0, iSize);
}

// Função que adiciona um ponteiro do nó de uma arvóre em uma fila
void enqueueNode(struct QueueNode** ptrQueue, struct Node* ptrNode, int iLevel)
{
    // Cria um novo nó da fila e atribui o ponteiro do nó da árvore
    struct QueueNode* ptrNewQueueNode = new struct QueueNode;
    ptrNewQueueNode->ptrCurrentNode = ptrNode;
    ptrNewQueueNode->iHeight = iLevel;
    ptrNewQueueNode->ptrNext = nullptr;

    // Se a fila estiver vazia, o novo nó será o primeiro
    if (*ptrQueue == nullptr)
    {
        (*ptrQueue) = ptrNewQueueNode;
    }

    // Se a fila não estiver vazia, o novo nó será adicionado ao final da fila
    else
    {
        struct QueueNode* ptrCurrent = *ptrQueue;
        while (ptrCurrent->ptrNext != nullptr) ptrCurrent = ptrCurrent->ptrNext;
        ptrCurrent->ptrNext = ptrNewQueueNode;
    }
}


// Função para imprimir a árvore binária de busca utilizando BFS
void printTreeBFS(struct Node* ptrNode)
{
    // Inicia a contagem do tempo de execução
    tpStartTree = high_resolution_clock::now(); 

    struct QueueNode* ptrQueueRoot = nullptr;

    // Se a árvore estiver vazia, retorna
    if (ptrNode == nullptr)
    {
        return;
    }

    // Variável para armazenar a altura atual
    int iCurrentHeight = 0;

    // Adiciona o nó raiz na fila
    enqueueNode(&ptrQueueRoot, ptrNode, iCurrentHeight);

    cout << endl;

    // Enquanto a fila não estiver vazia
    while (ptrQueueRoot != nullptr)
    {
        // Se a altura do nó atual for diferente da altura anterior, pula uma linha
        if (ptrQueueRoot->iHeight != iCurrentHeight)
        {
            cout << endl;
            iCurrentHeight = ptrQueueRoot->iHeight;
        }

        // Imprime o valor do nó atual
        cout << ptrQueueRoot->ptrCurrentNode->iData << " ";

        // Adiciona os filhos do nó atual na fila
        if (ptrQueueRoot->ptrCurrentNode->ptrLeft != nullptr) enqueueNode(&ptrQueueRoot, ptrQueueRoot->ptrCurrentNode->ptrLeft, ptrQueueRoot->iHeight + 1);
        if (ptrQueueRoot->ptrCurrentNode->ptrRight != nullptr) enqueueNode(&ptrQueueRoot, ptrQueueRoot->ptrCurrentNode->ptrRight, ptrQueueRoot->iHeight + 1);

        // Remove o nó atual da fila e libera a memória
        struct QueueNode* ptrTemp = ptrQueueRoot;
        ptrQueueRoot = ptrQueueRoot->ptrNext;
        free(ptrTemp);
    }

    cout << endl;

    // Finaliza a contagem do tempo de execução
    tpStopTree = high_resolution_clock::now();

    // Imprime o tempo de execução
    printTime(tpStartTree, tpStopTree);
}

// Função que busca o endereço de memória de um nó na árvore
struct Node* searchNode(struct Node* ptrNode, int iTarget)
{
    // Verifica se o nó atual é nulo, indicando o final da sub-árvore
    if (ptrNode == nullptr)
    {
        return nullptr;
    }

    // Verifica se o valor do nó atual é igual ao valor buscado
    if (ptrNode->iData == iTarget)
    {
        return ptrNode;
    }

    // Se o valor do nó atual for maior que o valor buscado, busca na subárvore esquerda
    if (ptrNode->iData > iTarget)
    {
        return searchNode(ptrNode->ptrLeft, iTarget);
    }

    // Se o valor do nó atual for menor que o valor buscado, busca na subárvore direita
    return searchNode(ptrNode->ptrRight, iTarget);
    
}

// Função que imprime o endereço de memória de um nó na árvore
void inputSearchNode(struct Node* ptrNode)
{
    // Solicita o valor a ser buscado
    int iTarget;
    cout << "Digite o valor a ser buscado: ";
    cin >> iTarget;

    // Verifica se o valor é numérico
    if (cin.fail())
    {
        cout << "Valor inválido!" << endl;
        return;
    }

    // Inicia a contagem do tempo de execução
    tpStartTree = high_resolution_clock::now();

    // Busca o endereço de memória do nó
    struct Node* ptrTarget = searchNode(ptrNode, iTarget);

    // Finaliza a contagem do tempo de execução
    tpStopTree = high_resolution_clock::now();

    // Imprime o tempo de execução
    printTime(tpStartTree, tpStopTree);

    // Imprime o resultado da busca
    if (ptrTarget == nullptr)
    {
        cout << "O endereço de memória do nó não foi encontrado!" << endl;
    }
    else
    {
        cout << "O endereço de memória do nó " << ptrTarget->iData << " é: " << ptrTarget << endl;
    }

}