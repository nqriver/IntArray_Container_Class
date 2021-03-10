#include <iostream>
#include <algorithm>
#include "../includes/IntArray.h"

int main() {
    IntArray arr(5);
    for (int i { 0 }; i < 5; ++i){
        arr[i] = 10 - i;
    }
    auto iter = arr.begin();
    while (iter != arr.end()){
        std::cout << ++(*(iter++)) << " ";
    }
    arr.print();
    return 0;
}
