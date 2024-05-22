// Name: Seyed Younes Shaterzadeh
// Student ID: 187484233
// Date: 2024-05-21
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_EMPLOYEE_H_
#define SENECA_EMPLOYEE_H_

#define DATAFILE "employees.csv"
namespace seneca
{
   struct Employee
   {
      char *m_name;
      int m_empNo;
      double m_salary;
   };
   void sort();
   bool load(Employee &emp);

   bool load();

   void display(const Employee &emp);

   void display();

   void deallocateMemory();

} // namespace seneca

#endif // SENECA_EMPLOYEE_H_