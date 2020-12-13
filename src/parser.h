#ifndef PARSER
#define PARSER

void Term();

void Add();

void Subtract();

void Expression();

void Assignment();

void Multiply();

void Divide();

void Factor();

bool IsAddop(char c);

bool IsWhite(char c);

bool IsAlNum(char c);

void SkipWhite();

void Ident();

bool IsWhite(char c);

#endif
