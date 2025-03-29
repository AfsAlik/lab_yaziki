#include <iostream>
using namespace std;
int length1(char* word){
    int i=0;
    char* temp=word;
    while(*temp!='\0')    {
        i++;
        temp++;
    }
    return i;
}
void copy(char* l, char* r){
    int size = length1(r)+1;
    delete[] l;
    l = new char [size];
    char* it1 = l;
    char* it2 = r;
    while(*it2!='\0'){
        *it1 = *it2;
        it1++;
        it2++;
    }
    *it1=*it2;
}
char* strcat(char* l,char* r){
    int size = length1(r) + length1(l) + 1;
    char* temp = new char [size];
    char* it1 = temp;
    char* it2 = l;
    char* it3 = r;
    while(*it2!='\0'){
        *it1 = *it2;
        it1++;
        it2++;
    }
    while(*it3!='\0'){
        *it1 = *it3;
        it1++;
        it3++;
    }
    *it1='\0';
    copy(l,temp);
    return l;
}
int strcmp(const char *l, const char *r){
    while (*l){
        if (*l != *r) {
            break;
        }
        l++;
        r++;
    }
 
    return *(const unsigned char*)l - *(const unsigned char*)r;
}
int main(){
    char *str1 = new char [length1("qwerty")+1];
    char *str2 = new char [length1("1234567890")+1];
    copy(str1,"qwerty");
    copy(str2,"1234567890");
    cout<<str1<<" Length: "<<length1(str1)<<endl;
    cout<<str2<<" Length: "<<length1(str2)<<endl;
    strcat(str1,str2);
    cout<<str1<<" Length: "<<length1(str1)<<endl;
    cout<<strcmp(str1,str2)<<endl;
}