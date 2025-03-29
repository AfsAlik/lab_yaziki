#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
using namespace std;

#include <vector>
#include <iostream>

bool bigger(const int lhs,const int rhs){
    return lhs>rhs;
}

bool lesser(const int lhs,const int rhs){
    return lhs<rhs;
}

void insertionSort( std::vector<int> & array, int left, int right, bool(*func)(const int,const int)){
    for( int p = left; p<=right; ++p )    {
        int tmp = std::move( array[ p ] );
        int j;
        for( j = p; j > 0 && func(tmp,array[ j - 1 ]); --j )
          array[ j ] = std::move( array[ j - 1 ] );
        array[ j ] = std::move( tmp );
    }
}

int main(){
    vector<int> arr {1,7,2,15,543,254,13,84,93,59,234};
    insertionSort(arr,0,arr.size()-1,lesser);
    for(const auto& h: arr)
    cout<<h<<" ";
    cout<<endl;
    insertionSort(arr,0,arr.size()-1,bigger);
    for(const auto& h: arr)
    cout<<h<<" ";
}