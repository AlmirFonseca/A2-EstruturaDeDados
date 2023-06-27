#include "tree.cpp"
#include <iostream>

int main()
{
    // Cria uma árvore binária de busca a partir de dados digitados pelo usuário
    struct Node* root = arvoreDados();
    cout<<"Árvore binária de busca criada: ";
    printTree(root);
    
    // Cria uma árvore binária de busca a partir de um arquivo .txt
    struct Node* ptrNode2 = ArvoreTxt("../arvore.txt");
    cout<<"Árvore binária de busca criada a partir de um arquivo .txt:"<<endl;
    printTree(ptrNode2);

    return 0;
}