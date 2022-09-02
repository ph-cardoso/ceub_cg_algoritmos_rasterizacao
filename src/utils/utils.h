#ifndef ALGORITMOS_RASTERIZACAO_UTILS_H
#define ALGORITMOS_RASTERIZACAO_UTILS_H

#endif //ALGORITMOS_RASTERIZACAO_UTILS_H

#define X_AXIS_SIZE 40 // + 20 | - 20
#define Y_AXIS_SIZE 80 // + 40 | - 40
#define PIXEL_CHAR 42
#define SPACE_CHAR ' '

void clearInputBuffer();
void clearConsole();
void printMenuOptions();
int askUserOption();
void printCartesianPlane(char**);
char** generateDinamicMatrix();
void cleanCartesianPlane(char**);
void waitEnterKeyToContinue();
void insertPixel(int, int, char**);
