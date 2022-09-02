#include "polar_coordinate_circle.h"
#include "../utils/utils.h"

void polar_coordinate_circle(int xc, int yc, int r, char** matriz) {
    int x, y, d;

    x = 0;
    y = r;
    d = 3 - 2 * r;

    drawSimetricPixels(xc, yc, x, y, matriz);

    while(x <= y) {
        if(d <= 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * x - 4 * y + 10;
            y = y - 1;
        }

        x = x + 1;

        drawSimetricPixels(xc, yc, x, y, matriz);
    }
}

void usePolarCoordinateCircle(char** matriz) {
    int choice[3];
    askCircleParams(choice);
    int xcentro = choice[0];
    int ycentro = choice[1];
    int raio = choice[2];

    polar_coordinate_circle(xcentro, ycentro, raio, matriz);
}
