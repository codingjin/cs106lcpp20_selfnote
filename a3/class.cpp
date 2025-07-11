#include <iostream>

template <typename T>
Vector<T>::Vector() : _size{0}, _capacity{4}
{
    _data = new T[_capacity];
}

template <typename T>
Vector<T>::Vector(size_t size) : _size{0}
{
    if (size > 0) {
        _capacity = size;
    } else {
        _capacity = 4;
    }
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] _data;
}

template <typename T>
void Vector<T>::setCapacity(size_t capacity)
{
    if (capacity > _capacity) {
        T* newdata = new T[capacity];
        for (size_t i = 0; i < _size; ++i) {
            newdata[i] = _data[i];
        }
        delete[] _data;
        _data = newdata;
    }
}

template <typename T>
size_t Vector<T>::getSize() const
{
    return _size;
}

template <typename T>
size_t Vector<T>::getCapacity() const
{
    return _capacity;
}

template <typename T>
void Vector<T>::resize()
{
    size_t capacity = _capacity << 1;
    T* newdata = new T[capacity];
    for (size_t i = 0; i < _size; ++i) {
        newdata[i] = _data[i];
    }
    delete[] _data;
    _data = newdata;
}

template <typename T>
void Vector<T>::push_back(const T& v)
{
    if (_size == _capacity) {
        resize();
    }
    _data[_size] = v;
    ++_size;
}

template <typename T>
T& Vector<T>::at(const size_t i)
{
    if (i > _size) {
        std::cerr << "out-of-index" << std::endl;
    }
    return _data[i];
}

template <typename T>
T& Vector<T>::operator[](const size_t i)
{
    if (i > _size) {
        std::cerr << "out-of-index" << std::endl;
    }
    return _data[i];
}