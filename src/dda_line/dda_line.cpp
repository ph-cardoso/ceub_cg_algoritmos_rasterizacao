#include <cmath>
#include "dda_line.h"
#include "../utils/utils.h"

void dda_line(int x1, int y1, int x2, int y2, char** matriz) {

    // determinação de dx e dy
    int dx = x2 - x1;
    int dy = y2 - y1;

    int step;

    // determinação do step
    if (abs(dx) > abs(dy)) {
        step = abs(dx);
    } else {
        step = abs(dy);
    }

    // incremento de x e y
    float x_incr = (float)dx / step;
    float y_incr = (float)dy / step;

    // ponto inicial
    float x = x1;
    float y = y1;

    // loop de inserção
    for (int i = 0; i < step; i ++) {
        insertPixel(round(x), round(y), matriz);
        x += x_incr;
        y += y_incr;
    }
}

void useDDALine(char** matriz) {
    int choice[4];
    askCoordenadas(choice);
    int x1 = choice[0];
    int y1 = choice[1];
    int x2 = choice[2];
    int y2 = choice[3];

    dda_line(x1, y1, x2, y2, matriz);
}
