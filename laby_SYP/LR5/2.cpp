#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main(){
    string file_name;
    cout<<"Enter file name"<<endl;
    cin>>file_name;
    ifstream out(file_name.c_str());
    ofstream in("result1.txt");
    if(!out){
        cout<<"Can't find file"<<endl;
        return -1;
    }
    if(!in){
        cout<<"Can't create file for result"<<endl;
        return -1;
    }
    stringstream number;
    bool find_number {false};
    int counter{0};
    char temp;
    while(out.get(temp)){
        if(!find_number){
            if(temp=='-') {counter++;continue;}
            if(counter==2){find_number =true;counter=0;continue;}
            if(temp!='-' && temp!=' ' && temp!='\n'){ 
                number<<temp;
                continue;
            }
            continue;
        }
        if(temp =='\f'){
            {in<<' ';in<<number.rdbuf();number.flush();in<<'\n';find_number=false;continue;}
        in<<temp;
    }

    }
}