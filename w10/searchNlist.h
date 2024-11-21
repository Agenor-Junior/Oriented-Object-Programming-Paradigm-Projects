/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 10
// Version 1.0
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Agenor Junior    2024-07-29      Workshop10
/////////////////////////////////////////////////////////////////
***********************************************************************/

/*
==== Template Type Requirements ====

ListArrayElements template function
This function is designed to receive different types of arrays, titles, and the number of arrays, and display this
data on the console.
By using <typename T>, I can pass various types of arrays.
During compilation, the template function identifies the type of array received.
The "<<" operator function of the abstract base class ReadWrite is called first inside the function, because the Car,
Employee, and Student classes inherit from the ReadWrite class.
Next, it is determined which object is the real one, and finally the display() function of the corresponding object
is called.

Search template function
Collection is a template class. It can receive the Car, Student, or Employee classes as types.
Thus, the collection and array use the same type name.
The data is added using the template member function defined in the collection template class.
In addition, the value of the key is of a different type for each class, so a different type name is used.
Then, just like the first template function, the types are determined during the compilation phase.
Then, the "==" operator is called for each class to check if there is a match.
If there is a match, the "add" template function in the Collection class is called to add the data.
*/


#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_

#include <iostream>
#include "Collection.h"
#include "Car.h"
#include "Student.h"
#include "Employee.h"

using namespace std;

namespace seneca
{
    // Using templates, receive different types of arrays
    template <typename T>
    void listArrayElements(const char* _title, const T* _arr, int _num) {
        cout << _title << endl;

        for (int i = 0; i < _num; i++) {
            cout << (i + 1) << ": ";
            // Call "<<" operator from the ReadWrite class that is abstract base class
            // and then compiler determines the actual object and Call the corresponding display()
            cout << _arr[i] << endl;
        }
    }

    // Receive the same typename in Collection and array
    // because to add the searched array to Collection
    // and use another typename to receive different key value
    template <typename T1, typename T2>
    bool search(Collection<T1>& _obj, const T1* _arr, int _num, T2 _key) {
        bool result = false;

        for (int i = 0; i < _num; i++) {
            if (_arr[i] == _key) { // Call "==" operator corresponding to each type
                _obj.add(_arr[i]);   // Call the template function "add" in Collection template class
                result = true;
            }
        }
        return result;
    }
}
#endif // !SDDS_SEARCHNLIST_H_