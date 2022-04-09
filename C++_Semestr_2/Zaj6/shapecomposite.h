//
// Created by Jakub on 4/9/2022.
//
#include <memory>
#include "shape.h"
#ifndef ZAD4SHAPEDRAWING_SHAPECOMPOSITE_H
#define ZAD4SHAPEDRAWING_SHAPECOMPOSITE_H
namespace Shapes{
    enum class ShapeOperation {INTERSECTION, SUM, DIFFERENCE};
    class ShapeComposite : public Shape{
    private:
        ShapeOperation shapeOperation_;
        std::shared_ptr<Shape> shape;
        std::shared_ptr<Shape> shape1;
    public:
        ShapeComposite() = default;
        ShapeComposite(std::shared_ptr<Shape> sharedPtr, std::shared_ptr<Shape> sharedPtr1, ShapeOperation shapeOperation) :
        shapeOperation_(shapeOperation), shape(sharedPtr), shape1(sharedPtr1) {};
        bool isIn(int x, int y) const override;
    };
}
#endif //ZAD4SHAPEDRAWING_SHAPECOMPOSITE_H
