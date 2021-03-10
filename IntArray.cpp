//
// Created by lukas on 09.03.2021.
//

#include <cassert>
#include <iostream>
#include "IntArray.h"

IntArray::IntArray(int size) : m_size { size }{
    assert(size >=0 );
    m_array = new int [m_size];
}

IntArray::~IntArray() {
    m_size = 0;
    delete [] m_array;
}

int &IntArray::operator [](int index) {
    assert(index >=0 and index <= m_size-1);
    return m_array[index];
}

void IntArray::erase() {
    delete [] m_array;
    m_array = nullptr;
    m_size = 0;
}

void IntArray::reallocate(int new_size) {   // reallocate resizes the array.  Any existing elements will be destroyed.
    erase();
    if (new_size <= 0){
        return;
    }
    m_array = new int [new_size];
    m_size = new_size;
}

void IntArray::resize(int new_size) {   // resize resizes the array.  Any existing elements will be kept.
    if (new_size <= 0){
        erase();
        return;
    }
    else if (new_size == m_size){
        return;
    }
    else{
        int * data { new int [new_size]};
        if (m_size > 0){
            int elementsToCopy { m_size > new_size ? new_size : m_size};
            for (int i {0}; i < elementsToCopy; ++i){
                data[i] = m_array[i];
            }
        }
        delete [] m_array;
        m_array = data;
        m_size = new_size;
    }
}

void IntArray::insertBefore(int value, int index) {
    assert(index >= 0 and index < m_size);
    int * data { new int [m_size+1] };
    for (int i{ 0 }; i < index; ++i){
        data[i] = m_array[i];
    }
    data [index] = value;
    for (int i{ index + 1 }; i < m_size + 1; ++i){
        data[i] = m_array[i-1];
    }
    delete [] m_array;
    m_array = data;
    m_size ++;
}

void IntArray::remove(int index) {
    assert(index >= 0 and index < m_size);
    int * data { new int [m_size - 1]};
    for (int i { 0 }; i < index; ++i){
        data[i] = m_array[i];
    }
    for (int i { index }; i < m_size -1; ++i){
        data[i] = m_array[i+1];
    }
    delete [] m_array;
    m_array = data;
    m_size--;
}

void IntArray::print() {
    std::cout << "[";
    for (int i { 0 }; i < m_size-1; i++){
        std::cout << m_array[i] << ", ";
    }
    std::cout << m_array[m_size-1] << "]";

}

void quickSort(IntArray &arr, int left, int rigth) {

}

IntArray::iterator::iterator(int *pointer, int index) : i_pointer{ pointer }, i_index{ index }
{

}
