#include "utils.h"
#include "../constants.h"
#include <iostream>
#include <cstdlib>

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
            " (3) - Imprime o traçado de um círculo (Sistemas de coordenadas polares)\n"
            " (4) - Imprime o traçado de um círculo (Algoritmo de Bresenham)\n" << endl;
}

int askUserOption() {
    int input;
    cout << "\nOpcao: ";
    cin >> input;
    return input;
}

void printCartesianPlane(char** matriz) {
    printf("\n");

    for (int i = 0; i < X_AXIS_SIZE; ++i) {
        for (int j = 0; j < Y_AXIS_SIZE; ++j) {
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

char** generateDinamicMatrix() {
    char **mat = static_cast<char **>(malloc(X_AXIS_SIZE * sizeof(char *)));
    for (int i = 0; i < X_AXIS_SIZE; ++i) {
        mat[i] = static_cast<char *>(malloc(Y_AXIS_SIZE * sizeof(char)));
    }

    return mat;
}

void cleanCartesianPlane(char** matriz) {
    for (int i = 0; i < X_AXIS_SIZE; ++i) {
        for (int j = 0; j < Y_AXIS_SIZE; ++j) {
            matriz[i][j] = char(SPACE_CHAR);

            if (i == X_AXIS_SIZE / 2) {
                matriz[i][j] = char(45);
            }

            if (j == Y_AXIS_SIZE / 2) {
                matriz[i][j] = '|';
            }

            if (i == X_AXIS_SIZE / 2 && j == Y_AXIS_SIZE / 2) {
                matriz[i][j] = '+';
            }
        }
    }
}

void waitEnterKeyToContinue() {
    cout << "Press ENTER to continue..." << endl;
    clearInputBuffer();
    cin.get();
}

void insertPixel(int y, int x, char** matriz) {
    int xPos;
    int yPos;

    if(x >= 0) {
        xPos = X_AXIS_SIZE - (x + (X_AXIS_SIZE / 2));
    } else {
        xPos = (X_AXIS_SIZE / 2) + abs(x);
    }

    if(y >= 0) {
        yPos = y + (Y_AXIS_SIZE / 2);
    } else {
        yPos = (Y_AXIS_SIZE / 2) - abs(y);
    }

    matriz[xPos][yPos] = char(PIXEL_CHAR);
    cout << "(" << x << "," << y << ")" << endl;
}

void askCoordenadas(int* choice) {
    cout << "Insira a coordenada do ponto x1: ";
    cin >> choice[0];
    cout << "Insira a coordenada do ponto y1: ";
    cin >> choice[1];
    cout << "Insira a coordenada do ponto x2: ";
    cin >> choice[2];
    cout << "Insira a coordenada do ponto y2: ";
    cin >> choice[3];
}

void askCircleParams(int* choice) {
    cout << "Insira a coordenada do ponto x_centro: ";
    cin >> choice[0];
    cout << "Insira a coordenada do ponto y_centro: ";
    cin >> choice[1];
    cout << "Insira o tamanho do raio: ";
    cin >> choice[2];
}

void drawSimetricPixels(int xc, int yc, int x, int y, char** matriz) {
    // Inserção dos pixels nas 8 octantes por simetria
    insertPixel(xc + x, yc + y, matriz);
    insertPixel(xc - x, yc + y, matriz);
    insertPixel(xc + x, yc - y, matriz);
    insertPixel(xc - x, yc - y, matriz);
    insertPixel(xc + y, yc + x, matriz);
    insertPixel(xc - y, yc + x, matriz);
    insertPixel(xc + y, yc - x, matriz);
    insertPixel(xc - y, yc - x, matriz);
}
