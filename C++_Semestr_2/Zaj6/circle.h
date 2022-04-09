//
// Created by Jakub on 4/9/2022.
//
#include "shape.h"
#ifndef ZAD4SHAPEDRAWING_CIRCLE_H
#define ZAD4SHAPEDRAWING_CIRCLE_H
namespace Shapes{
    class Circle : public Shape{
    private:
        int xCenter, yCenter, radius;
    public:
        Circle() = default;
        Circle(int x, int y, int r) : xCenter(x), yCenter(y), radius(r) {};
        bool isIn(int x, int y) const override ;
        int x() const {return this->xCenter;}
        int y() const {return this->yCenter;}
        int getRadius() const {return this->radius;}
    };
}
#endif //ZAD4SHAPEDRAWING_CIRCLE_H
