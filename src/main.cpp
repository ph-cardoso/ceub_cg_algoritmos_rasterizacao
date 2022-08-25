#include <iostream>
#include <cstdlib>

#define X_AXIS_SIZE 40
#define Y_AXIS_SIZE 80
#define PIXEL_CHAR 42

using namespace std;

void clearInputBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF) {}
}

void clearConsole() {
    #ifdef WINDOWS
        system("cls");
    #else
        // Assume POSIX
        system("clear");
    #endif
}

void printMenuOptions() {
    cout << "\nEscolha o número referente ao desafio desejado:\n"
            " (0) - Sair\n"
            " (1) - Imprime uma reta (Algoritmo DDA)\n"
            " (2) - Imprime uma reta (Algoritmo de Bresenham)\n"
            " (3) - Imprime o traçado de um círculo (Teorema de Pitágoras)\n"
            " (4) - Imprime o traçado de um círculo (Sistemas de coordenadas polares)\n"
            " (5) - Imprime o traçado de um círculo (Algoritmo de Bresenham)\n" << endl;
}

int askUserOption() {
    int input;
    cout << "\nOpcao: ";
    cin >> input;
    return input;
}

void printCartesianPlane() {

}

void initCartesianPlane() {
    char matriz[X_AXIS_SIZE][Y_AXIS_SIZE];

    for (int i = 0; i < X_AXIS_SIZE; ++i) {
        for (int j = 0; j < Y_AXIS_SIZE; ++j) {
            matriz[i][j] = char(PIXEL_CHAR);

            if (i == X_AXIS_SIZE/2){
                matriz[i][j] = char(45);
            }

            if (j == Y_AXIS_SIZE/2){
                matriz[i][j] = '|';
            }

            if (i == X_AXIS_SIZE/2 && j == Y_AXIS_SIZE/2){
                matriz[i][j] = '+';
            }
        }
    }

    printf("\n");

    for (int i = 0; i < X_AXIS_SIZE; ++i) {
        for (int j = 0; j < Y_AXIS_SIZE; ++j) {
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void waitEnterKeyToContinue() {
    cout << "Press ENTER to continue..." << endl;
    clearInputBuffer();
    cin.get();
}

int init() {
    while(true){
        clearConsole();
        printMenuOptions();
        switch (askUserOption()) {
            case 0:
                return 0;
            case 1:
                initCartesianPlane();
                waitEnterKeyToContinue();
                break;
            case 2:
                cout << "Caso 2\n";
                break;
            case 3:
                cout << "Caso 3\n";
                break;
            case 4:
                cout << "Caso 4\n";
                break;
            case 5:
                cout << "Caso 5\n";
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