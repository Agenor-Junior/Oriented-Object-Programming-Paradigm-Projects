#ifndef LBLSHAPE_H
#define LBLSHAPE_H
#include "Shape.h"

namespace seneca {
    class LblShape : public Shape {
        char* m_label{ nullptr };
    protected:
        const char* label() const;
    public:
        LblShape();
        LblShape(const char* label);
        ~LblShape();
        void getSpecs(std::istream& is) override;
        
        LblShape(const LblShape&) = delete;
        LblShape& operator=(const LblShape&) = delete;
    };
}

#endif
