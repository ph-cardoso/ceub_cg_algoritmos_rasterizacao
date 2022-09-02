#include <iostream>
#include "utils/utils.h"
#include "bresenham_line/bresenham_line.h"

using namespace std;

int init() {
    char **matriz = generateDinamicMatrix();
    while(true){
        clearConsole();
        printMenuOptions();
        switch (askUserOption()) {
            case 0:
                return 0;
            case 1:
                cleanCartesianPlane(matriz);
                printCartesianPlane(matriz);
                waitEnterKeyToContinue();
                break;
            case 2:
                cleanCartesianPlane(matriz);
                useBresenhamLine(matriz);
                printCartesianPlane(matriz);
                waitEnterKeyToContinue();
                break;
            case 3:
                cleanCartesianPlane(matriz);
                insertPixel(4, 4, matriz);
                insertPixel(4, -4, matriz);
                insertPixel(-4, 4, matriz);
                insertPixel(-4, -4, matriz);
                printCartesianPlane(matriz);
                waitEnterKeyToContinue();
                break;
            case 4:
                cout << "Caso 4\n";
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