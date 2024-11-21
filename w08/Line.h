#ifndef LINE_H
#define LINE_H
#include "LblShape.h"

namespace seneca {
    class Line : public LblShape {
        int m_length{ 0 };
    public:
        Line();
        Line(const char* label, int length);
        void draw(std::ostream& os) const override;
        void getSpecs(std::istream& is) override;
    };
}

#endif
