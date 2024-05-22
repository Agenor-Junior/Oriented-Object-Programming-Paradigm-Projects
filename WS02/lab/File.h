// Name: Seyed Younes Shaterzadeh
// Student ID: 187484233
// Date: 2024-05-21
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_FILE_H_
#define SENECA_FILE_H_
namespace seneca
{
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char name[]);
   bool read(int &empNo);
   bool read(double &salary);
}
#endif // !SENECA_FILE_H_