// Name: Seyed Younes Shaterzadeh
// Student ID: 187484233
// Date: 2024-05-21
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <cstring>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace seneca
{

   int noOfEmployees;
   Employee *employees;

   void sort()
   {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--)
      {
         for (j = 0; j < i; j++)
         {
            if (employees[j].m_empNo > employees[j + 1].m_empNo)
            {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   bool load(Employee &emp)
   {
      int empNo;
      double salary;
      char name[128];
      bool ok = false;

      if (read(empNo) && read(salary) && read(name))
      {
         emp.m_empNo = empNo;
         emp.m_salary = salary;
         emp.m_name = new char[strlen(name) + 1];
         strcpy(emp.m_name, name);
         ok = true;
      }

      return ok;
   }

   bool load()
   {
      bool ok = false;

      if (openFile(DATAFILE))
      {
         noOfEmployees = noOfRecords();
         employees = new Employee[noOfEmployees];

         int i = 0;
         for (; i < noOfEmployees; i++)
         {
            if (!load(employees[i]))
            {
               break;
            }
         }

         if (i != noOfEmployees)
         {
            cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
         }
         else
         {
            ok = true;
         }

         closeFile();
      }
      else
      {
         cout << "Could not open data file: " << DATAFILE << endl;
      }

      return ok;
   }

   void display(const Employee &emp)
   {
      cout << emp.m_empNo << ": " << emp.m_name << ", " << emp.m_salary << endl;
   }

   void display()
   {
      cout << "Employee Salary report, sorted by employee number" << endl;
      cout << "no- Empno, Name, Salary" << endl;
      cout << "------------------------------------------------" << endl;

      sort();

      for (int i = 0; i < noOfEmployees; i++)
      {
         cout << i + 1 << "- ";
         display(employees[i]);
      }
   }

   void deallocateMemory()
   {
      for (int i = 0; i < noOfEmployees; i++)
      {
         delete[] employees[i].m_name;
      }
      delete[] employees;
   }

}