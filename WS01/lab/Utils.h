#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H

namespace seneca
{
    // Function Prototypes
    void flushkeys();
    bool ValidYesResponse(char ch);
    bool yes();
    void readCstr(char cstr[], int len);
    int readInt(int min, int max);
}
#endif
