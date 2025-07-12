#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array
{
    private:
        T               *_data;
        unsigned int    _size;

    public:
        Array() : _data(NULL), _size(0)
        {
        }

        Array(unsigned int n) : _data(NULL), _size(n)
        {
            if (n > 0)
                _data = new T[n]();
        }

        Array(const Array& other) : _data(NULL), _size(other._size)
        {
            if (_size > 0)
            {
                _data = new T[_size]();
                for (unsigned int i = 0; i < _size; ++i)
                    _data[i] = other._data[i];
            }
        }

        Array   &operator=(const Array& other)
        {
            if (this != &other)
            {
                delete[] _data;
                _size = other._size;
                if (_size > 0)
                {
                    _data = new T[_size]();
                    for (unsigned int i = 0; i < _size; ++i)
                        _data[i] = other._data[i];
                }
                else
                    _data = NULL;
            }
            return (*this);
        }

        ~Array()
        {
            delete[] _data;
        }

        T   &operator[](unsigned int idx)
        {
            if (idx >= _size)
                throw std::out_of_range("Index out of bounds");
                
            return (_data[idx]);
        }

        const T &operator[](unsigned int idx) const
        {
            if (idx >= _size)
                throw std::out_of_range("Index out of bounds");

            return (_data[idx]);
        }

        unsigned int    size() const
        {
            return (_size);
        }
};

#endif
