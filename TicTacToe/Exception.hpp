#ifndef EXCEPTION_HPP_INCLUDED
#define EXCEPTION_HPP_INCLUDED

#include <string>

class Exception
{
public:
					Exception();

					Exception(const std::string & strWhat);

	std::string		What();

private:
	std::string		strWhat;
};

#endif
