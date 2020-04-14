#pragma once
#include <iostream>
using namespace std;


class SetOfChar {
public:
    SetOfChar();
    SetOfChar(const SetOfChar& setchar, int num_of_elem);
 bool IsEmpty();
 void Insert(char c);
 void Delete(char c);
 void Union(const SetOfChar& setchar1, const SetOfChar& setchar2);
 void Isertion(const SetOfChar& setchar1, const SetOfChar& setchar2);
 void Print();
    
  SetOfChar(char c);
    
~SetOfChar();
    
private:
    bool set[94];
};
