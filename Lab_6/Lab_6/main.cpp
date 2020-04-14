/*Написать функцию, указанную в задании, используя только операции над битами
 * (никаких возведений в степень и т.п.). Во всех вариантах необходимо менять все биты сразу, а не по одному в цикле.
 * Биты нумеруются с 0 до 31 начиная с правого бита. Бит с номером p должен меняться.
 * Написать программу для проверки правильности работы функции. Для того, чтобы было удобно проверять правильность
 * работы с битами, исходное и полученное число можно вывести, используя формат %08x – целое число в шестнадцатеричной
 * системе счисления, 8 знаков, впереди добавляются нули. Необходимо проверять корректность введённых значений
 * переменных n и p.
 *----------------------------------------------------------------------------------------------------------------------
 * Написать функцию, которая в числе x инвертирует n бит, находящихся слева от позиции p, остальные биты остаются без изменения.
 * без изменения.*/

/*
 * & (bitwise AND) Takes two numbers as operands and does AND on every bit of two numbers. The result of AND is 1 only if both bits are 1.
 * | (bitwise OR) Takes two numbers as operands and does OR on every bit of two numbers. The result of OR is 1 if any of the two bits is 1.
 * ^ (bitwise XOR) Takes two numbers as operands and does XOR on every bit of two numbers. The result of XOR is 1 if the two bits are different.
 * << (left shift) Takes two numbers, left shifts the bits of the first operand, the second operand decides the number of places to shift.
 * >> (right shift) Takes two numbers, right shifts the bits of the first operand, the second operand decides the number of places to shift.
 * ~ (bitwise NOT) Takes one number and inverts all bits of it
 */


#include <iostream>
#define usize 32

using namespace std;

void PRINT_BIN(int x)
{
    unsigned mask = 0x80000000; // 10000000000000000000000000000000
    int i;
    
    //10000000000000000000000000000000
    //00000000000000000000000000001100 - 12
    
    for (i = 0; i < 32; i++)
    {
        if (x & mask)
            printf("1");
        else
            printf("0");
        x = x << 1;
    }
    
    printf("\n");
    return;
}

int CHANGE_NUMBER(int x, int p, int n)
{
  unsigned int mask = 0xffffffff; //01111111111111111111111111111111
 //  PRINT_BIN(mask);
   //mask = (mask << 32 - n) ;
 //  PRINT_BIN(mask);
  // mask = mask>> (32 - p - n);
  // PRINT_BIN(mask);
    
    mask = (mask << 32 - n) >> (32 - p - n);
    return x ^ (mask);
}

int main()
{
    int x, p, n;
    printf("--------------------------------------------------------- \n");
    
    printf("введите число: ");
    scanf("%d", &x);
    
    printf("\nчисло в двоичной системе:\n");
    PRINT_BIN(x);
    
    printf("\n Введите X, число бит в которых установятся нули (от 1 до 32): ");
    scanf("%d", &n);
    
    if (n < 1 || n > 32) {
        printf("Error: \n");
    } else {
        printf("\n");
        printf("отступ от 0 до %d: ", (usize - n));
        scanf("%d", &p);
        if (p < 0 || p > usize - n) {
            printf("Error:  \n");
        } else {
            x = CHANGE_NUMBER(x, p, n);
            printf("\nИзмененное число:\n");
            PRINT_BIN(x);
        }
    }
    printf("------------------------------------------------------------ \n");
    return 0;
    
}




//сколько будет 1 или 0 после той или иной операчии по заданию/ по разным заданиям сдвигам

//00000000000000000000100110010101
//00000000000000000000100110010101

//00000000000000000000010110100001
//01111111111111111111101001011101

//00000000000000000000000100000000
//00000000000000000000011111110000
//00000000000000000000011000000000

//без сдвига
//00000000000000000001100011000000
//00000000000000000000000000000111
//00000000000000000001100011000111
