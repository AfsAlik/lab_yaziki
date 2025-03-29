#include "shape.h"
class circuit : public shape
{
    int x1,y1;
    int diam;
    public:
    void info()
    {
        std::cout<<"I'am circuit class"<<std::endl;
    }
    circuit(int _x1,int _y1, int _diam): x1{_x1},y1{_y1},diam{_diam}{}
};