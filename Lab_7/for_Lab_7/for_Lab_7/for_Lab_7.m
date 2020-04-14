//
//  for_Lab_7.m
//  for_Lab_7
//
//  Created by Anna  on 20/11/2019.
//  Copyright © 2019 Anna . All rights reserved.
//

#import "for_Lab_7.h"


@implementation for_Lab_7

#include <iostream>
using namespace std;

const int NMAX = 33;
bool New_Space = true;
 extern "C" __declspec(dllexport)  void Add_Element(char * &a, int i, int old_size, int new_size, char c) {
    char * new_a = new char[new_size];
    int check = i;
    for (i = 0; i < old_size; ++i)
        new_a[i] = a[i - check];
    if (check == 0)
        new_a[new_size - 1] = c;
    else
        new_a[0] = c;
    delete[] a;
    a = new_a;
    return;
}
 extern "C" __declspec(dllexport)  bool IsCorrect(char cur) {
    bool flag = false;
    if (  ((cur >= 'a') && (cur <= 'z' )) || (( cur >= 'A') && (cur <= 'Z'))  ||  ((cur >= '0' ) && (cur <= '9'))   ){
        flag = true;
    }
    return flag;
}
 extern "C" __declspec(dllexport) void Convert_String(char* input_str, char* &convert_str, char* &output_str, int& cur, int last, int& length) {
    
    if (cur == last) {
        return;
    }
    else if (IsCorrect(input_str[cur])) {
        Add_Element(convert_str, 0, length, length + 1, input_str[cur]);
        Add_Element(output_str, 1, length + 1, length + 1, input_str[cur]);
        New_Space = true;
        length++;
    }
    else if (New_Space) {
        Add_Element(convert_str, 0, length, length + 1, ' ');
        Add_Element(output_str, 1, length + 1, length + 1, ' ');
        New_Space = false;
        length++;
    }
    cur++;
    Convert_String(input_str, convert_str, output_str, cur, last, length);
    return;
}
 extern "C" __declspec(dllexport)  void Print(char* str, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}
 extern "C" __declspec(dllexport)  bool IsEmpty(char* str, int length) {
    bool flag = false;
    if (length == 1) {
        flag = true;
    }
    return flag;
}
@end
