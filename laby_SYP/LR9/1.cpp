#include <iostream>
#include <vector>
template <typename T1>
void Sort(T1& arr){
    for(int i=0;i<arr.size()-1;i++){
        for(int j=0;j<arr.size()-i-1;j++){
            if(arr[j]>arr[j+1]) std::swap(arr[j],arr[j+1]);
        }
    }
}
int main(){
    std::vector<int> arr{23,1,65,2};
    Sort(arr);
    for(auto h:arr)
    std::cout<<h<<" ";
}