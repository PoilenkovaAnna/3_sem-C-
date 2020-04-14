
#include "ClassSet.h"


int main()
{
    SetOfChar s1;
    s1.Insert('a');
    s1.Insert('b');
    printf("SET-1 : ");
    s1.Print();
    
    SetOfChar s2;
    s2.Insert('a');
    s2.Insert('c');
    s2.Insert('d');
    
    printf("SET-2 : ");
    s2.Print();
    
    SetOfChar s3;
    s3.Insert('1');
    s3.Insert('*');
    
    printf("SET-3: ");
    s3.Print();
    
    SetOfChar s4;
    s4 = Un(s3, s2);
    printf("объединение SET-2 и SET-3 : ");
    s4.Print();
    
    s2 = In(s1, s2);
    printf("пересечение SET-1 и SET-2 : ");
    s2.Print();
    
    printf("\n");
    return 0;
}
