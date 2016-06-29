#include "Exception.hpp"

using namespace std;

Exception::Exception()
{

}

Exception::Exception(const string & strWhat)
{
	this->strWhat = strWhat;
}

string Exception::What()
{
	return strWhat;
}