#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

struct outOfRange
{
	outOfRange(const std::string& error_message) {}
};

struct RangeError : outOfRange
{
    int index;
    RangeError(int i) : outOfRange("Range Error"), index(i) { }
};

template<class T> struct Vector : public std::vector<T> {
    typedef typename std::vector<T>::size_type size_type;

    Vector() { }
    Vector(size_type n) :std::vector<T>(n) {}
    Vector(size_type n, const T& v) :std::vector<T>(n, v) {}

    T& operator[](unsigned int i) // rather than return at(i);
    {
        if (i < 0 || this->size() <= i) throw RangeError(i);
        return std::vector<T>::operator[](i);
    }

    const T& operator[](unsigned int i) const
    {
        if (i < 0 || this->size() <= i) throw RangeError(i);
        return std::vector<T>::operator[](i);
    }
};

#define vector Vector

int main()
try
{
    vector<int> v(10);
    v[20] = 5; // trying to access invalid index
}
catch (const std::exception& e)
{
    std::cerr << "error: " << e.what() << '\n';
    return 1;
}
catch(...)
{
    std::cerr << "Yeah nah: unknown exception hey!\n";
    return 2;
}