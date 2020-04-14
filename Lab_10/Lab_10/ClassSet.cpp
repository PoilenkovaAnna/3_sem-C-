#include <iostream>
#include "ClassSet.h"
using namespace std;


SetOfChar::SetOfChar() {
	for (int i = 0; i < 94; i++) {
		set[i] = false;
	}  return;
}

SetOfChar::SetOfChar(const SetOfChar& setchar, int num_of_elem) {  
	if (num_of_elem > 32 && num_of_elem < 127) {
		for (int i = 0; i < num_of_elem; i++) {
			set[i] = setchar.set[i];
		}  for (int i = num_of_elem; i < 95; i++) {
			set[i] = false;
		   }
	} return;
}

void SetOfChar::Insert(char c) {
	set[(int)c - 33] = true;
	return;
}

void SetOfChar::Delete(char c) {
	set[(int)c - 33] = false;
	return;
}

bool SetOfChar::IsEmpty() {
	bool flag = true;
	for (int i = 0; i < 94; i++) {
		if (set[i]) {
			flag = false;
		}
	}	return flag;
}

void SetOfChar::Print() {
	for (int i = 0; i < 94; i++) {
		if (set[i]) {
			char x = char(i + 33);
			printf("%c", x);
			printf(" ");
		}
	}printf("\n");
     return;
}
SetOfChar::~SetOfChar() {}

SetOfChar::operator char() {
	return true;
}

SetOfChar::SetOfChar(char c) {
	for (int i = 0; i < 94; i++) {
		set[i] = false;
	}
	set[(int)c - 33] = true;
	return;
}




//--------------friend--------------------------------------------------------------------
SetOfChar  Un(const SetOfChar& setchar1, const SetOfChar& setchar2) {
	SetOfChar s;
	for (int i = 0; i < 94; i++) {
		s.set[i] = setchar1.set[i] | setchar2.set[i];
	}  return s;
}

SetOfChar In(const SetOfChar& setchar1, const SetOfChar& setchar2) {
	SetOfChar s;
	for (int i = 0; i < 94; i++) {
		s.set[i] = setchar1.set[i] & setchar2.set[i];
	}  return s;
}

SetOfChar Diff(const SetOfChar& setchar1, const SetOfChar& setchar2) {
	SetOfChar s;
	for (int i = 0; i < 94; i++) {
		s.set[i] = setchar1.set[i] & ~setchar2.set[i];
	}  return s;
}
//------------------------------------------------------------------------------------------




SetOfChar& SetOfChar::operator +=(const SetOfChar& setchar1) {
	for (int i = 0; i < 94; i++) {
		*(this->set + i) |= *(setchar1.set + i);
	}
	return *this;
}

bool SetOfChar::operator ==(const SetOfChar& setchar1)  {
   for (int i = 0; i < 94; i++) {
		if (*(this->set + i) != *(setchar1.set + i)) {
			return false;
		}
	} return true;
}

bool SetOfChar::operator !=(const SetOfChar& setchar1)  {
	for (int i = 0; i < 94; i++) {
		if (*(this->set + i) == *(setchar1.set + i)) {
			return false;
		}
	} return true;
}

SetOfChar& SetOfChar::operator = (const SetOfChar& setchar) {
	if (this == &setchar)
		return *this;

	for (int i = 0; i < 94; i++)
		*(this->set + i) = *(setchar.set + i);
	return *this;
}

































/*

SetOfChar SetOfChar::operator +(const SetOfChar& setchar1)
{
	SetOfChar res;
	for (int i = 0; i < 94; i++) {
		*(res.set + i) =  *(this->set + i) | *(setchar1.set + i);
	}
	return res;
}

SetOfChar SetOfChar::operator *(const SetOfChar& setchar1)
{
	SetOfChar res;
	for (int i = 0; i < 94; i++) {
		*(res.set + i) = *(this->set + i) & *(setchar1.set + i);
	}
	return res;
}

SetOfChar SetOfChar::operator -(const SetOfChar& setchar1)
{
	SetOfChar res;
	for (int i = 0; i < 94; i++) {
		*(res.set + i) = *(this->set + i) &  ~*(setchar1.set + i);
	}
	return res;

}
*/
