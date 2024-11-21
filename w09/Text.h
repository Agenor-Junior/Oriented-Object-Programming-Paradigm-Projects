/*
* Student: Agenor Dionizio da SIlva Junior
* ID: 138121223
I have done all the coding by myself and only copied the code that my professor provided
to complete my workshops and assignments.
*/

#ifndef SENECA_TEXT_H__
#define SENECA_TEXT_H__
namespace seneca {
   class Text {
      char* m_filename; 
      char* m_content; 
      int getFileLength()const;
   protected:
      const char& operator[](unsigned int index)const;
   public:
      Text(const char* filename=nullptr);
      
      // rule of three 
      Text(const Text&);
      Text& operator=(const Text&);
      ~Text();

      void read();
      virtual void write(std::ostream& os)const;
   };
   
   std::ostream& operator<<(std::ostream& os, const Text& RO);
}
#endif // !SENECA_PERSON_H__

