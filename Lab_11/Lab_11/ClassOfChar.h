#pragma once

#include <iostream>

using namespace std;

class SetOfChar {
public:
	void AssignSet();
	SetOfChar();
	SetOfChar(const SetOfChar& set_char, int num_char);
	void Insert(char ch);
	void DeleteChar(char ch);
	bool IsEmpty();
	char ToChar(const SetOfChar& setchar);
	void PrintSet();
    bool Repeated(const char& ch);
	SetOfChar(char ch);
    
    friend SetOfChar Unity(const SetOfChar& set_char1, const SetOfChar& set_char2);
    friend SetOfChar Intersection(const SetOfChar& set_char1, const SetOfChar& set_char2);
    friend SetOfChar Difference(const SetOfChar& set_char1, const SetOfChar& set_char2);

	~SetOfChar();

	SetOfChar operator + (const SetOfChar& set_char);
	SetOfChar operator - (const SetOfChar& set_char);
	SetOfChar operator * (const SetOfChar& set_char);
	SetOfChar& operator += (const SetOfChar& set_char);
	bool operator == (const SetOfChar& set_char);
	bool operator != (const SetOfChar& set_char);
	SetOfChar& operator = (const SetOfChar& set_char);

private:
	bool set[94];
};

