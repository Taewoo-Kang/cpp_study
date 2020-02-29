#ifndef __ARRAY_TEMPLATE_H_
#define __ARRAY_TEMPLATE_H_

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class BoundaryCheckArray
{
private:
    T * arr;
    int arrlen;

    BoundaryCheckArray(const BoundaryCheckArray& arr) { }
    BoundaryCheckArray& operator= (const BoundaryCheckArray& arr) { }

public:
    BoundaryCheckArray(int len);
    T& operator[] (int idx);
    T operator[] (int idx) const;
    int GetArrLen() const;
    ~BoundaryCheckArray();
};

template <typename T>
BoundaryCheckArray<T>::BoundaryCheckArray(int len) : arrlen(len)
{
    arr = new T[len];
}

template <typename T>
T& BoundaryCheckArray<T>::operator[] (int idx)
{
    if(idx<0 || idx>=arrlen)
    {
        cout << "Array index out if bound exception" << endl;
        exit(1);
    }
    return arr[idx];
}

template <typename T>
T BoundaryCheckArray<T>::operator[] (int idx) const
{
    if(idx<0 || idx>=arrlen)
    {
        cout << "Array index out if bound exception" << endl;
        exit(1);
    }
    return arr[idx];
}
template <typename T>
int BoundaryCheckArray<T>::GetArrLen() const
{
    return arrlen;
}

template < typename T>
BoundaryCheckArray<T>::~BoundaryCheckArray()
{
    delete []arr;
}

#endif