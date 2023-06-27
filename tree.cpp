#include <iostream>
#include <string>
#include <regex> // Para usar expressões regulares
#include "tree.h" // Inclui funções e estruturas para manipulação de árvores 

using namespace std;


// Função para criar um novo nó
struct Node* newNode(int iPayload)
{
    // Aloca memória para o novo nó
    struct Node* newNode = new Node; 
    // Atribui o dado ao novo nó
    newNode -> iData = iPayload;
    // Atribui nullptr aos ponteiros para os nós filhos
    newNode -> ptrLeft = nullptr; 
    newNode -> ptrRight = nullptr;
    return newNode;
}


// Função para inserir um novo nó na árvore binária de busca
struct Node* insertNode(struct Node* ptrNode,int iPayload)
{
    // Se a árvore estiver vazia, retorna o novo nó
    if (ptrNode==nullptr)
    {
        ptrNode = newNode(iPayload);
        return ptrNode;
    }
    // Caso contrário, percorre a árvore recursivamente até encontrar a posição correta
    else if(iPayload < ptrNode->iData)
    {
        ptrNode->ptrLeft = insertNode(ptrNode->ptrLeft,iPayload);
    }
    else
    {
       ptrNode->ptrRight = insertNode(ptrNode->ptrRight,iPayload); 
    }
    
    return ptrNode;
}

// Função para imprimir a árvore binária de busca
void printTree(struct Node* ptrNode)
{
    // Se o nó inicial não for nulo, imprime o dado e percorre recursivamente a árvore
    if (ptrNode != nullptr)
    {
        cout<<" "<<ptrNode->iData;
        printTree(ptrNode->ptrLeft);
        printTree(ptrNode->ptrRight);
    }
    
}



// Função para, dado uma string separada por vírgulas, criar uma árvore binária de busca
struct Node* stringArvore(struct Node* ptrNode, string iDados)
{
    // Variável para armazenar o dado convertido para inteiro
    int iPayload;
    // Expressão regular para separar os elementos entre vírgulas
    regex regex(",");
    sregex_token_iterator iterator(iDados.begin(), iDados.end(), regex, -1);
    sregex_token_iterator endIterator;
    
    // Percorre os elementos separados e os insere na árvore
    while (iterator != endIterator) 
    {
        // Converte o elemento para inteiro
        iPayload = stoi(*iterator);
        // Insere o elemento na árvore
        ptrNode = insertNode(ptrNode,iPayload);
        ++iterator;
    }
    return ptrNode;
}

// Função para criar uma árvore binária de busca a partir de dados digitados
struct Node* arvoreDados()
{
    // Cria um ponteiro para o nó raiz e o inicializa como nulo
    struct Node* ptrRoot = nullptr;

    // Variável para armazenar os dados digitados
    string strDados;

    // Solicita os dados ao usuário
    cout<<"Digite os dados da sua árvore separados por vírgula: ";
    cin>>strDados;
    
    // Chama a função para criar a árvore
    ptrRoot = stringArvore(ptrRoot,strDados);
    
    return ptrRoot;
}


