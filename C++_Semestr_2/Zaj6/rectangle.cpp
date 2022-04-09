//
// Created by Jakub on 4/9/2022.
//
#include "rectangle.h"
bool Shapes::Rectangle::isIn(int x, int y) const {
    if ((x >= this->x_ && x <= this->xTo_)&&(y >= this->y_ && y <= this->yTo_)) return true;
    return false;
}