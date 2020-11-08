#include <stdlib.h>
#include <cctype>
#include "cradle.h"

void GetChar()
{
	std::cin >> look;
}

void Error(const std::string& s)
{
	std::cout << std::endl << "Error: " << s << "." << std::endl;
}

void Abort(const std::string& s)
{
	Error(s);
	exit(1);
}

void Expected(const std::string& s)
{
	Abort(s + " Expected");
}

void Match(const char x)
{
	static std::string border = "\'";

	if (look == x)
		GetChar();
	else
		Expected(border + x + border);
}

char GetName()
{
	if (!(std::isalpha(look))) Expected("Name");
	char name = look;
	GetChar();

	return name;
}

char GetNum()
{
	if (!(std::isdigit(look))) Expected("Integer");
	char integer = look;
	GetChar();

	return integer;
}

void Emit(const std::string& s)
{
	std::cout << TAB << s;
}

void EmitLine(const std::string& s)
{
	Emit(s);
	std::cout << std::endl;
}

void Init()
{
	GetChar();
}
