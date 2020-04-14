#pragma once

#include <iostream>
using namespace std;


class SetOfChar {
public:
    SetOfChar();
    SetOfChar(const SetOfChar& setchar, int num_of_elem);
    void Delete(char c);
    bool IsEmpty();
    void Insert(char c);
    void Print();
    operator char();
    SetOfChar(char c);
    ~SetOfChar();

	friend SetOfChar Un(const SetOfChar& setchar1, const SetOfChar& setchar2);
    friend SetOfChar In(const SetOfChar& setchar1, const SetOfChar& setchar2);
    friend SetOfChar Diff(const SetOfChar& setchar1, const SetOfChar& setchar2);

	SetOfChar& operator +=(const SetOfChar& setchar1);
	bool operator ==(const SetOfChar& setchar1) ;
	bool operator !=(const SetOfChar& setchar1) ;
	SetOfChar& operator =  (const SetOfChar& setchar);
	
private:
	bool set[94];
};






















/*
 SetOfChar operator +(const SetOfChar& setchar1);
 SetOfChar operator *(const SetOfChar& setchar1);
 SetOfChar operator -(const SetOfChar& setchar1);
 */
