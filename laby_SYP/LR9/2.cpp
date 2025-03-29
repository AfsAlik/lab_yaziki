#include <iostream>
template <typename T1>
T1 getmax(T1 t1,T1 t2){
    return t1>t2? t1:t2;
}

template<typename T1>
T1 getmax(T1 t[],size_t size){
    T1 answer = t[0];
    for(int i=0;i<size;i++){
        if(t[i]>answer) answer = t[i];
    }
    return answer;
}

int main(){
    int first = 3, second = 5;
    int arr[] = {3,9,1,5};
    std::cout<<"max int = "<<getmax(first,second)<<std::endl;
    std::cout<<"max int = "<<getmax(arr,sizeof(arr)/sizeof(arr[0]))<<std::endl;
}