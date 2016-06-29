#ifndef HELPERS_HPP_INCLUDED
#define HELPERS_HPP_INCLUDED

#include <sstream>

namespace Helpers
{

	template <typename T>
	std::string		ToString(const T & t)
	{
		std::stringstream str;
		std::string strRet;

		str << t;
		str >> strRet;

		return strRet;
	}

};	//	namespace Helpers

#endif
