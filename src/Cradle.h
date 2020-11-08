#ifndef CRADLE
#define CRADLE

#include <iostream>
#include <string>

char look = '\0';

const char TAB = '\t';

void GetChar();

void Error(const std::string& s);

void Abort(const std::string& s);

void Expected(const std::string& s);

void Match(const char c);

char GetName();

char GetNum();

void Emit(const std::string& s);

void EmitLine(const std::string& s);

void Init();

#endif
