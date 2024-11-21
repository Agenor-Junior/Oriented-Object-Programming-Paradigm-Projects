// Final Project Milestone 4
// BOOK Module
// File	Book.cpp
// Version 4.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "Book.h"
#include "Lib.h"

namespace seneca {

    Book::Book() : m_author(nullptr) {}

    Book::Book(const Book& other) : Publication(other), m_author(nullptr) {
        setAuthor(other.m_author);
    }

    Book& Book::operator=(const Book& other) {
        if (this != &other) {
            Publication::operator=(other);
            setAuthor(other.m_author);
        }
        return *this;
    }

    Book::~Book() {
        delete[] m_author;
    }

    char Book::type() const {
        return 'B';
    }

    std::ostream& Book::write(std::ostream& os) const {
        Publication::write(os);
        if (conIO(os)) {
            os << " ";
            if (strlen(m_author) > SENECA_AUTHOR_WIDTH) {
                os << std::setw(SENECA_AUTHOR_WIDTH) << std::left << std::string(m_author).substr(0, SENECA_AUTHOR_WIDTH);
            }
            else {
                os << std::setw(SENECA_AUTHOR_WIDTH) << std::left << m_author;
            }
            os << " |";
        }
        else {
            os << "\t" << m_author;
        }
        return os;
    }

    std::istream& Book::read(std::istream& is) {
        char author[256];
        Publication::read(is);

        delete[] m_author;
        m_author = nullptr;

        if (conIO(is)) {
            is.ignore();
            std::cout << "Author: ";
            is.getline(author, 256);
        }
        else {
            is.get();
            is.getline(author, 256, '\n');
            is.putback('\n');
        }

        if (is) {
            setAuthor(author);
        }

        return is;
    }

    void Book::set(int member_id) {
        Publication::set(member_id);
        resetDate();
    }

    Book::operator bool() const {
        return m_author && m_author[0] && Publication::operator bool();
    }

    void Book::setAuthor(const char* author) {
        delete[] m_author;
        if (author && author[0]) {
            m_author = new char[strlen(author) + 1];
            strcpy(m_author, author);
        }
        else {
            m_author = nullptr;
        }
    }

}