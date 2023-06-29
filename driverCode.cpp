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


    // =============== CONVERSÃO DA ÁRVORE EM LISTA ===============
    cout << endl << "---- Conversão da árvore em lista: " << endl;

    // Cria uma lista encadeada simples
    struct List* ptrList1 = newList();
    
    // Insere um novo nó na lista encadeada simples
    insertListNode(ptrList1, 1);
    insertListNode(ptrList1, 2);
    insertListNode(ptrList1, 3);
    insertListNode(ptrList1, 4);
    insertListNode(ptrList1, 5);
    // Imprime a lista encadeada simples
    cout << "Lista encadeada simples criada: ";
    printList(ptrList1);

    // Converte a árvore binária de busca em uma lista encadeada simples
    struct List* ptrList2 = treeToList(ptrRootTxt);
    // Imprime a lista encadeada simples
    cout << "Lista encadeada simples criada a partir da árvore binária de busca: ";
    printList(ptrList2);


    // =================== ORDENAÇÃO DA LISTA ===================
    cout << endl << "---- Ordenação da lista: " << endl;

    // Ordena a lista encadeada simples utilizando Insertion Sort
    cout << "Lista encadeada simples antes do ordenamento por Insertion Sort: ";
    printList(ptrList2);

    struct List* ptrList2Ordered = insertionSort(ptrRootTxt);

    // Imprime a lista encadeada simples
    cout << "Lista encadeada simples ordenada utilizando Insertion Sort: ";
    printList(ptrList2Ordered);

    return 0;
}