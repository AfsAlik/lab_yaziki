#include "shape.h"
class triangle : public shape
{
    int x1,x2,x3;
    int y1,y2,y3;
    public:
    void info()
    {
        std::cout<<"I'am triangle class"<<std::endl;
    }
    triangle(int _x1,int _y1,int _x2,int _y2,int _x3,int _y3) : x1{_x1},y1{_y1},x2{_x2},y2{_y2},x3{_x3},y3{_y3} {}
};