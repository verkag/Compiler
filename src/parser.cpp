
#include "cradle.h"
#include "parser.h"
#include <string>
#include <cstring>

void Term()
{
	EmitLine((std::string)"MOVE # " + GetNum() + " D0");
}

void Add()
{
	Match('+');
	Term();
	EmitLine("Add D1, D0");
}

void Subtract()
{
	Match('-');
	Term();
	EmitLine("Add D1, D0");
}

void Expression()
{
	Term();
	while (std::strchr("+-", look))
	{
		EmitLine("pushl %eax");
		switch (look)
		{
		case '+':
			Add();
			break;
		case '-':
			Subtract();
			break;
		default:
			Expected("Addop");
		}

	}
}

