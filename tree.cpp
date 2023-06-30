#include <iostream>
#include <string>
#include <fstream> // Para usar arquivos .txt
#include <regex> // Para usar expressões regulares
#include "tree.h" // Inclui funções e estruturas para manipulação de árvores 

using namespace std;


// Função para criar um novo nó
struct Node* newNode(int iPayload)
{
    // Aloca memória para o novo nó
    struct Node* newNode = new struct Node; 
    // Atribui o dado ao novo nó
    newNode->iData = iPayload;
    // Atribui nullptr aos ponteiros para os nós filhos
    newNode->ptrLeft = nullptr; 
    newNode->ptrRight = nullptr;
    return newNode;
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


// Função para, dado uma string separada por vírgulas, criar uma árvore binária de busca
struct Node* stringToTree(struct Node* ptrNode, string strTree)
{
    // Variável para armazenar o dado convertido para inteiro
    int iPayload;
    // Expressão regular para separar os elementos entre vírgulas
    regex regex(",");
    sregex_token_iterator iterator(strTree.begin(), strTree.end(), regex, -1);
    sregex_token_iterator endIterator;
    
    // Percorre os elementos separados e os insere na árvore
    while (iterator != endIterator) 
    {
        // Converte o elemento para inteiro
        iPayload = stoi(*iterator);
        // Insere o elemento na árvore
        ptrNode = insertNode(ptrNode, iPayload);
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
    cout << "Digite os dados da sua árvore separados por vírgula: ";
    cin >> strTree;

    // Chama a função para criar a árvore
    ptrRoot = stringToTree(ptrRoot, strTree);
    
    return ptrRoot;
}



// Função para criar uma árvore binária de busca a partir de um arquivo .txt
struct Node* txtToTree(string strPath)
{
    // Cria um ponteiro para o nó raiz e o inicializa como nulo
    struct Node* ptrRoot = nullptr;

    // Variável para armazenar o conteúdo do arquivo
    ifstream inputFile;

    // Abre o arquivo   
    inputFile.open(strPath);

    // Verifica se o arquivo foi aberto corretamente
    if (inputFile.is_open()) 
    {
        // Variável para armazenar o conteúdo do arquivo
        string strConteudo((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>()));

        // Fecha o arquivo
        inputFile.close();

        // Chama a função para criar a árvore a partir do conteúdo do arquivo
        ptrRoot = stringToTree(ptrRoot, strConteudo);

    } 
    // Caso contrário, exibe uma mensagem de erro
    else 
    {
        cout << "Erro ao abrir o arquivo." << endl;
    }

    return ptrRoot;
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

    // Chama a função para inserir o elemento na árvore
    ptrNode = insertNode(ptrNode, iPayload);

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
        if (ptrNode->ptrLeft == nullptr and ptrNode->ptrRight == nullptr)
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
            free(ptrNode);

            // Retorna o filho direito do nó excluído
            return ptrRightTemp;
        }

        // Se o nó tiver apenas o filho esquerdo
        else if (ptrNode->ptrRight == nullptr)
        {
            // Cria um ponteiro para armazenar temporariamente o filho esquerdo do nó que será excluído
            struct Node* ptrLeftTemp = ptrNode->ptrLeft;

            // Exclui o nó
            free(ptrNode);

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

    // Chama a função para remover o elemento da árvore
    ptrNode = removeNode(ptrNode, iPayload);

    return ptrNode;
}

// Função que calcula a altura da árvore
int calculateHeight( struct Node* prtNode) {
    if (prtNode == NULL)
        return 0;
    else {
        // Calcula a altura das subárvores esquerda e direita
        int leftHeight = calculateHeight(prtNode->ptrLeft);
        int rightHeight = calculateHeight(prtNode->ptrRight);
        
        // Retorna a altura do nó atual somada à altura da subárvore mais alta
        return 1 + max(leftHeight, rightHeight);
    }
}
