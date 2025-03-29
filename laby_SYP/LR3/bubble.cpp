#include <iostream>
void bubbleSort(int arr[], int n){
    int i, j;
    bool flag;
    for(i = 0; i < n; i++)
    {
        flag = false;                                   
        for(j = 0; j < n-i-1; j++)
        {
            
            if( arr[j] > arr[j+1])
            {
                std::swap(arr[j],arr[j+1]);
                flag = true;
            }
        }
        if(!flag)
        {
            break;
        }
    }
}