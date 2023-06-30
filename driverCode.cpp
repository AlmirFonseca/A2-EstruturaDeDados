#include "tree.cpp"
#include "sort.cpp"
#include <iostream>

int main()
{   
    // =============== CRIAÇÃO DA ÁRVORE POR INPUT ===============
    cout << endl << "---- Criação de árvore por input: " << endl;

    // Cria uma árvore binária de busca a partir de dados digitados pelo usuário
    struct Node* ptrRootInput = inputTree();
    cout << "Árvore binária de busca criada: ";
    printTree(ptrRootInput);
    // Verifica se a árvore binária de busca é perfeita
    cout << endl << "A árvore binária de busca é perfeita? " << isPerfectTree(ptrRootInput) << endl;


    // =============== CRIAÇÃO DA ÁRVORE POR TXT ===============
    cout << endl << "---- Criação de árvore por txt: " << endl;

    // Cria uma árvore binária de busca a partir de um arquivo .txt
    struct Node* ptrRootTxt = txtToTree("./arvore.txt");
    cout << "Árvore binária de busca criada a partir de um arquivo .txt:";
    printTree(ptrRootTxt);
    // Verifica se a árvore binária de busca é perfeita
    cout << endl << "A árvore binária de busca é perfeita? " << isPerfectTree(ptrRootTxt) << endl;


    // =============== INSERÇÃO DE ELEMENTO ===============
    cout << endl << "---- Inserção de elemento: " << endl;

    // Imprime a árvore antes da inserção
    cout << "Árvore binária de busca antes da inserção do elemento: ";
    printTree(ptrRootTxt);
    cout << endl;

    // Solicita ao usuário um elemento para ser inserido na árvore
    ptrRootTxt = inputInsertNode(ptrRootTxt);

    // Imprime a árvore com o novo elemento inserido
    cout << "Árvore binária de busca após a inserção do elemento: ";
    printTree(ptrRootTxt);

    cout << endl;


    // =============== REMOÇÃO DE ELEMENTO ===============
    cout << endl << "---- Remoção de elemento: " << endl;

    // Imprime a árvore antes da remoção
    cout << "Árvore binária de busca antes da remoção do elemento: ";
    printTree(ptrRootTxt);
    cout << endl;

    // Solicita ao usuário um elemento para ser removido da árvore
    ptrRootTxt = inputRemoveNode(ptrRootTxt);

    // Imprime a árvore com o elemento removido
    cout << "Árvore binária de busca após a remoção do elemento: ";
    printTree(ptrRootTxt);

    cout << endl;


    // =============== BASE DE LISTA DUPLAMENTE ENCADEADA ===============
    cout << endl << "---- Base de lista duplamente encadeada: " << endl;

    // Cria uma lista encadeada
    struct ListNode* ptrListHead = nullptr;
    
    // Insere um novo nó na lista encadeada
    insertList(&ptrListHead, 3);
    insertList(&ptrListHead, 2);
    insertList(&ptrListHead, 1);
    insertList(&ptrListHead, 4);
    insertList(&ptrListHead, 7);

    // Imprime a lista encadeada
    cout << "Lista encadeada criada: ";
    printList(ptrListHead);

    // Deleta a lista 
    deleteList(&ptrListHead);

    // Imprime a lista vazia
    cout << "Lista após a deleção: ";
    printList(ptrListHead);

    
    // =============== CONVERSÃO DA ÁRVORE EM LISTA ===============
    cout << endl << "---- Conversão da árvore em lista: " << endl;

    // Converte a árvore binária de busca em uma lista encadeada
    ptrListHead = treeToList(ptrRootTxt);
    // Imprime a lista encadeada
    cout << "Lista encadeada criada a partir da árvore binária de busca: ";
    printList(ptrListHead);

    
    // =================== ORDENAÇÃO DA LISTA ===================
    cout << endl << "---- Ordenação da lista: " << endl;

    cout << "Lista encadeada antes do ordenamento: ";
    printList(ptrListHead);

    // Ordena a lista encadeada utilizando Bubble Sort
    struct ListNode* ptrListBubbleSort =  bubbleSort(ptrRootTxt);

    // Imprime a lista encadeada ordenada
    cout << "Lista encadeada ordenada utilizando Bubble Sort: ";
    printList(ptrListBubbleSort);

    // Ordena a lista encadeada utilizando Selection Sort
    struct ListNode* ptrListSelectionSort =  selectionSort(ptrRootTxt);

    // Imprime a lista encadeada ordenada
    cout << "Lista encadeada ordenada utilizando Selection Sort: ";
    printList(ptrListSelectionSort);

    return 0;
}