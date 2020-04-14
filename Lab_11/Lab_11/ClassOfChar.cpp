
#include "ClassOfChar.h"
#include "ClassesExceptions.h"
#include <iostream>

void SetOfChar::AssignSet() {
    for (int i = 0; i < 94; i++) {
        set[i] = false;
    }
    return;
}

SetOfChar::SetOfChar() {
    AssignSet();
}

SetOfChar::SetOfChar(const SetOfChar& set_char, int num_char) {
    AssignSet();
    if (num_char > 32 && num_char < 127) {
        for (int i = 0; i < num_char - 32; i++) {
            set[i] = set_char.set[i];
        }
    }
    return;
}

void SetOfChar::Insert(char ch) {
    if (Repeated(ch))
        throw ex1(" -символ уже в сете-  ", ch);
    set[(int)ch - 33] = true;
    return;
}

void SetOfChar::DeleteChar(char ch) {
    set[(int)ch - 33] = false;
    return;
}

char SetOfChar::ToChar(const SetOfChar& setchar) {
    int i = 0;
    bool fl = false;
    while ((!fl) && (i < 94)) {
        if (setchar.set[i]) {
            return (char(i + 33));
        }
        ++i;
    }
    return '0';
}

bool SetOfChar::IsEmpty() {
    bool fl = true; int i = 0;
    while ((i < 94) && (fl)) {
        if (set[i])
            fl = false;
        i++;
    } return fl;
}

bool SetOfChar::Repeated(const char& ch) {
    if (set[(int)ch - 33])
        return true;
    return false;
}

void SetOfChar::PrintSet() {
    for (int i = 0; i < 94; i++) {
        if (set[i]) {
            char x = char(i + 33);
            printf("%c ", x);
        }
    } printf("\n");
    return;
}

SetOfChar::~SetOfChar() {}

SetOfChar::SetOfChar(char ch) {
    for (int i = 0; i < 94; i++) {
        set[i] = false;
    }  set[(int)ch - 33] = true;
}
//-----------------------------------------------------------------------------
SetOfChar Unity(const SetOfChar& set_char1, const SetOfChar& set_char2) {
    SetOfChar r;
    for (int i = 0; i < 94; i++) {
        r.set[i] = (set_char1.set[i] | set_char2.set[i]);
    } if (r.IsEmpty())
        throw ex2("-пустой сет после операции объединения-");
    return r;
}

SetOfChar Intersection(const SetOfChar& set_char1, const SetOfChar& set_char2) {
    SetOfChar r;
    for (int i = 0; i < 94; i++) {
        r.set[i] = (set_char1.set[i] & set_char2.set[i]);
    } if (r.IsEmpty())
        throw ex2("-пустой сет после операции пересечение-");
    return r;
}

SetOfChar Difference(const SetOfChar& set_char1, const SetOfChar& set_char2) {
    SetOfChar r;
    for (int i = 0; i < 94; i++) {
        r.set[i] = (set_char1.set[i] & ~(set_char2.set[i]));
    } if (r.IsEmpty())
        throw ex2("-пустой сет после операции разности-");
    return r;
}
//-----------------------------------------------------------------------------
SetOfChar SetOfChar::operator + (const SetOfChar& set_char) {
    SetOfChar r;
    for (int i = 0; i < 94; i++) {
        *(r.set + i) = *(this->set + i) | *(set_char.set + i);
    } if (r.IsEmpty())
        throw ex2("-пустой сет после операции объединения-");
    return r;
}

SetOfChar SetOfChar::operator - (const SetOfChar& set_char) {
    SetOfChar r;
    for (int i = 0; i < 94; i++) {
        *(r.set + i) = *(this->set + i) & ~*(set_char.set + i);
    } if (r.IsEmpty())
        throw ex2("-пустой сет после операции разности-");
    return r;
}

SetOfChar SetOfChar::operator * (const SetOfChar& set_char) {
    SetOfChar r;
    for (int i = 0; i < 94; i++) {
        *(r.set + i) = *(this->set + i) & *(set_char.set + i);
    } if (r.IsEmpty())
        throw ex2("-пустой сет после операции обьединения-");
    return r;
}

SetOfChar& SetOfChar::operator += (const SetOfChar& set_char) {
    if (char ch = Repeated(ToChar(set_char)))
        throw ex1(" -символ уже в сете-  ", ch);
    for (int i = 0; i < 94; i++) {
        *(this->set + i) |= *(set_char.set + i);
    }
    
    return *this;
}

bool SetOfChar::operator == (const SetOfChar& set_char)  { //ваил
    int i = 0;
    bool fl = true;
    while ((i < 94) && (fl)) {
        if (*(this->set + i) != *(set_char.set + i))
            fl = false;
        i++;
    }
    return fl;
}

bool SetOfChar::operator != (const SetOfChar& set_char)  {
    return (!(this == &set_char));
}

SetOfChar& SetOfChar::operator = (const SetOfChar& set_char) {
    if (this == &set_char)
        return *this;
    for (int i = 0; i < 94; i++)
        *(this->set + i) = *(set_char.set + i);
    return *this;
}


