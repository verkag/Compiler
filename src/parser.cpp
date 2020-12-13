#include <stdlib.h>
#include <cctype>
#include "cradle.h"
#include "parser.h"

char look = '\0';
const char TAB = '\t';

void GetChar()
{
	look = std::getchar();
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

	if (look != x) Expected(border + x + border);
	else
	{
		GetChar();
		SkipWhite();
	}
}

std::string GetName()
{
	std::string token = ""; 								
	if (!IsAlNum(look))	Expected("Name");								
	while (IsAlNum(look))
	{
		token = token + static_cast<char>(std::toupper(look));
		GetChar();
	}
	return token;
	SkipWhite();
}

std::string GetNum()
{
	std::string value = "";
	if (!std::isdigit(look)) Expected("Integer");
	while (std::isdigit(look))
	{
		value += look;
		GetChar();
	}
	return value;
	SkipWhite();
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
	SkipWhite();
}
