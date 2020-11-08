#ifndef CRADLE
#define CRADLE

#include <iostream>
#include <string>

extern char look;

extern const char TAB;

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
