// Cria um novo nó e carrega o payload
struct ListNode* createListNode(int iPayload);

// Insere um nó no final da lista
void insertList(struct ListNode** ptrHead, int iPayload);

// Insere um nó antes de um nó específico
void insertBefore(struct ListNode** ptrHead, struct ListNode* ptrNextNode, int iPayload);

// Insere um nó após um nó específico
void insertAfter(struct ListNode* ptrPrevNode, int iPayload);

// Deleta um nó específico a partir do seu ponteiro
void deleteNode(struct ListNode** ptrHead, struct ListNode* ptrDel);

// Deleta toda a lista
void deleteList(struct ListNode** ptrHead);

// Exibe os elementos da lista
void printList(struct ListNode* ptrHead);

// Percorre a lista e encontra o menor e o maior elemento
void getListRange(struct ListNode* ptrHead, int* iListMin, int*iListMax);

// Função que percorre a árvore binária de busca e insere os dados em uma lista
void insertTreeInList(struct Node* ptrNodeTree, struct ListNode** ptrListHead);

// Função que converte uma árvore binária de busca em uma lista encadeada
struct ListNode* treeToList(struct Node* ptrNodeTree);

// Troca dois nós de posição numa lista
void swapListNodes(struct ListNode** ptrHead, struct ListNode** ptrNode1, struct ListNode** ptrNode2, bool bSwitchNodes);

// Converte a árvore numa lista e a ordena utilizando o algoritmo de Bubble Sort
struct ListNode* bubbleSort(struct Node* ptrNodeTree, bool bPrintStates);

// Converte a árvore numa lista e a ordena utilizando o algoritmo de Selection Sort
struct ListNode* selectionSort(struct Node* ptrNodeTree, bool bPrintStates);

// Converte a árvore numa lista e a ordena utilizando o algoritmo de Insert Sort
struct ListNode* insertionSort(struct Node* ptrNodeTree, bool bPrintStates);

// Converte a árvore numa lista e a ordena utilizando o algoritmo de Shell Sort
struct ListNode* shellSort(struct Node* ptrNodeTree, bool bPrintStates);