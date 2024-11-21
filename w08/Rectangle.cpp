#include "Rectangle.h"
#include <cstring>
#include <iostream>

namespace seneca {
    Rectangle::Rectangle() : LblShape(), m_width(0), m_height(0) {}

    Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label), m_width(width), m_height(height) {
        if (height < 3 || width < (int(strlen(label)) + 2)) {
            m_width = 0;
            m_height = 0;
        }
    }

    void Rectangle::draw(std::ostream& os) const {
        if (m_width > 0 && m_height > 0) {
            os << '+';
            for (int i = 0; i < m_width - 2; i++) {
                os << '-';
            }
            os << "+\n";

            os << '|';
            os.width(m_width - 2);
            os << std::left << label() << "|\n";

            for (int i = 0; i < m_height - 3; i++) {
                os << '|';
                os.width(m_width - 2);
                os << ' ' << "|\n";
            }

            os << '+';
            for (int i = 0; i < m_width - 2; i++) {
                os << '-';
            }
           
            os << "+";
        }
    }

    void Rectangle::getSpecs(std::istream& is) {
        LblShape::getSpecs(is);
        is >> m_width;
        is.ignore();
        is >> m_height;
        is.ignore();
        if (m_height < 3 || m_width < (int(strlen(label())) + 2)) {
            m_width = 0;
            m_height = 0;
        }
    }
}

