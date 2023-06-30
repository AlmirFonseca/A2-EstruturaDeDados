#include <iostream>
#include <windows.h>
#include "src/menu.h" // Inclui as funções do menu

using namespace std;

int main()
{
    // Define a codificação do terminal para UTF-8
    system("chcp 65001");

    // Limpa o terminal
    system("cls");

    // Chama a função que exibe o menu principal
    menuPrincipal();

    return 0;
}