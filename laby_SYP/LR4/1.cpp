#include <iostream>
#include <string.h>
using namespace std;
int main(){
    char test1[20];
    char test2[20];
    cin>>test1>>test2;
    cout<<"First word length: "<<strlen(test1)<<endl;
    cout<<"Second word length: "<<strlen(test1)<<endl;
    cout<<"Concatenated both word: "<<strcat(test1,test2)<<endl;
    cout<<"Word equal? Answer: ";
    strcmp(test1,test2)? cout<<"No" : cout<<"Yes";
    cout<<endl;
    strcpy(test1,test2);
    cout<<"Word equal? Answer: ";
    strcmp(test1,test2)? cout<<"No" : cout<<"Yes";
}