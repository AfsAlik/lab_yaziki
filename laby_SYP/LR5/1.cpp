#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void check_for_blank(int& counter_for_blank,int& counter_for_other,const string word){
    for(const auto& h: word){
        if(isspace(h) || iscntrl(h)) counter_for_blank++;
        else counter_for_other++;
    }
}

void check_for_sub(vector<string>& arr,const string& words,const string& find_word){
    stringstream os;
    os<<words;
    while(os){
        string temp;
        os>>temp;
        if(temp.find(find_word)!=string::npos) arr.push_back(temp);
    }

}

int main(){
    vector<string> arr;
    string find_substring;
    string file_name;
    cout<<"File name: "<<endl;
    cin>>file_name;
    ifstream fs(file_name.c_str());
    int counter_for_blank {0};
    int counter_for_other {0};
    if(!fs){
        cout<<"File doesn't not exist"<<endl;
        return -1;
    }
    cout<<"Find next substring:"<<endl;
    cin>>find_substring;
    while(fs){
        string temp;
        getline(fs,temp);
        cout<<temp<<endl;
        check_for_blank(counter_for_blank,counter_for_other,temp);
        check_for_sub(arr,temp,find_substring);

    }
    cout<<"In this file " << counter_for_blank<<" blank characters"<<endl;
    cout<<"And " << counter_for_other<<" other character"<<endl;

    fs.close();
    ofstream in("result.txt");
    if(!in){
        cout<<"Can't create file"<<endl;
        return -1;
    }
    for(const auto h:arr){
        in<<h;
        in<<endl;
      }

}