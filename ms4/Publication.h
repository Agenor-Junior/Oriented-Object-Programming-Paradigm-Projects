// Final Project Milestone 4
// Publication Module
// File	Publication.h
// Version 1.0
// Author	Agenor Junior
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////


#ifndef SENECA_PUBLICATION_H
#define SENECA_PUBLICATION_H

#include <iostream>
#include "Date.h"
#include "Streamable.h"
#include "Lib.h"

namespace seneca {

    class Publication : public Streamable {
        char* m_title;
        char m_shelfId[SENECA_SHELF_ID_LEN + 1];
        int m_membership;
        int m_libRef;
        Date m_date;

    public:
        Publication();
        virtual ~Publication();
        Publication(const Publication& other);
        Publication& operator=(const Publication& other);
        
        virtual void set(int member_id);
        void setRef(int value);
        void resetDate();
       
        virtual char type() const;
        bool onLoan() const;
        Date checkoutDate() const;
        bool operator==(const char* title) const;
        operator const char* () const;
        int getRef() const;
        
        bool conIO(std::ios& io) const override;
        std::ostream& write(std::ostream& os) const override;
        std::istream& read(std::istream& istr) override;
        operator bool() const override;
    };

}

#endif // SENECA_PUBLICATION_H