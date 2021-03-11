#include <cassert>
#include <iostream>
#include "../includes/IntArray.h"

IntArray::IntArray(int size) : m_size { size }{
    assert(size >=0 );
    m_array = new int [m_size];
}

IntArray::~IntArray() {
    m_size = 0;
    delete [] m_array;
    m_array = nullptr;
    begin();
    end();
}


int IntArray::size() const {
    return m_size;
}

int &IntArray::operator [](int index) {
    assert(index >=0 and index <= m_size-1);
    return m_array[index];
}

const int &IntArray::operator[](int index) const {
    assert(index >=0 and index <= m_size-1);
    return m_array[index];
}

void IntArray::erase() {
    delete [] m_array;
    m_array = nullptr;
    m_size = 0;
    begin();
    end();
}

void IntArray::reallocate(int new_size) {   // reallocate resizes the array.  Any existing elements will be destroyed.
    erase();
    if (new_size <= 0){
        return;
    }
    m_array = new int [new_size];
    m_size = new_size;
    begin();
    end();
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
        int * data { new int [new_size]{} };
        if (m_size > 0){
            int elementsToCopy { m_size > new_size ? new_size : m_size};
            for (int i {0}; i < elementsToCopy; ++i){
                data[i] = m_array[i];
            }
        }
        delete [] m_array;
        m_array = data;
        m_size = new_size;
        begin();
        end();
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
    begin();
    end();
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
    begin();
    end();
}

std::ostream &operator<<(std::ostream &out, const IntArray &array) {
    out << "[SIZE : " << array.size() << "]  [";
    for (int i { 0 }; i < array.m_size-1; i++){
        out << array[i] << ", ";
    }
    out << array[array.m_size-1] << "]" << std::endl <<std::endl;
    return out;
}


//
//
//      Iterator methods
//
//


IntArray::iterator::iterator(pointer ptr, value_type index) : i_pointer{ ptr }, i_index{ index }
{

}

int &IntArray::iterator::operator[](int index) {
    return *(i_pointer + index);
}

int *IntArray::iterator::operator->() {
    return i_pointer;
}

int &IntArray::iterator::operator*() const {
    return *i_pointer;
}

int &IntArray::iterator::operator*() {
    return *i_pointer;
}

bool operator==(const IntArray::iterator &it_1, const IntArray::iterator &it_2) {
    return it_1.i_pointer == it_2.i_pointer;
}

bool operator!=(const IntArray::iterator &it_1, const IntArray::iterator &it_2) {
    return !(it_1 == it_2);
}

IntArray::iterator &IntArray::iterator::operator++() {
    ++i_index;
    ++i_pointer;
    return *this;
}

IntArray::iterator IntArray::iterator::operator++ (int) {
    auto clone { *this };
    ++(*this);
    return clone;
}

IntArray::iterator &IntArray::iterator::operator--() {
    --i_index;
    --i_pointer;
    return *this;
}

IntArray::iterator IntArray::iterator::operator--(int) {
    auto clone { *this };
    --(*this);
    return clone;
}

IntArray::iterator IntArray::iterator::operator+(int value) {
    return {i_pointer + value, i_index + value};
}

IntArray::iterator IntArray::iterator::operator-(int value) {
    return {i_pointer - value, i_index - value};
}

IntArray::iterator IntArray::iterator::operator-=(int value) {
    i_index -= value;
    i_pointer -= value;
    return *this;
}

IntArray::iterator IntArray::iterator::operator+=(int value) {
    i_index += value;
    i_pointer += value;
    return *this;
}

int operator-(const IntArray::iterator &it_1, const IntArray::iterator &it_2) {
    return (it_1.i_index - it_2.i_index);
}

bool operator>(const IntArray::iterator &it_1, const IntArray::iterator &it_2) {
    return (it_1 - it_2 > 0);
}

bool operator>=(const IntArray::iterator &it_1, const IntArray::iterator &it_2) {
    return !(it_1 < it_2);
}

bool operator<(const IntArray::iterator &it_1, const IntArray::iterator &it_2) {
    return (it_2 > it_1);
}

bool operator<=(const IntArray::iterator &it_1, const IntArray::iterator &it_2) {
    return !(it_1 > it_2);
}

IntArray::IntArray(std::initializer_list<int> initList)
        : IntArray::IntArray(static_cast<int>(initList.size()))
{
    auto counter { 0 };
    for (auto element : initList){
        m_array[counter] = element;
        ++counter;
    }
}

IntArray &IntArray::operator=(std::initializer_list<int> initList) {
    int size { static_cast<int>(initList.size()) };
    if (size != m_size){
        delete [] m_array;
        m_size = size;
        m_array = new int [m_size] {};
    }

    int counter { 0 };
    for (auto element: initList){
        m_array[counter] = element;
        ++counter;
    }
    return *this;
}
