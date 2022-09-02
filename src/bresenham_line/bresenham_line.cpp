#include "bresenham_line.h"
#include "../utils/utils.h"
#include <iostream>

void bresenham_line(int x1, int y1, int x2, int y2, char** matriz) {
    int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;

    dx = x2 - x1;
    dy = y2 - y1;

    dx1 = abs(dx);
    dy1 = abs(dy);

    px = 2 * dy1 - dx1;
    py = 2 * dx1 - dy1;

    if(dy1 <= dx1) {
        if(dx >= 0) {
            x = x1;
            y = y1;
            xe = x2;
        } else {
            x = x2;
            y = y2;
            xe = x1;
        }

        insertPixel(x, y, matriz);

        for(i = 0; x < xe; i++) {
            x = x + 1;

            if(px < 0) {
                px = px + 2 * dy1;
            } else {
                if((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
                    y = y + 1;
                } else {
                    y = y - 1;
                }

                px = px + 2 * (dy1 - dx1);
            }

            insertPixel(x, y, matriz);
        }
    } else {
        if( dy >= 0) {
            x = x1;
            y = y1;
            ye = y2;
        } else {
            x = x2;
            y = y2;
            ye = y1;
        }

        insertPixel(x, y, matriz);

        for(i = 0; y < ye; i++) {
            y = y + 1;

            if(py <= 0) {
                py = py + 2 * dx1;
            } else {
                if((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
                    x = x + 1;
                } else {
                    x = x - 1;
                }

                py = py + 2 * (dx1 - dy1);
            }

            insertPixel(x, y, matriz);
        }
    }
}

void useBresenhamLine(char** matriz) {
    int choice[4];
    askCoordenadas(choice);
    int x1 = choice[0];
    int y1 = choice[1];
    int x2 = choice[2];
    int y2 = choice[3];

    bresenham_line(x1, y1, x2, y2, matriz);
}
