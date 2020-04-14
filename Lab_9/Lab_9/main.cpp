#include "ClassSet.h"
int main()
{
    SetOfChar s1;
    s1.Insert('a');
    s1.Insert('b');
    
    printf("SET-1 : ");
    s1.Print();
    
    SetOfChar s2;
    s2.Insert('c');
    s2.Insert('d');
    s2.Insert('a');
    
    printf("SET-2 : ");
    s2.Print();
    
    SetOfChar s3;
    s3 = s2 + s1;
    
    printf("SET-3 (созданное объединеним 1 и 2 сетом: )");
    s3.Print();

    SetOfChar s4;
    s4 = s2 * s1;
    printf("SET-4 (созданное пересечением 1 и 2 сетом: )");
    s4.Print();
    
    SetOfChar s5;
    s5 = s3;
    printf("SET-5 (созданное присваиванием множества 3: )");
    s5.Print();
    
    if (s3 != s5) {
        printf("SET-3 & SET-5  не равны\n");
    }
    else {
        printf("SET-3 & SET-5  равны\n");
    }
     s5 += '*';
    printf("SET-5  после добавления * : ");
    s5.Print();
return 0;
}
