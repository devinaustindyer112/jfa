#include "Array.hpp"

template <typename T> Array<T>::Array() {
    this->elements = new T[0];
    this->size = 0;
}

template <typename T> Array<T>::~Array() {
    delete[] this->elements;
}