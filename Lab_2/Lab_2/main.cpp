//Даны две матрицы разного размера. Для той из матриц, в которой больше произведение
// ненулевых элементов, найти количество положительных элементов в каждой строке.

#include <iostream>

using namespace std;

const int nmax = 15;

void input(int n, int m, int **& a, FILE *fin) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; ++j) {
            fscanf(fin, "%d", &a[i][j]);
        }
    }
    return;
}

void output(int n, int m, int ** a, FILE *fout) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; ++j) {
            fprintf(fout, "%d ", a[i][j]);
        }
        fprintf(fout, "\n");
    }
    return;
}

void output_2(int n, int * a, FILE *fout) {
    for (int i = 0; i < n; ++i) {
        fprintf(fout, "%d ряд %d \n", i + 1, a[i]);
    }
    return;
}

int Quantity(int n, int m, int ** a) {
    int num = 1;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] > 0) {
                num *= a[i][j];
            }
        }
    }
    
    return num;
}

void PoisitivQuantity(int n, int m, int ** a, int x[]) {
    for (int i = 0; i < m; i++) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (a[i][j] > 0) {
                ++count;
            }
        }
        x[i] = count;
    }
    return;
}

int RowPoisitivQuantity(int num, int *a) {
    int count = 0;
    for (int i = 0; i < num; ++i) {
        if (a[i] > 0) {
            ++count;
        }
    }
    return count;
}

void output_3(int m, int ** a, FILE *fout) {
    int result;
    
    for (int i = 0; i < m; ++i) {
        result = RowPoisitivQuantity(m, a[i]);
        fprintf(fout, "%d", i + 1);
        fprintf(fout, " ряд: ");
        fprintf(fout, "%d", result);
        fprintf(fout, "\n");
    }
    return;
}

void matrix_dec(int m, int n, int **& a ){
    a = new int *[m];
    for (int i = 0; i < m; ++i){
        a[i] = new int [n];
    }
    return;
}


int main() {
    int width_1, height_1, width_2, height_2;
    
    printf("Первая марица: ");
    printf("\n");
    printf("кол-во строк: ");
    scanf("%d", &width_1);
    printf("кол-во столбцов: ");
    scanf("%d", &height_1);
    printf("\n");
    
    printf("Вторая матрица: ");
    printf("\n");
    printf("кол-во строк: ");
    scanf("%d", &width_2);
    printf("кол-во столбцов: ");
    scanf("%d", &height_2);
    printf("\n");
    
    
    FILE *fin_1, *fin_2, *fout;
    
    fin_1 = fopen("lab_2_1_input.txt", "r");
    fin_2 = fopen("lab_2_2_input.txt", "r");
    fout = fopen("lab_2_output.txt", "w");
    
    if (!(fin_1) || !(fin_2)) printf("Error: file!");
    else {
        int **x, **y;
        matrix_dec(height_1, width_1, x);
        matrix_dec(height_2, width_2, y);
        
        input(width_1, height_1, x, fin_1);
        input(width_2, height_2, y, fin_2);
        
        int choose;
        printf("Выберите метод: \n");
        printf("1 -  \n");
        printf("2 -  \n");
        printf("Вы выбрали: ");
        scanf("%d", &choose);
        
        if (choose == 1) {
            fprintf(fout, "------------------------------------------------------");
            fprintf(fout, "\n");
            fprintf(fout, "\n");
            
            fprintf(fout, "введено: ");
            fprintf(fout, "\n");
            
            output(width_1, height_1, x, fout);
            fprintf(fout, "\n");
            output(width_2, height_2, y, fout);
            fprintf(fout, "\n");
            
            int first = Quantity(width_1, height_1, x);
            int second = Quantity(width_2, height_2, y);
            
            fprintf(fout, "Произведение не нулевых первой матрицы: ");
            fprintf(fout, "%d", first);
            fprintf(fout, "\n");
            fprintf(fout, "Произведение не нулевых второй матрицы: ");
            fprintf(fout, "%d", second);
            fprintf(fout, "\n");
            fprintf(fout, "\n");
            
            if (second > first) {
                fprintf(fout, "у второй матрицы произведение больше! \n");
                fprintf(fout, "\n");
                int result[height_2];
                PoisitivQuantity(height_2, width_2, y, result);
                fprintf(fout, "результат: \n");
                output_2(height_2, result, fout);
            } else {
                fprintf(fout, "у первой матрицы произведение больше! \n");
                fprintf(fout, "\n");
                int result[height_1];
                PoisitivQuantity(height_1, width_1, x, result);
                fprintf(fout, "Результат: \n");
                output_2(height_1, result, fout);
            }
            
            fprintf(fout, "------------------------------------------------------------");
            fprintf(fout, "\n");
        } else if (choose == 2) {
            fprintf(fout, "----------------------------------------------------------");
            fprintf(fout, "\n");
            fprintf(fout, "\n");
            
            fprintf(fout, "введенное: ");
            fprintf(fout, "\n");
            
            output(width_1, height_1, x, fout);
            fprintf(fout, "\n");
            output(width_2, height_2, y, fout);
            fprintf(fout, "\n");
            
            int first = Quantity(width_1, height_1, x);
            int second = Quantity(width_2, height_2, y);
            
            fprintf(fout, "Произведение не нулевых первой матрицы: ");
            fprintf(fout, "%d", first);
            fprintf(fout, "\n");
            fprintf(fout, "Произведение не нулевых второй матрицы: ");
            fprintf(fout, "%d", second);
            fprintf(fout, "\n");
            fprintf(fout, "\n");
            if (second > first) {
                fprintf(fout, "у второй матрицы произведение больше! \n");
                fprintf(fout, "\n");
                
                output_3(height_2, y, fout);
            } else {
                fprintf(fout, "у первой матрицы произведение больше!  \n");
                fprintf(fout, "\n");
                output_3(height_1, x, fout);
            }
            
            fprintf(fout, "------------------------------------------------------------");
            fprintf(fout, "\n");
        } else printf("Error: неизвестный метод");
        
        delete []x;
        delete []y;
        fclose(fin_1);
        fclose(fin_2);
        fclose(fout);
    }
    return 0;
}









































/*

//
//Даны две матрицы разного размера. Для той из матриц, в которой меньше среднее арифметическое положительных элементов, найти произведение ненулевых элементов в каждой строке.
//  main.cpp
//  Lab_2
//
//  Created by Anna  on 09/10/2019.
//  Copyright © 2019 Anna . All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <fstream>// для файла
using namespace std;
const int c_nmax = 100;

void InPut(float mas[][c_nmax], int str, int st, FILE*f){
    for(int i=0; i<str; i++) {
        for ( int j=0; i<st; j++) {
            fscanf ( f, "%f" ,&mas[i][j]);
        }
        fprintf(f, "\n");
        cout <<" "<< endl;
    }
    return;
}


// вывод массива
void output (int mas[], int n, FILE*f){
    for(int i=0;i<n;i++) {
        fprintf ( f, "%d " ,mas[i] );
    }
    fprintf (f,"\n");
    return;
}

//произведение ненулевых элементов в фикс строке
float Prod( float mas[][c_nmax], int fix_str, int st){
    int p=1;
    for ( int i=0; i < st; i++)
        if (mas[fix_str][i] != 0) {
            p *=mas[fix_str][i];
        }
    return  p;
}

void ForMin(float mas[][c_nmax], int str, int st){
    for(int i=0; i<str; i++) {
        Prod(mas,i, st);
    }
    return;
}


int ArithMean ( float mas[][c_nmax], int str, int st) {
    int p=0;
    int j=0;
    for(int i=0; i<str; i++)
        for ( int j=0; i<st; j++) {
            if (mas[i][j] >= 0) {
                p +=mas[i][j];
                j++;
            }
}
      return  p/j;
}

int main(){
   
    
    FILE* fin_1, *fin_2, *fout;
    fin_1 = fopen("lab2_1.txt","r");
    fin_2 = fopen("lab2_2.txt","r");
    fout = fopen("lab2_out.txt","w");
    
    if (!(fin_1) || !(fin_1) || !(fin_1) || !(fin_1)) printf("Error file");
    else {

        int str1, st1, str2, st2;
        puts ("Введите размеры первого массива");
        scanf ("%d %d \n",&str1,&st1);
        printf("Вы ввели  %d и %d \n",str1,st1);
        
        puts ("Введите размеры второго массива");
        scanf ("%d %d \n",&str2,&st2);
        printf("Вы ввели  %d и %d \n",str2, st2);
        
        float mas1[str1][st1], mas2[str2][st2];
        
        InPut(mas1[][], str1, st1, fin_1);
        InPut(mas2[][], str2, st2, fin_1);
        
        ArithMean (mas1[][], str1, st1);
        ArithMean (mas2[][], str2, st2);
        
        ForMin(float *ptarray, int str, int st)
        ForMin(float *ptarray, int str, int st)
        
    
    }
        
        return 0;
    }
}

//попытки динамического

/*
 
 void InPut(float *ptarray, int str, int st, FILE*f){
 ptarray = new float[str][st];
 for(int i=0; i<str; i++) {
 for ( int j=0; i<st; j++) {
 fscanf ( f, "%d" ,&ptarray);
 //cout << ptarray[i][j] << " ";
 }
 fprintf(f, "\n");
 cout <<" "<< endl;
 }
 return;
 }
 
 float Prod( float *ptarray, int fix_str, int st){
 int p=1;
 for ( int i=0; i < st; i++)
 if (ptarray[fix_str][i] != 0) {
 p *=ptarray[fix_str][i];
 }
 return  p;
 }
 
 void ForMin(float *ptarray, int str, int st){
 ptarray = new float[str][st];
 for(int i=0; i<str; i++) {
 Prod(ptarray,i, st);
 }
 return;
 }
 
 
 int ArithMean ( float *ptarray, int str, int st) {
 int p=0;
 int j=0;
 for(int i=0; i<str; i++)
 for ( int j=0; i<st; j++) {
 if (ptarray[i][j] >= 0) {
 p +=ptarray[i][j];
 j++;
 }
 return  p/j;
 }
 }
 
 int main(){
 
 
 FILE* fin_1, *fin_2, *fout;
 fin_1 = fopen("lab2_1.txt","r");
 fin_2 = fopen("lab2_2.txt","r");
 fout = fopen("lab2_out.txt","w");
 
 if (!(fin_1) || !(fin_1) || !(fin_1) || !(fin_1)) printf("Error file");
 else {
 float *ptarray_1;
 float *ptarray_2;
 
 int str1, st1, str2, st2;
 puts ("Введите размеры первого массива");
 scanf ("%d %d \n",&str1,&st1);
 printf("Вы ввели  %d и %d \n",str1,st1);
 
 puts ("Введите размеры второго массива");
 scanf ("%d %d \n",&str2,&st2);
 printf("Вы ввели  %d и %d \n",str2, st2);
 
 InPut(ptarray_1, str1, st1, fin_1);
 InPut(ptarray_2, str2, st2, fin_1);
 
 ArithMean (ptarray_1, str1, st1);
 ArithMean (ptarray_2, str2, st2);
 
 ForMin(float *ptarray, int str, int st)
 ForMin(float *ptarray, int str, int st)
 
 
 }
 
 return 0;
 }
 }

 */
