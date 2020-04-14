#include <iostream>
#include "ClassSet.h"
using namespace std;


SetOfChar::SetOfChar() {
	for (int i = 0; i < 94; i++) {
		set[i] = false;
	}
}


SetOfChar::SetOfChar(const SetOfChar& setchar, int num_of_elem) { 
	if (num_of_elem > 32 && num_of_elem < 127) {
		for (int i = 0; i < num_of_elem; i++) {
			set[i] = setchar.set[i];
		}
		for (int i = num_of_elem; i < 95; i++) {
			set[i] = false;
		}
	}
}

void SetOfChar::Insert(char c) {
	set[(int)c - 33] = true;
}

void SetOfChar::Delete(char c) {
	set[(int)c - 33] = false;
}

bool SetOfChar::IsEmpty() {
	bool flag = true;
	for (int i = 0; i < 94; i++) {
		if (set[i]) {
			flag = false;
		}
	}
	return flag;
}

void SetOfChar::Print() {
	for (int i = 0; i < 94; i++) {
		if (set[i]) {
			char x = char(i + 33);
			printf("%c", x);
			printf(" ");
		}
	}
	printf("\n");
}
SetOfChar::~SetOfChar() {}
//______________________________________________________

SetOfChar::operator char() {
	return true;
}

SetOfChar::SetOfChar(char c) {
	for (int i = 0; i < 94; i++) {
		set[i] = false;
	}
	set[(int)c - 33] = true;
}
//объединение множеств ( ИЛИ )
SetOfChar SetOfChar::operator +(const SetOfChar& set){
	SetOfChar res;
	for (int i = 0; i < 94; i++) {
		*(res.set + i) =  *(this->set + i) | *(set.set + i);
	}
    return res;
}
// пересечение множеств ( И )
SetOfChar SetOfChar::operator *(const SetOfChar& set)
{
	SetOfChar res;
	for (int i = 0; i < 94; i++) {
		*(res.set + i) = *(this->set + i) & *(set.set + i);
	}
	return res;
}

SetOfChar SetOfChar::operator -(const SetOfChar& set)
{
	SetOfChar res;
	for (int i = 0; i < 94; i++) {
		*(res.set + i) = *(this->set + i) &  ~*(set.set + i);
	}
	return res;

}
// добавление нового элемента в множество
SetOfChar& SetOfChar::operator +=(const SetOfChar& set)
{
	for (int i = 0; i < 94; i++) {
		*(this->set + i) |= *(set.set + i);
	}
	return *this;
}


bool SetOfChar:: operator==(const SetOfChar& set)  //ваил
{     bool fl = true; int i = 0;
    while ((fl) & ( i < 94)) {
        if (*(this->set + i) != *(set.set + i)) {
            fl = false;
        } else i++;
    }
    return fl;
}




bool SetOfChar::operator !=(const SetOfChar& set) // ваил
{       bool fl = true; int i = 0;
    while ((fl) & ( i < 94)) {
		if (*(this->set + i) == *(set.set + i)) {
            fl = false;
        } else i++;
    }
    return fl;
}


SetOfChar& SetOfChar::operator = (const SetOfChar& set)
{
	if (this == &set)
		return *this;
   for (int i = 0; i < 94; i++)
		*(this->set + i) = *(set.set + i);
	return *this;
}

