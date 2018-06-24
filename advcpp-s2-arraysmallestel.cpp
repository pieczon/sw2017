#include <iostream>
#include <array>

//http://slides.com/uczelnia_bt_kw/pointerz#/3/3
// excercise
// implement a find min function that: 
// is a template function ! :)
// accepts arguments as an array (pointer, array)
// returns smallest element

template <class T> 
T min(T _arr[], int size)
{
    T minimum = _arr[0];
    for(int i = 0; i < size; ++i)
    {
        if (_arr[i] < minimum) 
        {
            minimum = _arr[i];
        }
    }
    return minimum;
}
int main()
{
    int arr[6]= {5,1,6,8,2,3};
    int *ptrarr = arr;
    std::cout << " min in array: " << min(arr, 6) << std::endl;
    std::cout << " min in ptr: " << min(ptrarr, 6) << std::endl;
}