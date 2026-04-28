#ifndef MODULESYROSLAV_H_INCLUDED
#define MODULESYROSLAV_H_INCLUDED

#include <string> // ОБОВ'ЯЗКОВО ДОДАТИ ЦЕЙ РЯДОК

// Модуль для лабораторної №8
double s_calculation(double x, double y, double z);

// Модуль для лабораторної №9
void task9_1(float salary, float experience, int& bonus_percent, float& total_payout);
const char* task9_2(int head_size);
int task9_3(unsigned int N);

// Задача 10
void task10_1(const std::string& inPath, const std::string& outPath);
void task10_2(const std::string& outPath);
void task10_3(const std::string& outPath, double x, double y, double z, int b);

#endif // MODULESYROSLAV_H_INCLUDED
