#include "tree.cpp"
#include "sort.cpp"
#include <iostream>

int main()
{
    // Cria uma árvore binária de busca a partir de dados digitados pelo usuário
    struct Node* root = arvoreDados();
    cout<<"Árvore binária de busca criada: ";
    printTree(root);
    // Verifica se a árvore binária de busca é perfeita
    cout<<"A árvore binária de busca é perfeita? "<<ePerfeita(root)<<endl;

    cout<<endl;
    
    // Cria uma árvore binária de busca a partir de um arquivo .txt
    struct Node* ptrNode2 = ArvoreTxt("../arvore.txt");
    cout<<"Árvore binária de busca criada a partir de um arquivo .txt:"<<endl;
    printTree(ptrNode2);
    // Verifica se a árvore binária de busca é perfeita
    cout<<"A árvore binária de busca é perfeita? "<<ePerfeita(ptrNode2)<<endl;

    cout<<endl;

    // Cria uma lista encadeada simples
    struct List* ptrList = newList();
    
    // Insere um novo nó na lista encadeada simples
    insertNodeList(ptrList, 1);
    insertNodeList(ptrList, 2);
    insertNodeList(ptrList, 3);
    insertNodeList(ptrList, 4);
    insertNodeList(ptrList, 5);
    // Imprime a lista encadeada simples
    cout<<"Lista encadeada simples criada: ";
    printList(ptrList);

    
    return 0;
}