/*
* Student: Agenor Dionizio da Silva Junior
* ID: 138121223
I have done all the coding by myself and only copied the code that my professor provided
to complete my workshops and assignments.
*/

#ifndef SENECA_HTMLTEXT_H__
#define SENECA_HTMLTEXT_H__
#include "Text.h"
namespace seneca {
   class HtmlText :  public Text {
      char* m_title;
   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);


      // rule of three 
      HtmlText(const HtmlText&);
      HtmlText& operator=(const HtmlText&);
      ~HtmlText();

      virtual void write(std::ostream& os)const;


   };
}
#endif // !SENECA_HTMLTEXT_H__
