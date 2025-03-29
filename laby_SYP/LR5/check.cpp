#include <fstream>
#include <iostream>
using namespace std;
int main(){
    ifstream in("check.txt");
    if(!in){
        cout<<"Cant"<<endl;
        return -1;
    }
    char ch;
    while(in.get(ch)){
        cout<<(int)ch<<endl;
    }
}