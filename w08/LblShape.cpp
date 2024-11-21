#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include <cstring>
#include <iostream>
#include <string>

namespace seneca {
    LblShape::LblShape() : m_label(nullptr) {}

    LblShape::LblShape(const char* label) {
        m_label = new char[strlen(label) + 1];
        strcpy(m_label, label);
    }

    LblShape::~LblShape() {
        delete[] m_label;
    }

    const char* LblShape::label() const {
        return m_label;
    }

    void LblShape::getSpecs(std::istream& is) {
        std::string temp;
        std::getline(is, temp, ',');
        delete[] m_label;
        m_label = new char[temp.length() + 1];
        strcpy(m_label, temp.c_str());
    }
}


