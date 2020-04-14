// Каждая запись представляет собой 4 числа типа double.
#include <iostream>

const int c_n = 4; //кол-во записей
const int c_m = 5;
typedef double t_mass[c_n];

void f_text_to_bin(FILE* fin_text, FILE *fout_bin);
void f_change_row(FILE *&fout_bin, int v_m, int v_n);
void f_print_bin(FILE *fout_bin);

int main()
{
    FILE* fin_text;
    FILE *fout_bin;
    
    int v_m, v_n; //строки которые надо поменять
    
    fin_text = fopen("lab_3.txt", "rt");
    fout_bin = fopen("fout.bin","w+b"); //для чтения и записи
    
    f_text_to_bin(fin_text, fout_bin); // делаем бинарный из текстового
    f_print_bin(fout_bin);
    
    fclose(fin_text);
    fclose(fout_bin);
    
    //Меняем бин
    printf("Введите ряд для изменения \n");
    scanf("%d%d", &v_m, &v_n);
    
    fout_bin = fopen("fout.bin", "rb+"); //для чтения и записи
    f_change_row(fout_bin,v_m,v_n);
    
    f_print_bin(fout_bin);
    
    fclose(fout_bin);
    return 0;
}

void f_text_to_bin(FILE* fin_text, FILE *fout_bin){
    if (fout_bin == NULL)
    {
        printf("Error: cant't open file");
    }
    else{
        while (!feof(fin_text)){
            char m_str[100]; // массив символов максимум из 4х элеметнов
            fgets(m_str, 100, fin_text); //записали строку из файла в массив
            
            int v_i = 0;
            bool v_flag = true;
            int v_count = 1;
            char m_num1[10], m_num2[10],m_num3[10], m_num4[10];
            int v_i1 = 0, v_i2 = 0, v_i3 = 0, v_i4 = 0; //цикловые переменные для m_num
            
            while (m_str[v_i] != '\0' && v_flag){
                if (m_str[v_i] == ' ' && m_str[v_i + 1] == ' '){
                    v_flag = false;
                }
                
                if (v_count == 1) { //заполняем 1-й элемент
                    m_num1[v_i1] = m_str[v_i];
                    v_i1 ++;
                }
                else if (v_count == 2) { //заполняем 2-й элемент
                    m_num2[v_i2] = m_str[v_i];
                    v_i2 ++;
                }
                else if (v_count == 3) { //заполняем 3-й элемент
                    m_num3[v_i3] = m_str[v_i];
                    v_i3 ++;
                }
                else if (v_count == 4) { //заполняем 4-й элемент
                    m_num4[v_i4] = m_str[v_i];
                    v_i4 ++;
                }
                if (m_str[v_i] == ' '){ //идем дальше
                    v_count++;
                }
                v_i++;
                
            }
            
            if (v_count == 4){ // если в строке 4 числа
                t_mass m_result;
                m_result[0] = atof(m_num1); //записываем число в нормальном виде
                m_result[1] = atof(m_num2);
                m_result[2] = atof(m_num3);
                m_result[3] = atof(m_num4);
                
                fwrite(&m_result, sizeof(t_mass), 1, fout_bin);
                
            }
        }
    }
    fseek(fout_bin,0, SEEK_SET); //(указатель файла, кол-во байт, начало отсчет - seek_set - начало файла)
    return;
}

void f_change_row(FILE *&fout_bin, int v_m, int v_n){
    t_mass m_row1, m_row2;
    
    fseek(fout_bin, (v_m - 1) * sizeof(t_mass), SEEK_SET);
    fread(&m_row1, sizeof(t_mass),1, fout_bin);
    
    fseek(fout_bin, (v_n - 1) * sizeof(t_mass), SEEK_SET);
    fread(&m_row2, sizeof(t_mass),1, fout_bin);
    
    fseek(fout_bin, (v_m - 1) * sizeof(t_mass), SEEK_SET);
    fwrite(&m_row2, sizeof(t_mass), 1, fout_bin);
    
    fseek(fout_bin, (v_n - 1) * sizeof(t_mass), SEEK_SET);
    fwrite(&m_row1, sizeof(t_mass), 1, fout_bin);
    
    fseek(fout_bin, 0, SEEK_SET);
    
    return;
}

void f_print_bin(FILE *fout_bin){
    int v_check;
    t_mass m_result;
    while (!feof(fout_bin)){
        v_check = fread(&m_result, sizeof(t_mass), 1, fout_bin);
        if (v_check != 0){
            for (auto i: m_result){
                printf("%f ", i);
            }
            printf("\n");
        }
    }
    return;
}
