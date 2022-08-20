#include <iostream>

using namespace std;

void clearConsole() {

}

void printMenuOptions() {
    cout << "\nEscolha o número referente ao desafio desejado:\n"
            " (0) - Sair\n"
            " (1) - Imprime uma reta (Algoritmo DDA)\n"
            " (2) - Imprime uma reta (Algoritmo de Bresenham)\n"
            " (3) - Imprime polilinhas formando um polígono (Algoritmo DDA)\n"
            " (4) - Imprime polilinhas formando um polígono (Algoritmo de Bresenham)\n"
            " (5) - Imprime o traçado de um círculo (Teorema de Pitágoras)\n"
            " (6) - Imprime o traçado de um círculo (Sistemas de coordenadas polares)\n"
            " (7) - Imprime o traçado de um círculo (Algoritmo de Bresenham)\n";
}

int askUserOption() {
    int input;
    cout << "\nOpcao: ";
    cin >> input;
    return input;
}

int init() {
    int userOption = 0;

    while(true){
        clearConsole();
        printMenuOptions();
        userOption = askUserOption();
        switch (userOption) {
            case 0:
                return 0;
            case 1:
                cout << "Caso 1";
                break;
            case 2:
                cout << "Caso 2";
                break;
            case 3:
                cout << "Caso 3";
                break;
            case 4:
                cout << "Caso 4";
                break;
            case 5:
                cout << "Caso 5";
                break;
            case 6:
                cout << "Caso 6";
                break;
            case 7:
                cout << "Caso 7";
                break;
            default:
                cout << "\nEssa opcao nao pode ser executada. Tente inserir uma opcao válida...\n";
        }
    }
}

int main() {
    init();
    return 0;
}
