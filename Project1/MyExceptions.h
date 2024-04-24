#include <iostream>
#include <exception>
using namespace std;

class MyException :public exception
{
	virtual const char* what() const noexcept
	{
		return "Wystapil blad\n";
	}
};

class FileException :public MyException
{
	virtual const char* what() const noexcept override
	{
		return "Blad otwarcia pliku\n";
	}
};

class WrongIDException :public MyException
{
	virtual const char* what() const noexcept override
	{
		return "Blad - zle ID";
	}
};