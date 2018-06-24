#include <iostream>
#include <algorithm>

//http://slides.com/uczelnia_bt_kw/pointerz#/7/4
// Implement min() function that:
// accepts two args: array, function pointer
// works on C-style array (arr, ptr) (yes, template)
// returns void
// when min element is found function pointer is invoked
// function pointer has signature: void ()(const TYPE &t)

template<typename T>
void fun(T t)
{
    std::cout << "min value of array: " << t << std::endl;
}

template<typename T>
void minElelment(T* array, std::size_t size, void (fun_ptr)(T&))
{
	auto v = *(std::min_element(array, array+size));
	fun_ptr(v);
}

int main()
{
	int arr[] = {4,7,2,4,9,0};
	minElelment(arr, sizeof(arr)/sizeof(int), fun);
}