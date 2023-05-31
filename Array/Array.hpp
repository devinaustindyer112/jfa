#ifndef ARRAY_H
#define ARRAY_H

template <typename T> class Array {
private:
    T* elements;
    int size;

    public:
        Array();
        ~Array();
        T operator[](int index);

};

#endif // ARRAY_H