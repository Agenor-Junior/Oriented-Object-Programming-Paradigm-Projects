/***********************************************************************
// OOP244 
// Version
// Date:
// Author:
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Agenor Junior    2024-05-08      MS5
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_UTILS_H__
#define SENECA_UTILS_H__
#include <iostream>
namespace seneca {
    class Utils {
    public:
        size_t getInt(size_t, size_t);
        int getMemberNum();
        char getType(unsigned int);
    };
    extern Utils ut;
}
#endif // SENECA_UTILS_H__


