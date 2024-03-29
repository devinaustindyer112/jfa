#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
    T *elements;
    int size;

public:
    Array();
    Array(const Array<T> &other);
    ~Array();
    int length();
    void push(T element);
    T pop();
    T get(int index);
    bool operator==(const Array<T> &other) const;
};

#endif // ARRAY_HPP