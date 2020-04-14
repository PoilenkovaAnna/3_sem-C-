/*Переделать задачу с тремя массивами так, чтобы вспомогательная функция (не main) работала не с
 * элементом массива Xi, а с выражением f(Xi), где f – некоторая функция (одного аргумента!), указатель
 * на которую передаётся через параметры. В качестве фактического параметра передавать указатель на
 * стандартную библиотечную функцию и указатель на пользовательскую функцию.
 * Ввод/вывод производить из файла/в файл (пример см. в лекции 4).
 * --------------------------------------------------------------------------------------------------------
 * Определить в каком массиве больше количество элементов, меньших заданного числа.
 * Если в двух или трёх массивах количества искомых элементов совпадают, вывести соответствующее сообщение.
 */

#include <iostream>
#include <cmath>

typedef double (*PF) (double);

using namespace std;

double  f_1(double x) {
    return exp(x);
}
double f_2(double x) {
    return sin(x);
}
double f_3(double x) {
    return log(x);
}
double f_4 (double x){
    return x;
}

void input(int& number, int a[], FILE* fin) {
    for (int i = 0; i < number; i++) {
        fscanf(fin, "%d", &a[i]);
    }
    return;
}


int finding(int x[], int& condition, int num, PF f) {
    int count = 0;
    for (int i = 0; i < num; ++i) {
        if (f(x[i]) > condition) {
            ++count;
        }
    }
    return count;
}

void output(int& number, int a[], FILE* fout) {
    for (int i = 0; i < number; i++) {
        fprintf(fout, "%d ", a[i]);
    };
    fprintf(fout, "\n");
    return;
}

int main()
{
    int  x[15], y[15], z[15];
    int num;
    int cond;
    
    printf("сколько элементов: ");
    scanf("%d", &num);
    printf("введите число: ");
    scanf("%d", &cond);
    
    FILE* fin_1, * fin_2, * fin_3, * fout;
    
    fin_1 = fopen("lab_1_input_1.txt", "r");
    fin_2 = fopen("lab_1_input_2.txt", "r");
    fin_3 = fopen("lab_1_input_3.txt", "r");
    fout = fopen("output.txt", "w");
    
    if (!(fin_1) || !(fin_2) || !(fin_3))    printf("Error_1 \n");
    else {
        
        PF function_1, function_2, function_3, function_4;
        
        function_1 = &f_1;
        function_2 = &f_2;
        function_3 = &f_3;
        function_4 = &f_4;
        
        
        input(num, x, fin_1);
        input(num, y, fin_2);
        input(num, z, fin_3);
        
        
        printf("выберите метод: ");
        int choose;
        scanf("%d", &choose);
        
        int first;
        int second;
        int third;
        
        if (choose == 1) {
            first = finding(x, cond, num, function_1);
            second = finding(y, cond, num, function_1);
            third = finding(z, cond, num, function_1);
        } else if (choose == 2) {
            first = finding(x, cond, num, function_2);
            second = finding(y, cond, num, function_2);
            third = finding(z, cond, num, function_2);
        } else if (choose == 3) {
            first = finding(x, cond, num, function_3);
            second = finding(y, cond, num, function_3);
            third = finding(z, cond, num, function_3);
        } else {
            printf("Error: function_4 was chosen automatically \n");
            first = finding(x, cond, num, function_4);
            second = finding(y, cond, num, function_4);
            third = finding(z, cond, num, function_4);
        }
        
        
        fprintf(fout, "-----------------------------------------------------------");
        fprintf(fout, "\n");
        
        fprintf(fout, "заданное число: ");
        fprintf(fout, "%d", cond);
        fprintf(fout, "\n");
        fprintf(fout, "\n");
        //-------------------------------------------------------------------------------------------------------------------
        fprintf(fout, "первый: ");
        output(num, x, fout);
        fprintf(fout, "\n");
        
        fprintf(fout, "второй: ");
        output(num, y, fout);
        fprintf(fout, "\n");
        
        fprintf(fout, "третий: ");
        output(num, z, fout);
        fprintf(fout, "\n");
        //-------------------------------------------------------------------------------------------------------------------
        fprintf(fout, "кол-во в первом: ");
        fprintf(fout, "%d", first);
        fprintf(fout, "\n");
        
        fprintf(fout, "кол-во во втором: ");
        fprintf(fout, "%d", second);
        fprintf(fout, "\n");
        
        fprintf(fout, "кол-во в третьем: ");
        fprintf(fout, "%d", third);
        fprintf(fout, "\n");
        fprintf(fout, "\n");
        
        
        if ((first > second) && (first > third)) {
            fprintf(fout, "в первом массиве больше количество элементов, меньших заданного числа! \n");
        }
        else if ((second > first) && (second > third)) {
            fprintf(fout, "во втором массиве больше количество элементов, меньших заданного числа! \n");
        }
        else if ((third > first) && (third > second)) {
            fprintf(fout, "в третьем массиве больше количество элементов, меньших заданного числа! \n");
        }
        else if ((first == second) && (first != third)) {
            fprintf(fout, "в первом и третьем массиве больше количество элементов, меньших заданного числа! \n");
        }
        else if ((first == third) && (first != second)) {
            fprintf(fout, "в первом и третьем массиве больше количество элементов, меньших заданного числа! \n");
        }
        else if ((second == third) && (second != first)) {
            fprintf(fout, "во втором и третьем массиве больше количество элементов, меньших заданного числа! \n");
        }
        else {
            fprintf(fout, "все равно! \n");
        }
        
        fprintf(fout, "-------------------------------------------------------------");
        fprintf(fout, "\n");
        
        printf("The end");
        printf("\n");
        
        fclose(fin_1);
        fclose(fin_2);
        fclose(fin_3);
        fclose(fout);
    }
}
