// Final Project Milestone 4
// Streamable interface
// File	Streamable.h
// Version 1.0
// Author	Agenor Junior
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////

#ifndef SENECA_STREAMABLE_H
#define SENECA_STREAMABLE_H
#include <iostream>	
namespace seneca {
	class Streamable {
	public:
		
		virtual std::ostream& write(std::ostream& os) const = 0;

		
		virtual std::istream& read(std::istream& is) = 0;

		
		virtual bool conIO(std::ios& io) const = 0;
		
		virtual operator bool() const = 0;
		
		virtual ~Streamable() = 0;
	};
	
	std::ostream& operator<<(std::ostream& os, const Streamable& s);
	std::istream& operator>>(std::istream& is, Streamable& s);
}
#endif