// Section 12
// Challenge

/* Write a C++ function named apply_all that expects two arrays of integers and their sizes and
  dynamically allocates a new array of integers whose size is the product of the 2 array sizes
  
  The function should loop through the second array and multiplies each element across each element of array 1 and store the
  product in the newly created array.
  
  The function should return a pointer to the newly allocated array.
  
  You can also write a print function that expects a pointer to an array of integers and its size and display the
  elements in the array.
    
  For example,
  
  Below is the output from the following code which would be in main:
  
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    cout << "Array 1: " ;
    print(array1,5);
    
    cout << "Array 2: " ;
    print(array2,3);
    
    int *results = apply_all(array1, 5, array2, 3);
    cout << "Result: " ;
    print(results,15);
   
   Output
   ---------------------
   Array 1: [ 1 2 3 4 5 ]
   Array 2: [ 10 20 30 ]
   Result: [ 10 20 30 40 50 20 40 60 80 100 30 60 90 120 150 ]
*/

#include <iostream>

void print(const int *const arr, size_t arr_size);
int *apply_all(const int *const arr1, size_t arr1_size, const int *const arr2, size_t arr2_size);
  
using namespace std;

int main() {
    const size_t array1_size {5};
    const size_t array2_size {3};
    
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    cout << "Array 1: " ;
    print(array1,array1_size);
    
    cout << "Array 2: " ;
    print(array2,array2_size);
    
    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size {array1_size * array2_size};

    cout << "Result: " ;
    print(results, results_size);
    
    delete [] results;
    cout << endl;

    return 0;
}

void print(const int *const arr, size_t arr_size)
{
  cout << "[ ";
  for(size_t i{0}; i < arr_size; i++)
    cout << arr[i] << ' ';
  cout << ']' << endl;
}

int *apply_all(const int *const arr1, size_t arr1_size, const int *const arr2, size_t arr2_size)
{
  int *arr{nullptr};
  arr = new int [arr1_size + arr2_size];

  int z{0};
  for(size_t y{0} ; y< arr2_size; y++)
    for(size_t x{0} ; x< arr1_size; x++)
    {
      arr[z] = arr1[x] * arr2[y];
      z++;
    }
  return arr;
}
