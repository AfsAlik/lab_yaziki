#include "triangle.h"
#include "circuit.h"
int main(){

    shape fig1 {};
    shape* fig2 = new triangle{0,0,3,3,5,5};
    shape* fig3 = new circuit{5,5,50};
    fig1.info();
    fig2->info();
    fig3->info();
}