#include <iostream>
#include <algorithm>
#include "../includes/IntArray.h"

void test();
void test_2();

int main() {
    test();
    test_2();
    return 0;
}

void test(){
    constexpr int size { 50 };
    IntArray arr(size);
    for (int i { 0 }; i < size; ++i){
        arr[i] = size - i;
    }
    std::cout << arr;

    auto iter = arr.begin();
    while (iter != arr.end()){
        ++(*(iter++));
    }
    std::cout << arr;

    for (auto &element : arr){
        element += 100;
    }

    arr.resize(70);

    std::cout << arr;
    std::sort(arr.begin(), arr.end());
    std::cout << arr;
    int indexToRemove {arr.size()-1};
    arr.remove(indexToRemove);
    arr[0] = 22;
    arr.insertBefore(899, 6);
    std::cout << arr;
    std::fill(arr.begin(), arr.end(), 2);
    std::cout << arr;
    arr.erase();
}

void test_2(){
    IntArray arr {1,2,3,4,5,6,7}; //initialized via initializer_list
    std::cout << arr;
    arr = {90,80,70};             //copy assignment via initializer_list
    std::cout << "Current last element : " << *(std::prev(arr.end(), 1)) << std::endl;
    arr.resize(10);
    std::cout << arr;
}
