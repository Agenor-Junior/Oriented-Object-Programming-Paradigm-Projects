// Final Project Milestone 4
// Streamable Module
// File	Streamable.cpp
// Version 1.0
// Author	Agenor Junior
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////


#include "Streamable.h"
namespace seneca {

    std::ostream& operator<<(std::ostream& os, const Streamable& obj) {
        if (obj) {
            obj.write(os);
        }
        return os;
    }

    std::istream& operator>>(std::istream& is, Streamable& obj) {
        obj.read(is);
        return is;
    }

    Streamable::~Streamable() {}
}