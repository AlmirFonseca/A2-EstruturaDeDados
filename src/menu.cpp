#include <iostream>
#include <windows.h> // Para usar Sleep() e mudar a cor do texto
#include <chrono>
#include "header.h"
#include "menu.h"
#include "sort.h"
#include "tree.h"
#include "driverCode.h"

using namespace std;

// Variável global que representa o texto do terminal
HANDLE hOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);

// Variável global que armazena a árvore
struct Node* ptrRoot = nullptr;

// Variável global que armazena os dados da árvore
TreeStats tsTreeStats;

// Inicializa as variáveis de tempo
time_point<high_resolution_clock> tpStart;
time_point<high_resolution_clock> tpStop;

// Variável global que armazena a lista resultante da ordenação da árvore
struct ListNode* ptrOrderedList;


// Função que pede confirmação para sobrescrever a árvore
bool confirmOverwrite()
{
    // Caso a árvore já exista, perguntar se o usuário deseja sobrescrevê-la
    if (ptrRoot != nullptr)
    {
        cout << "A árvore já existe. Deseja sobrescrevê-la? (S/N): ";
        char cEscolha;
        cin >> cEscolha;

        // Caso o usuário não queira sobrescrever a árvore, voltar ao menu de manipulação
        if (cEscolha == 'N' || cEscolha == 'n')
        {
            return false;
        }

        // Caso o usuário queira sobrescrever a árvore, liberar a memória da árvore atual
        else if (cEscolha == 'S' || cEscolha == 's')
        {
            deleteTree(ptrRoot);
            return true;
        }

        // Caso o usuário digite uma opção inválida, voltar ao menu de manipulação
        else
        {
            cout << "Opção inválida" << endl;
            return false;
        }
    }

    // Caso a árvore não exista, retornar true
    else return true;
}


// Exibe o tempo de execução do processo
void printTime(time_point<high_resolution_clock> tpTimeStart, time_point<high_resolution_clock> tpTimeStop)
{
    // Calcula o tempo de execução em nanosegundos
    auto nsTimeDuration = duration_cast<nanoseconds>(tpTimeStop - tpTimeStart);
    // Armazena o tempo de execução em um long long int
    long long int llTime = nsTimeDuration.count();

    cout << "Tempo de execução: ";

    // Exibe o tempo de execução, ajustando a sua escala conforme necessário
    if (llTime < 1e3) cout << llTime << " nanosegundos (ns)" << endl;
    else if (llTime < 1e6) cout << llTime/1e3 << " microsegundos (us)" << endl;
    else if (llTime < 1e9) cout << llTime/1e6 << " milisegundos (ms)" << endl;
    else cout << llTime/1e9 << " segundos (s)" << endl;
}


// Exibe o menu principal e retorna a escolha do usuário
int escolhaPrincipal()
{
    int iEscolha;
    
    // Setar a cor da letra para azul
    SetConsoleTextAttribute(hOutputHandle, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    // Imprimir o menu principal
    cout << endl << "+==+==+==+==+==+==+ MENU PRINCIPAL +==+==+==+==+==+==+" << endl;

    cout << "1. Manipulação da árvore" << endl;
    cout << "2. Informações sobre a árvore" << endl;
    cout << "3. Exibir árvore" << endl;
    cout << "4. Ordenação da árvore" << endl;
    cout << "5. Imprimir driverCode" << endl;
    cout << "6. SAIR" << endl;

    cout << "======================================================" << endl << endl;

    // Ler a escolha do usuário
    cout << "Digite a sua escolha: ";
    cin >> iEscolha;

    // Resetar a cor
    SetConsoleTextAttribute(hOutputHandle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    cout << endl;

    // Retornar a escolha do usuário
    return iEscolha;
}


// Exibe o menu de manipulação e retorna a escolha do usuário
int escolhaManipulacao()
{
    int iEscolha;

    // Setar a cor da letra para verde
    SetConsoleTextAttribute(hOutputHandle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    // Imprimir o menu de manipulação
    cout << endl << "========> MANIPULAÇÃO" << endl;

    cout << "1. Contruir uma árvore binária a partir de um '.txt'" << endl;
    cout << "2. Costruir uma árvore com os dados digitados" << endl;
    cout << "3. Inserir um elemento na árvore" << endl;
    cout << "4. Remover um elemento da árvore" << endl;
    cout << "5. Buscar o endereço de memória de um elemento da árvore" << endl;
    cout << "--------" << endl;
    cout << "6. MENU PRINCIPAL" << endl << endl;

    // Ler a escolha do usuário
    cout << "Digite a sua escolha: ";
    cin >> iEscolha;

    // Resetar a cor
    SetConsoleTextAttribute(hOutputHandle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    cout << endl;

    // Retornar a escolha do usuário
    return iEscolha;
}


// Exibe o menu de informações e retorna a escolha do usuário
int escolhaInfos()
{
    int iEscolha;

    // Setar a cor da letra para verde
    SetConsoleTextAttribute(hOutputHandle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    // Imprimir o menu de informações
    cout << endl << "========> INFORMAÇÕES" << endl;

    cout << "1. Altura da árvore " << endl;
    cout << "2. Tamanho da árvore" << endl;
    cout << "3. A árvore é completa?" << endl;
    cout << "4. A árvore é perfeita?" << endl;
    cout << "--------" << endl;
    cout << "5. MENU PRINCIPAL" << endl << endl;

    // Ler a escolha do usuário
    cout << "Digite a sua escolha: ";
    cin >> iEscolha;

    // Resetar a cor
    SetConsoleTextAttribute(hOutputHandle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    cout << endl;

    // Retornar a escolha do usuário
    return iEscolha;
}


// Exibe o menu de ordenação e retorna a escolha do usuário
int escolhaOrdenacao()
{
    int iEscolha;

    // Setar a cor da letra para verde
    SetConsoleTextAttribute(hOutputHandle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    // Imprimir o menu de ordenação
    cout << endl << "========> ORDENAÇÃO" << endl;

    cout << "1. Ordenar a lista representada pela árvore por Bubble Sort" << endl;
    cout << "2. Ordenar a lista representada pela árvore por Selection Sort" << endl;
    cout << "3. Ordenar a lista representada pela árvore por Insertion Sort" << endl;
    cout << "4. Ordenar a lista representada pela árvore por Shell Sort" << endl;
    cout << "--------" << endl;
    cout << "5. MENU PRINCIPAL" << endl << endl;

    // Ler a escolha do usuário
    cout << "Digite a sua escolha: ";
    cin >> iEscolha;

    // Resetar a cor
    SetConsoleTextAttribute(hOutputHandle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    cout << endl;

    // Retornar a escolha do usuário
    return iEscolha;
}


// Executa a escolha do usuário do menu de manipulação
void menuManipulacao()
{
    // Obter a escolha do usuário
    int iEscolha = escolhaManipulacao();

    // Executar a escolha do usuário
    switch (iEscolha)
    {
    case 1:
        if (confirmOverwrite()) ptrRoot = inputTxtTree();
        break;
    case 2:
        if (confirmOverwrite()) ptrRoot = inputTree();
        break;
    case 3:
        ptrRoot = inputInsertNode(ptrRoot);
        break;
    case 4:
        ptrRoot = inputRemoveNode(ptrRoot);
        break;
    case 5: 
        inputSearchNode(ptrRoot);
        break;
    
    // Caso o usuário queira voltar ao menu principal
    case 6:
        return;

    // Caso o usuário digite uma opção inválida
    default:
        cout << "Opção inválida" << endl;
        break;
    }

    // Esperar 1 segundo e chamar o menu de manipulação novamente
    Sleep(1);
    menuManipulacao();
}


// Executa a escolha do usuário do menu de informações
void menuInfos()
{
    // Obter a escolha do usuário
    int iEscolha = escolhaInfos();

    // Executar a escolha do usuário
    switch (iEscolha)
    {
    case 1:
        // Calcula a altura da árvore e mede o tempo de execução
        tpStart = chrono::high_resolution_clock::now();
        cout << "Altura da árvore: " << calculateHeight(ptrRoot) << endl;
        tpStop = chrono::high_resolution_clock::now();
        printTime(tpStart, tpStop);

        break;
    case 2:
        // Calcula o tamanho da árvore e mede o tempo de execução
        tpStart = chrono::high_resolution_clock::now();

        // Chama a função para obter os resultados
        tsTreeStats = getTreeSize(ptrRoot);

        // Exibindo os resultados
        cout << "Número de nós: " << tsTreeStats.iNumNodes << endl;
        cout << "Valor mínimo: " << tsTreeStats.iMinValue << endl;
        cout << "Valor máximo: " << tsTreeStats.iMaxValue << endl;
        cout << "Número de folhas: " << tsTreeStats.iNumLeaves << endl;

        tpStop = chrono::high_resolution_clock::now();
        printTime(tpStart, tpStop);

        break;
    case 3:
        // Calcula se a árvore é completa e mede o tempo de execução
        tpStart = chrono::high_resolution_clock::now();
        cout << "A árvore é completa?" << endl;
        cout << (isCompleteTree(ptrRoot) ? "Sim" : "Não") << endl;
        tpStop = chrono::high_resolution_clock::now();
        printTime(tpStart, tpStop);

        break;
    case 4:
        // Calcula se a árvore é perfeita e mede o tempo de execução
        tpStart = chrono::high_resolution_clock::now();
        cout << "A árvore é perfeita?" << endl;
        cout << (isPerfectTree(ptrRoot) ? "Sim" : "Não") << endl;
        tpStop = chrono::high_resolution_clock::now();
        printTime(tpStart, tpStop);

        break;
    
    // Caso o usuário queira voltar ao menu principal
    case 5: 
        return;

    // Caso o usuário digite uma opção inválida
    default:
        cout << "Opção inválida" << endl;
        break;
    }

    // Esperar 1 segundo e chamar o menu de informações novamente
    Sleep(1);
    menuInfos();
}


// Executa a escolha do usuário do menu de ordenação
void menuOrdenacao()
{
    // Obter a escolha do usuário
    int iEscolha = escolhaOrdenacao();

    // Executar a escolha do usuário
    switch (iEscolha)
    {
    case 1:
        // Ordena a lista por Bubble Sort e mede o tempo de execução
        tpStart = chrono::high_resolution_clock::now();
        ptrOrderedList = bubbleSort(ptrRoot, false);

        // Exibindo a lista ordenada
        cout << "Lista ordenada: ";
        printList(ptrOrderedList);
        cout << endl;

        // Imprimindo o tempo de execução
        tpStop = chrono::high_resolution_clock::now();
        printTime(tpStart, tpStop);

        // Liberando a memória da lista ordenada
        deleteList(&ptrOrderedList);

        break;
    case 2:
        // Ordena a lista por Selection Sort e mede o tempo de execução
        tpStart = chrono::high_resolution_clock::now();
        ptrOrderedList = selectionSort(ptrRoot, false);

        // Exibindo a lista ordenada
        cout << "Lista ordenada: ";
        printList(ptrOrderedList);

        // Imprimindo o tempo de execução
        tpStop = chrono::high_resolution_clock::now();
        printTime(tpStart, tpStop);

        // Liberando a memória da lista ordenada
        deleteList(&ptrOrderedList);

        break;
    case 3:
        // Ordena a lista por Insertion Sort e mede o tempo de execução
        tpStart = chrono::high_resolution_clock::now();
        ptrOrderedList = insertionSort(ptrRoot, false);

        // Exibindo a lista ordenada
        cout << "Lista ordenada: ";
        printList(ptrOrderedList);

        // Imprimindo o tempo de execução
        tpStop = chrono::high_resolution_clock::now();
        printTime(tpStart, tpStop);

        // Liberando a memória da lista ordenada
        deleteList(&ptrOrderedList);

        break;
    case 4:
        // Ordena a lista por Shell Sort e mede o tempo de execução
        tpStart = chrono::high_resolution_clock::now();
        ptrOrderedList = shellSort(ptrRoot, false);

        // Exibindo a lista ordenada
        cout << "Lista ordenada: ";
        printList(ptrOrderedList);

        // Imprimindo o tempo de execução
        tpStop = chrono::high_resolution_clock::now();
        printTime(tpStart, tpStop);

        // Liberando a memória da lista ordenada
        deleteList(&ptrOrderedList);

        break;
    
    // Caso o usuário queira voltar ao menu principal
    case 5: 
        return;

    // Caso o usuário digite uma opção inválida
    default:
        cout << "Opção inválida" << endl;
        break;
    }

    // Esperar 1 segundo e chamar o menu de ordenação novamente
    Sleep(1);
    menuOrdenacao();
}


// Executa a escolha do usuário do menu principal
void menuPrincipal()
{
    // Obter a escolha do usuário
    int iEscolha = escolhaPrincipal();

    // Executar a escolha do usuário
    switch (iEscolha)
    {
    case 1:
        menuManipulacao();
        break;
    case 2:
        menuInfos();
        break;
    case 3:
        printTreeBFS(ptrRoot);
        break;
    case 4:
        menuOrdenacao();
        break;
    case 5: 
        printDriverCode();
        break;
    
    // Caso o usuário queira sair do programa, encerra a função menuPrincipal
    case 6:
        cout << endl << "Saindo do programa..." << endl << endl;
        return;

    // Caso o usuário digite uma opção inválida
    default:
        cout << "Opção inválida" << endl;
        break;
    }

    // Esperar 1 segundo e chamar o menu principal novamente
    Sleep(1);
    menuPrincipal();
}