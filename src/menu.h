#include <chrono>

using namespace std::chrono;

// Função que pede confirmação para sobrescrever a árvore
bool confirmOverwrite();

// Função que solicita ao usuário se ele deseja visualizar a representação gráfica da ordenação
bool drawSort();

// Exibe o tempo de execução do processo
void printTime(time_point<high_resolution_clock> tpTimeStart, time_point<high_resolution_clock> tpTimeStop);

// Função que exibe o menu principal e retorna a escolha do usuário
int escolhaPrincipal();

// Funções que exibem os menus secundários e retornam a escolha do usuário
int escolhaManipulacao();
int escolhaInfos();
int escolhaOrdenacao();

// Funções com as funcionalidades de cada menu secundário
void menuManipulacao();
void menuInfos();
void menuOrdenacao();

// Função com as funcionalidades do menu principal
void menuPrincipal();