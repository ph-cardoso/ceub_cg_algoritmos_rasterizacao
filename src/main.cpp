#include <iostream>
#include "utils/utils.h"
#include "bresenham_line/bresenham_line.h"
#include "bresenham_circle/bresenham_circle.h"

using namespace std;

int init() {
    char **matriz = generateDinamicMatrix();

    // Loop de controle
    while(true){
        clearConsole();
        printMenuOptions();

        switch (askUserOption()) {
            case 0:
                // Finaliza o programa
                return 0;
            case 1:
                // Linha com DDA
                cleanCartesianPlane(matriz);
                printCartesianPlane(matriz);
                waitEnterKeyToContinue();
                break;
            case 2:
                // Linha com Bresenham
                cleanCartesianPlane(matriz);
                useBresenhamLine(matriz);
                printCartesianPlane(matriz);
                waitEnterKeyToContinue();
                break;
            case 3:
                // Círculo com Coordenadas Polares
                cleanCartesianPlane(matriz);
                insertPixel(4, 4, matriz);
                insertPixel(4, -4, matriz);
                insertPixel(-4, 4, matriz);
                insertPixel(-4, -4, matriz);
                printCartesianPlane(matriz);
                waitEnterKeyToContinue();
                break;
            case 4:
                // Círculo com Bresenham
                cleanCartesianPlane(matriz);
                useBresenhamCircle(matriz);
                printCartesianPlane(matriz);
                waitEnterKeyToContinue();
                break;
            default:
                // Opção inválida
                cout << "\nEssa opcao nao pode ser executada. Tente inserir uma opcao válida...\n";
                waitEnterKeyToContinue();
        }
    }
}

int main() {
    init();
    return 0;
}