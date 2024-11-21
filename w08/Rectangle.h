#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "LblShape.h"

namespace seneca {
    class Rectangle : public LblShape {
        int m_width{ 0 };
        int m_height{ 0 };
    public:
        Rectangle();
        Rectangle(const char* label, int width, int height);
        void draw(std::ostream& os) const override;
        void getSpecs(std::istream& is) override;
    };
}

#endif
