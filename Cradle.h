#pragma once

#include <iostream>
#include <vector>
#include <string>

const char TAB = '\t';
char look;

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

char Match(const char x)
{
	if (look == x) GetChar();
	else Expected("  " + (std::string&)x + " ");
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

void EmitLn(const std::string& s)
{
	Emit(s);
	std::cout << std::endl;
}

void Init()
{
	GetChar();
}
