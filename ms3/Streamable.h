#ifndef STREAMABLE_H
#define STREAMABLE_H

#include <iostream>

class Streamable {
public:
    virtual std::ostream& write(std::ostream& os) const = 0;
    virtual std::istream& read(std::istream& is) = 0;
    virtual bool conIO(std::ios& io) const = 0;
    virtual operator bool() const = 0;
    virtual ~Streamable() = default;
};

std::ostream& operator<<(std::ostream& os, const Streamable& obj);
std::istream& operator>>(std::istream& is, Streamable& obj);

#endif // STREAMABLE_H
