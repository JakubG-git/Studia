//
// Created by Jakub on 4/9/2022.
//
#include "shapecomposite.h"
bool Shapes::ShapeComposite::isIn(int x, int y) const {
    switch (this->shapeOperation_) {
        case Shapes::ShapeOperation::SUM:
            if (this->shape->isIn(x, y) || this->shape1->isIn(x,y))return true;
            return false;
        case Shapes::ShapeOperation::INTERSECTION:
            if (this->shape->isIn(x, y) && this->shape1->isIn(x,y))return true;
            return false;
        case Shapes::ShapeOperation::DIFFERENCE:
            if (this->shape->isIn(x, y) && !this->shape1->isIn(x,y))return true;
            return false;
    }
}

