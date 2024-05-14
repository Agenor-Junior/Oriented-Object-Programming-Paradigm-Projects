#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef SENECA_FILE_H
#define SENECA_FILE_H

#include "ShoppingRec.h"

namespace seneca
{
    // Functions
    bool openFileForRead();
    bool openFileForOverwrite();
    void closeFile();
    bool freadShoppingRec(ShoppingRec *rec);
    void fwriteShoppintRec(const ShoppingRec *rec);
}
#endif