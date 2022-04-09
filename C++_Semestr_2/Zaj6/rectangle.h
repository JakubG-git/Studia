//
// Created by Jakub on 4/9/2022.
//
#include "shape.h"
#ifndef ZAD4SHAPEDRAWING_RECTANGLE_H
#define ZAD4SHAPEDRAWING_RECTANGLE_H
namespace Shapes{

    class Rectangle : public Shape{
    private:
        int x_, y_, xTo_, yTo_;
    public:
        Rectangle() = default;
        Rectangle(int x, int y, int xTo, int yTo) : x_(x), y_(y), xTo_(xTo), yTo_(yTo) {};
        bool isIn(int x, int y) const override;
        int x()const {return this->x_;}
        int y()const {return this->y_;}
        int xTo()const {return  this->xTo_;}
        int yTo()const {return this->yTo_;}
    };
}
#endif //ZAD4SHAPEDRAWING_RECTANGLE_H
