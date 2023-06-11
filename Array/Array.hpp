#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T> class Array {
private:
    T* elements;
    int size;

    public:
        Array();
        ~Array();
        int length();
        void push(T element);
        T pop();
        T operator[](int index);

};

#endif // ARRAY_HPP