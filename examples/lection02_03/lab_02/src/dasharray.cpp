#include "dasharray.h"

DashArray::DashArray() : _size(0), _array{nullptr}
{
    std::cout << "Default constructor" << std::endl;
}

DashArray::DashArray(const size_t &n, unsigned char t)
{
    std::cout << "Fill constructor" << std::endl;
    _array = new unsigned char[n];
    for (size_t i = 0; i < n; ++i)
        _array[i] = t;
    _size = n;
}

DashArray::DashArray(const std::initializer_list<unsigned char> &t)
{
    std::cout << "Initializer list constructor" << std::endl;
    _array = new unsigned char[t.size()];
    size_t i{0};
    for (auto c : t)
        _array[i++] = c;
    _size = t.size();
}

DashArray::DashArray(const std::string &t)
{
    std::cout << "Copy string constructor" << std::endl;
    _array = new unsigned char[t.size()];
    _size  = t.size();

    for(size_t i{0};i<_size;++i) _array[i] = t[i];
}

DashArray::DashArray(const DashArray &other)
{
    std::cout << "Copy constructor" << std::endl;
    _size  = other._size;
    _array = new unsigned char[_size];

    for(size_t i{0};i<_size;++i) _array[i] = other._array[i];
}

DashArray::DashArray(DashArray &&other) noexcept
{
    std::cout << "Move constructor" << std::endl;
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}

DashArray DashArray::add(const DashArray &other)
{
    return DashArray(this->_size+other._size,'1');
}
DashArray DashArray::remove(const DashArray &other)
{

    if(_size<other._size) throw std::logic_error("dash array can't be negative");

    _size -= other._size;

    return *this;
}

bool DashArray::equals(const DashArray &other) const
{
    return _size==other._size;
}

std::ostream &DashArray::print(std::ostream &os)
{
    for (size_t i = 0; i < _size; ++i)
        os << _array[i];
    return os;
}

DashArray::~DashArray() noexcept
{
    if (_size > 0)
    {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}