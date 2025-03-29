#include <iostream>
#include <string>
#include <fstream>
using namespace std;

char encrypt(const char ch,int& number,const string& key){
    char temp = ch^key[number];
    number=number++%key.size();
    return temp;
}
int main(int argc,char *argv[]){
    if(argc!=3){
        cout<<"You should type only 2 argument"<<endl;
        return -1;
    }
    ifstream in{argv[1]};
    if(!in){
        cout<<"Can't open file"<<endl;
        return -1;
    }
    ofstream out{"result2.txt"};
    if(!out){
        cout<<"Can't create file"<<endl;
        return -1;
    }
    char temp;
    int counter{0};
    string key {argv[2]};
    while(in.get(temp)){
        out<<encrypt(temp,counter,key);
    }    
}