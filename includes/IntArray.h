#ifndef INTARRAY_CONTAINER_CLASS_INTARRAY_H
#define INTARRAY_CONTAINER_CLASS_INTARRAY_H


#include <iterator>

class IntArray {
private:
    int * m_array { nullptr };
    int m_size { };

private:
    class iterator{
    public:
        iterator(int *pointer, int index);
        int& operator [](int index);
        int &operator *();
        int &operator *() const;
        int *operator ->();
        iterator &operator ++();
        iterator operator ++(int);
        iterator &operator --();
        iterator operator --(int);
        iterator operator + (int value);
        iterator operator - (int value);
        iterator operator -= (int value);
        iterator operator += (int value);
        friend bool operator >(const iterator &it_1, const iterator &it_2);
        friend bool operator >=(const iterator &it_1, const iterator &it_2);
        friend bool operator <(const iterator &it_1, const iterator &it_2);
        friend bool operator <=(const iterator &it_1, const iterator &it_2);
        friend int operator -(const iterator &it_1, const iterator &it_2);
        friend bool operator == (const iterator &it_1, const iterator &it_2);
        friend bool operator != (const iterator &it_1, const iterator &it_2);

    private:
        int * i_pointer;
        int i_index;
    public:
        using difference_type = int;
        using value_type = int;
        using pointer = int*;
        using reference = int&;
        using iterator_category = std::random_access_iterator_tag;
    };

public:             // for defined friend function operators overloading for nested 'iterator' class
    friend bool operator == (const iterator &it_1, const iterator &it_2);
    friend bool operator != (const iterator &it_1, const iterator &it_2);
    friend int operator -(const iterator &it_1, const iterator &it_2);
    friend bool operator >(const iterator &it_1, const iterator &it_2);
    friend bool operator >=(const iterator &it_1, const iterator &it_2);
    friend bool operator <(const iterator &it_1, const iterator &it_2);
    friend bool operator <=(const iterator &it_1, const iterator &it_2);

public:
    IntArray() = default;
    explicit IntArray(int size);
    ~IntArray();
    int size() const;
    int &operator [] (int index);
    const int &operator [] (int index) const;
    iterator begin() { return {m_array, 0}; };
    iterator end() { return {m_array + m_size, m_size}; };
    friend std::ostream &operator <<(std::ostream &out, const IntArray &array);
    void erase();
    void reallocate(int size);  // reallocate resizes the array.  Any existing elements will be destroyed.
    void resize(int new_size);  // Any existing elements will be maintained.
    void insertBefore(int value, int index);
    void remove(int index);
};


#endif //INTARRAY_CONTAINER_CLASS_INTARRAY_H
