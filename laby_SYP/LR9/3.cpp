#include <iostream>
#include <vector>
#include <algorithm>
template <typename T1>
class Tstack
{
    protected:
    int numItem;
    T1* item;
    public:
    Tstack(size_t size =10) : numItem{0}{
        item = new T1[size];
    }
    ~Tstack(){
        delete [] item;
    }
    void push(T1 t);
    T1 pop();
};

template <typename T1>
void Tstack<T1>::push(T1 t){
    item[numItem++]=t;
}

template<typename T1>
T1 Tstack<T1>::pop(){
    return item[--numItem];
}

int main(){
    Tstack <int> stack{};
    std::vector <int> arr{1,5,3};
    std::sort(arr.begin(),arr.end(),std::less<int>());
    for(auto h:arr) stack.push(h);
    for(int i=0;i<3;i++)
    {
        std::cout<<stack.pop()<<" ";
    }
}