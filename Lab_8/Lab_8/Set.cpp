#include <iostream>
#include "Set.h"
using namespace std;

SetOfChar::SetOfChar() {
    for (int i = 0; i < 94; i++) {
        set[i] = false;
    }
    return;
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


void  SetOfChar::Union(const SetOfChar& setchar1, const SetOfChar& setchar2) {
    for (int i = 0; i < 94; i++) {
        set[i] = setchar1.set[i] | setchar2.set[i];
    }
}

void SetOfChar::Isertion(const SetOfChar& setchar1, const SetOfChar& setchar2) {
    for (int i = 0; i < 94; i++) {
        set[i] = setchar1.set[i] & setchar2.set[i];
    }
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


SetOfChar::SetOfChar(char c) {
    for (int i = 0; i < 94; i++) {
        set[i] = false;
    }
    set[(int)c - 33] = true;
}


