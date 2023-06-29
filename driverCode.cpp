#include "tree.cpp"
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

    return 0;
}