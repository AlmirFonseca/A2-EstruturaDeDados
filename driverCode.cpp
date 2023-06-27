#include "tree.cpp"
#include <iostream>

using namespace std;

int main()
{
    struct Node* root = newNode(1);
    root -> ptrLeft = newNode(5);
    root -> ptrRight = newNode(3);
    root -> ptrRight  ->ptrLeft = newNode(7);
    cout<<root->iData<<endl;
    cout<<root->ptrLeft->iData<<endl;
    cout<<root->ptrRight->iData<<endl;
    cout<<root->ptrRight->ptrLeft->iData<<endl;

    return 0;
}