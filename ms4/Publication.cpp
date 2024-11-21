// Final Project Milestone 4
// Publication Module
// File	Publication.cpp
// Version 1.0
// Author	Agenor Junior
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Agenor Junior      2024.07.04           add Lib.h
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iomanip>
#include "Publication.h"
#include "Lib.h"
namespace seneca {

    Publication::Publication() : m_title(nullptr), m_membership(0), m_libRef(-1), m_date() {
        m_shelfId[0] = '\0';
    }

    Publication::~Publication() {
        delete[] m_title;
    }

    Publication::Publication(const Publication& other) : m_title(nullptr) {
        *this = other;
    }

    Publication& Publication::operator=(const Publication& other) {
        if (this != &other) {
            delete[] m_title;
            m_title = nullptr;
            if (other.m_title) {
                m_title = new char[strlen(other.m_title) + 1];
                strcpy(m_title, other.m_title);
            }
            strcpy(m_shelfId, other.m_shelfId);
            m_membership = other.m_membership;
            m_libRef = other.m_libRef;
            m_date = other.m_date;
        }
        return *this;
    }

    void Publication::set(int member_id) {
        m_membership = (member_id >= 10000 && member_id <= 99999) ? member_id : 0;
    }

    void Publication::setRef(int value) {
        m_libRef = value;
    }

    void Publication::resetDate() {
        m_date = Date();
    }

    char Publication::type() const {
        return 'P';
    }

    bool Publication::onLoan() const {
        return m_membership != 0;
    }

    Date Publication::checkoutDate() const {
        return m_date;
    }

    bool Publication::operator==(const char* title) const {
        return m_title && strstr(m_title, title);
    }

    Publication::operator const char* () const {
        return m_title;
    }

    int Publication::getRef() const {
        return m_libRef;
    }

    bool Publication::conIO(std::ios& io) const {
        return &io == &std::cin || &io == &std::cout;
    }

    std::ostream& Publication::write(std::ostream& os) const {
        if (conIO(os)) {
            os << "| " << std::setw(SENECA_SHELF_ID_LEN) << std::setfill(' ') << m_shelfId << " | ";

            std::string title_display;
            if (strlen(m_title) > SENECA_TITLE_WIDTH) {
                title_display = std::string(m_title, SENECA_TITLE_WIDTH);
            }
            else {
                title_display = m_title;
            }

            os << std::left << std::setw(SENECA_TITLE_WIDTH) << std::setfill('.') << title_display << " | ";

            if (m_membership)
                os << std::setw(5) << std::setfill(' ') << m_membership;
            else
                os << std::setw(5) << std::setfill(' ') << " N/A ";

            os << " | " << m_date << " |";
        }
        else {
            os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t"
                << m_membership << "\t" << m_date;
        }
        return os;

    }

    std::istream& Publication::read(std::istream& istr) {
        char title[256]{};
        char shelfId[SENECA_SHELF_ID_LEN + 1]{};
        int membership = 0;
        int libRef = -1;
        Date date;

        
        if (m_title) {
            delete[] m_title;
            m_title = nullptr;
        }
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        resetDate();

        if (conIO(istr)) {
            std::cout << "Shelf No: ";
            istr.getline(shelfId, SENECA_SHELF_ID_LEN + 1);
            if (strlen(shelfId) != SENECA_SHELF_ID_LEN) {
                istr.setstate(std::ios::failbit);
            }
            std::cout << "Title: ";
            istr.getline(title, 256);
            std::cout << "Date: ";
            istr >> date;
        }
        else {
            istr >> libRef;
            istr.get(); 
            istr.getline(shelfId, SENECA_SHELF_ID_LEN + 1, '\t');
            istr.getline(title, 256, '\t');
            istr >> membership;
            istr.get();  
            istr >> date;
        }

        if (!date) {
            istr.setstate(std::ios::failbit);
        }

        if (istr) {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
            strcpy(m_shelfId, shelfId);
            set(membership);
            m_date = date;
            m_libRef = libRef;
        }

        return istr;
    }

    Publication::operator bool() const {
        return m_title && m_title[0] && m_shelfId[0];
    }

}