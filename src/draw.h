// Altera a cor do texto do terminal
void changeCoutColor(char cColor);

// Calcula o número de caracteres que a barra deve ter, de acordo com os valores dos números
int getBarSize(int iListMax, int iListMin, int iCurrentBar);

// Imprime o estado atual da lista usando barras de caracteres coloridas
void printListState(struct ListNode* ptrHead, int iListMin, int iListMax, struct ListNode* ptrNodeA, char cColorA, struct ListNode* ptrNodeB, char cColorB);
