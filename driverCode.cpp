#include "tree.cpp"
#include <iostream>

using namespace std;

int main()
{
    struct Node* root = arvoreDados();
    cout<<"Árvore binária de busca criada: ";
    printTree(root);

    return 0;
}