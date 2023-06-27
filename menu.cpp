#include <iostream>
#include <windows.h> // Para usar Sleep() e mudar a cor do texto
#include "menu.h"

using namespace std;

// Variável global que representa o texto do terminal
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


// Exibe o menu principal e retorna a escolha do usuário
int escolhaPrincipal()
{
    int iEscolha;
    
    // Setar a cor da letra para azul
    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

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
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    cout << endl;

    // Retornar a escolha do usuário
    return iEscolha;
}


// Exibe o menu de manipulação e retorna a escolha do usuário
int escolhaManipulacao()
{
    int iEscolha;

    // Setar a cor da letra para verde
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

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
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    cout << endl;

    // Retornar a escolha do usuário
    return iEscolha;
}


// Exibe o menu de informações e retorna a escolha do usuário
int escolhaInfos()
{
    int iEscolha;

    // Setar a cor da letra para verde
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

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
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    cout << endl;

    // Retornar a escolha do usuário
    return iEscolha;
}


// Exibe o menu de ordenação e retorna a escolha do usuário
int escolhaOrdenacao()
{
    int iEscolha;

    // Setar a cor da letra para verde
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

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
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
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
        cout << "Contruir uma árvore binária a partir de um '.txt'" << endl;
        break;
    case 2:
        cout << "Costruir uma árvore com os dados digitados" << endl;
        break;
    case 3:
        cout << "Inserir um elemento" << endl;
        break;
    case 4:
        cout << "Remover um elemento" << endl;
        break;
    case 5: 
        cout << "Buscar o endereço de memória de um elemento" << endl;
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
        cout << "Altura da árvore" << endl;
        break;
    case 2:
        cout << "Tamanho da árvore" << endl;
        break;
    case 3:
        cout << "A árvore é completa?" << endl;
        break;
    case 4:
        cout << "A árvore é perfeita?" << endl;
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
        cout << "Ordenar a lista representada pela árvore por Bubble Sort" << endl;
        break;
    case 2:
        cout << "Ordenar a lista representada pela árvore por Selection Sort" << endl;
        break;
    case 3:
        cout << "Ordenar a lista representada pela árvore por Insertion Sort" << endl;
        break;
    case 4:
        cout << "Ordenar a lista representada pela árvore por Shell Sort" << endl;
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
        cout << "Exibir árvore" << endl;
        break;
    case 4:
        menuOrdenacao();
        break;
    case 5: 
        cout << "Imprimir driverCode" << endl;
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