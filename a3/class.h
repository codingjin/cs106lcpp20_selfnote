
#pragma once

#include <cstddef>

template <typename T>
class Vector {
public:
    using iterator = T*;

    Vector();
    Vector(size_t size);
    ~Vector();

    void setCapacity(size_t capacity);
    size_t getSize() const;
    size_t getCapacity() const;

    void push_back(const T& v);

    T& at(const size_t i);
    T& operator[](const size_t i);

private:
    size_t _size;
    size_t _capacity;
    iterator _data;

    void resize();
};

#include "class.cpp"