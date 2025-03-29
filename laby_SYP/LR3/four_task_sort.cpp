#include <vector>
#include <iostream>
using namespace std;
void sort(vector<int>& array){
    vector<int> odd;
    vector<int> even;
    for(const auto& h:array)    {
        if(h%2) odd.push_back(h);
        else even.push_back(h);
    }
    for(int i=0;i<odd.size();i++)    {
        int temp = std::move(odd[i]);
        int j;
        for( j = i; j > 0 && temp > odd[ j - 1 ]; --j )
          odd[ j ] = std::move( odd[ j - 1 ] );
        odd[ j ] = std::move( temp );
    }
    for(int i=0;i<even.size();i++)    {
        int temp = std::move(even[i]);
        int j;
        for( j = i; j > 0 && temp < even[ j - 1 ]; --j )
          even[ j ] = std::move( even[ j - 1 ] );
        even[ j ] = std::move( temp );
    }
    even.insert(end(even),begin(odd),end(odd));
    array.swap(even);
}

int main(){
    vector <int> arr {1,7,5,4,9,12,17,12,18,16,23,12,175,12,171};
    sort(arr);
    for(const auto& h:arr)
    cout<<h<<" ";
}