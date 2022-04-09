//
// Created by Jakub on 4/9/2022.
//
#include "circle.h"

bool Shapes::Circle::isIn(int x, int y) const {
    int d2 = (x - this->xCenter) * (x - this->xCenter) + (y - this->yCenter) * (y - this->yCenter);
    int r2 = radius*radius;
    if (d2 <= r2) return true;
    return false;
}
