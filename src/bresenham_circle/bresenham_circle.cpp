#include "bresenham_circle.h"
#include "../utils/utils.h"

void bresenham_circle(int xc, int yc, int r, char** matriz) {
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    drawSimetricPixels(xc, yc, x, y, matriz);

    while (y >= x) {
        // incremento de x
        x++;

        // parâmetro auxiliar 'd'
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }

        drawSimetricPixels(xc, yc, x, y, matriz);
    }
}

void useBresenhamCircle(char** matriz) {
    int choice[3];
    askCircleParams(choice);
    int xcentro = choice[0];
    int ycentro = choice[1];
    int raio = choice[2];

    bresenham_circle(xcentro, ycentro, raio, matriz);
}
