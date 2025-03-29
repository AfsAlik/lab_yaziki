#include <iostream>
#include <cstring>
template <typename T1>
T1 getmax(T1 t1,T1 t2){
    return t1>t2? t1:t2;
}
char* getmax(char s1,char s2){
    if(strcmp(&s1,&s2)>0) return &s1;
    else return &s2;
}
template <typename T1>
T1 getmax(T1 t[],size_t size){
    T1 answer = t[0];
    for(int i=0;i<size;i++){
        if(t[i]>answer) answer = t[i];
    }
    return answer;
}
int main(){
    int left {3},second{5};
    char *s1 = "String 1";
    char *s2 = "String 2";
    std::cout<<"Max int = "<<getmax(left,second)<<std::endl;
    std::cout<<"Max string = "<<getmax(s1,s2)<<std::endl;
}