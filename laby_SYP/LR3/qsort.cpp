#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
using namespace std::chrono;

#include <vector>
#include <iostream>


template <typename T>
void insertionSort( std::vector<T> & array, int left, int right ){
    for( int p = left; p<=right; ++p )    {
        T tmp = std::move( array[ p ] );
        int j;
        for( j = p; j > 0 && tmp < array[ j - 1 ]; --j )
          array[ j ] = std::move( array[ j - 1 ] );
        array[ j ] = std::move( tmp );
    }
}

template <typename T>
const T & median( std::vector<T> & a, int left, int right ){
  int center = ( left + right ) / 2;
  if( a[ center ] < a[ left ] )
    std::swap( a[ left ], a[ center ] );
  if( a[ right ] < a[ left ] )
    std::swap( a[ left ], a[ right ] );
  if( a[ right ] < a[ center ] )
    std::swap( a[ center ], a[ right ] );
  std::swap( a[ center ], a[ right - 1 ] );
  return a[ right - 1 ];
}

template <typename T>
void quicksort( std::vector<T> & a, int left, int right ){
  if( left + 10 <= right )  {
  
    const T & pivot = median( a, left, right );
    int i = left, j = right - 1;
    for( ; ; )    {
        while( a[ ++i ] < pivot ) { }
        while( pivot < a[ --j ] ) { }
        if( i < j )
          std::swap( a[ i ], a[ j ] );
        else
          break;
    }
    std::swap( a[ i ], a[ right - 1 ] );
    quicksort( a, left, i - 1 );
    quicksort( a, i + 1, right );
  }
   else
     insertionSort( a, left, right );
}

template <typename T>
void sort( std::vector<T> & array ){
    quicksort( array, 0, array.size( ) - 1 );
}

// int main()
// {
//   std::random_device dev;
//   std::mt19937 rng(dev());
//   std::uniform_int_distribution<std::mt19937::result_type> dist(INT_MIN,INT_MAX);
//   std::vector<int> numbers;
//   for(int i=0;i<100000;i++)
//   {
//     numbers.push_back(dist(rng));
//   }
//   sort(numbers)

//   if(std::is_sorted(numbers.begin(),numbers.end()))
//   {
//     std::cout<<"sorted"<<std::endl;
//   }
//   else 
//   {
//     std::cout<<"Not sorted"<<std::endl;
//   }
//   for(auto& h:numbers)
//   std::cout<<h<<std::endl;
//}