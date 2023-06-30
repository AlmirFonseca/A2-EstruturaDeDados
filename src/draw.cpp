#include <iostream>
#include <windows.h>
#include "header.h"
#include "draw.h"

using namespace std;

// Variável global que representa o texto do terminal
HANDLE h_draw = GetStdHandle(STD_OUTPUT_HANDLE);

// Altera a cor do texto do terminal
void changeCoutColor(char cColor = 'w'){
    if (cColor == 'b') SetConsoleTextAttribute(h_draw, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    else if (cColor == 'g') SetConsoleTextAttribute(h_draw, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    else if (cColor == 'r') SetConsoleTextAttribute(h_draw, FOREGROUND_RED | FOREGROUND_INTENSITY);
    else SetConsoleTextAttribute(h_draw, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}

// Calcula o número de caracteres que a barra deve ter, de acordo com os valores dos números
int getBarSize(int iListMax, int iListMin, int iCurrentBar){
    // Remapeia o intervalo [iListMin, iListMax] para [3, 70]
    return (int) (iCurrentBar - iListMin) * (67.0) / (iListMax - iListMin) + 3;
}

// Imprime o estado atual da lista usando barras de caracteres coloridas
void printListState(struct ListNode* ptrHead, int iListMin, int iListMax, struct ListNode* ptrNodeA=nullptr, char cColorA='w', struct ListNode* ptrNodeB=nullptr, char cColorB='w'){
    // Limpa o terminal
    system("cls");
    
    // Percorre a lista
    while (ptrHead != nullptr){
        // Se o nó atual for o nó A, imprime ele com a cor A
        if (ptrHead == ptrNodeA){
            changeCoutColor(cColorA);
        }
        // Se o nó atual for o nó B, imprime ele com a cor B
        else if (ptrHead == ptrNodeB){
            changeCoutColor(cColorB);
        }
        // Se o nó atual não for o nó A nem o nó B, imprime ele com a cor padrão
        else{
            changeCoutColor();
        }

        // Imprime o valor do nó atual
        cout << ptrHead->iData << " \t";

        // Imprime a barra de caracteres
        for (int iAux=0; iAux<getBarSize(iListMax, iListMin, ptrHead->iData); iAux++){
            cout << "\u2588";
        }

        // Configura a cor padrão pra saída
        changeCoutColor();

        // Avança para a próxima linha, para representar outro elemtento da lista
        cout << endl;

        // Avança para o próximo nó
        ptrHead = ptrHead->ptrNext;
    }

    // Congela a tela por um curto período de tempo
    Sleep(200);
}

