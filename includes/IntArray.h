//
// Created by lukas on 09.03.2021.
//

#ifndef INTARRAY_CONTAINER_CLASS_INTARRAY_H
#define INTARRAY_CONTAINER_CLASS_INTARRAY_H


#include <iterator>

class IntArray {
private:
    int * m_array { nullptr };
    int m_size { };
    class iterator : public std::iterator<std::output_iterator_tag, int>{
    public:
        iterator(int *pointer);
        int &operator *() const;;
        int *operator ->();;
        iterator &operator ++();
        iterator operator ++(int);
        friend bool operator == (const iterator &it_1, const iterator &it_2);
        friend bool operator != (const iterator &it_1, const iterator &it_2);

    private:
        int * i_pointer;
    };
public:             // for defined friend function operators overloading for nested 'iterator' class
    friend bool operator == (const iterator &it_1, const iterator &it_2);
    friend bool operator != (const iterator &it_1, const iterator &it_2);

public:
    IntArray() = default;
    explicit IntArray(int size);
    ~IntArray();
    int &operator [] (int index);
    iterator begin() { return iterator(m_array); };
    iterator end() { return iterator(m_array + m_size); };
    void erase();
    void reallocate(int size);  // reallocate resizes the array.  Any existing elements will be destroyed.
    void resize(int new_size);
    void insertBefore(int value, int index);
    void remove(int index);
    void print();
//    friend void quickSort(int *, int, int);
};


#endif //INTARRAY_CONTAINER_CLASS_INTARRAY_H
