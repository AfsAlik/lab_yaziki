#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <conio.h>
#define N 5

#include "utility.h"

using namespace std;
int main(){

    float m[N][N];
    int i,j;
    srand(time(NULL));
    for(i=0;i<N;i++)
    {
      for(j=0;j<N;j++) m[i][j] = rand()/10.;
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++) cout<<setw(8)<<setprecision(5)<<m[i][j];
        cout<<endl;
    }

    float minValue = min(m);
    float maxValue = max(m);
    float minBottom = minBottomTriangle(m);
    float maxBottom = maxBottomTriangle(m);
    float maxUpper = maxUpperTriangle(m);
    float minUpper = minUpperTriangle(m);
    float minDiagMain = minMainDiag(m);
    float maxDiagMain = maxMainDiag(m);
    float maxDiagSec = maxSecondaryDiag(m);
    float minDiagSec = minSecondaryDiag(m);
    float averageArray = average(m);
    float averageBotom = averageBottomTriangle(m);
    float averageUpper = averageUpperTriangle(m);
    float sumUpper = sumUpperTriangle(m);
    float sumBottom = sumBottomTriangle(m);
    float mostclosed = closeToAverage(m);
    cout<<"Min: "<<minValue<<endl;
    cout<<"Max: "<<maxValue<<endl; 
    cout<<"MinBottomTriangle: "<<minBottom<<endl;
    cout<<"MaxBottomTriangle: "<<maxBottom<<endl;
    cout<<"MaxUpperTriangle: "<<maxUpper<<endl;
    cout<<"MinUpperTriangle: "<<minUpper<<endl;
    cout<<"minMainDiag: "<<minDiagMain<<endl;
    cout<<"maxMainDiag: "<<maxDiagMain<<endl;
    cout<<"maxSecondaryDiag: "<<maxDiagSec<<endl;
    cout<<"minSecondaryDiag: "<<minDiagSec<<endl;
    cout<<"average: "<<averageArray<<endl;
    cout<<"averageBottomTriangle: "<<averageBotom<<endl;
    cout<<"averageUpperTriangle: "<<averageUpper<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<"Sum of "<<i+1<<" row: "<<rowSum(m,i)<<endl;
    }

    for(int i=0;i<5;i++)
    {
        cout<<"Sum of "<<i+1<<" column: "<<columnSum(m,i)<<endl;
    }

    for(int i=0;i<5;i++)
    {
        cout<<"Min of "<<i+1<<" row: "<<rowMin(m,i)<<endl;
    }
    for(int i=0;i<5;i++)
    {
        cout<<"Max of "<<i+1<<" row: "<<rowMax(m,i)<<endl;
    }

    for(int i=0;i<5;i++)
    {
        cout<<"Min of "<<i+1<<" column: "<<columnMin(m,i)<<endl;
    }
    for(int i=0;i<5;i++)
    {
        cout<<"Max of "<<i+1<<" column: "<<columnMax(m,i)<<endl;
    }

    for(int i=0;i<5;i++)
    {
        cout<<"Average of "<<i+1<<" column: "<<averageColumn(m,i)<<endl;
    }
    for(int i=0;i<5;i++)
    {
        cout<<"Average of "<<i+1<<" row: "<<averageRow(m,i)<<endl;
    }

    cout<<"Sum Upper Triangle: "<<sumUpper<<endl;
    cout<<"Sum Bottom Triangle: "<<sumBottom<<endl;
    cout<<"Most closed to average: "<<mostclosed<<endl;

    getch();
}