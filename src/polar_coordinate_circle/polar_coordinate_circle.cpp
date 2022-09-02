#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#include <cmath>
#include "polar_coordinate_circle.h"
#include "../utils/utils.h"

void polar_coordinate_circle(int xc, int yc, int r, char** matriz) {
    float angle;

    for (int i = 0; i < 100; i++) {
        // ângulo
        angle = i * 2 * (M_PI / 100);

        insertPixel(round(xc + (cos(angle) * r)), round(yc + (sin(angle) * r)), matriz);
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

#pragma clang diagnostic pop