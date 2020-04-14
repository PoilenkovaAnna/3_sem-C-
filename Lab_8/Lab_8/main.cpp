/*Разработать класс для представления объекта множество символов*.
 Определить конструктор с одним параметром-строкой,
 который задаёт элементы множества и который можно использовать как конструктор умолчания.
 Определить конструктор, который копирует в новое множество элементы другого множества,
 не превышающие заданное значение, который можно использовать как конструктор копирования.
 Определить деструктор.
 Определить преобразования из переменной типа char в множество и из множества в переменную типа char.*/



#include "Set.h"


int main()
{
    SetOfChar s1;
    s1.Insert('a');
    s1.Insert('b');
    printf("SET1 после добавления а и b: ");
    s1.Print();
    
    SetOfChar s2(s1, 98);   //копирую множество 1 не превышая буквы b
    printf("SET2, созданное копированием мн-ва 1, не превышая букву b: ");
    s2.Print();
    
    printf("SET2 после повторного добавления а и c, d: ");
    s2.Insert('a');        //проверка, что а два раза не входит
    s2.Insert('c');
    s2.Insert('d');
    s2.Print();
    
    
    printf("SET2 после удаления с: ");
    s2.Delete('c');
    s2.Print();
    
    SetOfChar s3;
    
    printf("Провекра на пустоту множетсва: ");
    if (s3.IsEmpty()) {
        printf("set is empty\n");
    }
    

    printf("SET3: ");
    s3.Insert('1');
    s3.Insert('{');
    s3.Print();
    
    
    printf("множетсво 3 после объединения с мн-вом 2: ");
    s3.Union(s3, s2);       // проверка объединения
    s3.Print();
    
    return 0;
}