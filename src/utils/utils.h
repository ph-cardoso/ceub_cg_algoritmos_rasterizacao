#ifndef ALGORITMOS_RASTERIZACAO_UTILS_H
#define ALGORITMOS_RASTERIZACAO_UTILS_H

void clearInputBuffer();
void clearConsole();
void printMenuOptions();
int askUserOption();
void printCartesianPlane(char**);
char** generateDinamicMatrix();
void cleanCartesianPlane(char**);
void waitEnterKeyToContinue();
void insertPixel(int, int, char**);
void askCircleParams(int*);
void askCoordenadas(int*);
void drawSimetricPixels(int, int, int, int, char**);

#endif //ALGORITMOS_RASTERIZACAO_UTILS_H
