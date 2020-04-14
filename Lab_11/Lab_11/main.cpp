
#include <iostream>
#include "ClassOfChar.h"
#include "ClassesExceptions.h"

int main() {
    SetOfChar s1;
    try {
        s1.Insert('a');
        s1.Insert('b');
        s1.Insert('c');
        s1.Insert('a');
    }
    catch (ex1& exception) {
        printf("%s%c\n\n", exception.what(), exception.get_char());
    }
    printf("SET-1 :");
    s1.PrintSet();
//----------------
    SetOfChar s2;
    try {
        s2 += 'c';
        s2 += 'd';
        s2 += 'e';
    }
    catch (ex1& exception) {
        printf("%s%c\n\n", exception.what(), exception.get_char());
    }
    printf("SET-2 :");
    s2.PrintSet();
//-----------------------------------операции с SETs-------------------------------
    SetOfChar s3;
    try {
        s3 = s1 + s2;
    }
    catch (ex2& exception) {
        printf("%s \n", exception.what());
    }
    printf("SET-3 (объединение): ");
    s3.PrintSet();
    
    try {
        s3 = s3 - s1;
    }
    catch (ex2& exception) {
        printf("%s \n", exception.what());
    }
    printf("Разность SET-3 и SET-2:");
    s3.PrintSet();
    
    printf("Пересечение SET-1 и SET-2:");
    try {
        (s1*s2).PrintSet();
    }
    catch (ex2& exception) {
        printf("%s \n\n", exception.what());
    }
    
    printf("Пересечение SET-3(после разности) и SET-1: ");
    try {
        (s1*s3).PrintSet();
    }
    catch (ex2& exception) {
        printf("%s \n\n", exception.what());
    }
    
    return 0;
}
