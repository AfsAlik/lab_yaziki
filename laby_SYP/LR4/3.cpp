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
     char *strings[3];
     strings[0] = new char[length1("one")+1];
     strings[1] = new char[length1("two")+1];
     strings[2] = new char[length1("three")+1];
     copy(strings[0],"one");
     copy(strings[1],"two");
     copy(strings[2],"three");
     for(int i=0;i<3;i++){
        cout<<strings[i]<<" Length: "<<length1(strings[i])<<endl;
     }
     cout<<strcmp(strings[0],strings[1])<<endl;
     strcat(strings[0],strings[1]);
     strcat(strings[0],strings[2]);
     cout<<strings[0]<<"Length: "<<length1(strings[0])<<endl;
}