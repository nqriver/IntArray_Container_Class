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
        iterator(int *pointer, int index);
        int &operator *() const { return *i_pointer; };
        int *operator ->() { return i_pointer; };
        iterator &operator ++() {++i_pointer; ++i_index; return *this;};
        iterator operator ++(int) {auto tempIter = *this; ++(*this); return tempIter; };
        friend bool operator == (const iterator &it_1, const iterator &it_2) { return it_1.i_pointer == it_2.i_pointer; }
        friend bool operator != (const iterator &it_1, const iterator &it_2) { return !(it_1 == it_2); };

    private:
        int * i_pointer;
        int i_index {0};
    };
public:
    IntArray() = default;
    explicit IntArray(int size);
    ~IntArray();
    int &operator [] (int index);
    iterator begin() { return iterator(m_array, 0); };
    iterator end() { return iterator(m_array + m_size, m_size); };
    void erase();
    void reallocate(int size);  // reallocate resizes the array.  Any existing elements will be destroyed.
    void resize(int new_size);
    void insertBefore(int value, int index);
    void remove(int index);
    void print();
    friend void quickSort(int *, int, int);
};


#endif //INTARRAY_CONTAINER_CLASS_INTARRAY_H
