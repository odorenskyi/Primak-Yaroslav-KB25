#include <iostream>
#include <iomanip>
#include <string>
#include "ModulesYroslav.h"

using namespace std;

void test_task9_1() {
    cout << "Тестування Задачі 9.1" << endl;
    // Масиви з тестовими даними (3 перевірки)
    float salaries[] = {10000.0f, 10000.0f, 20000.0f};
    float experiences[] = {1.5f, 5.0f, 15.0f};
    int expected_bonuses[] = {0, 10, 25};
    float expected_totals[] = {10000.0f, 11000.0f, 25000.0f};

    for (int i = 0; i < 3; i++) {
        int actual_bonus = 0;
        float actual_total = 0.0f;

        // Виклик функції з бібліотеки
        task9_1(salaries[i], experiences[i], actual_bonus, actual_total);

        cout << "Тест " << i + 1 << " (Стаж: " << experiences[i] << " р.): ";
        if (actual_bonus == expected_bonuses[i] && actual_total == expected_totals[i]) {
            cout << "PASSED" << endl;
        } else {
            cout << "FAILED! Очікувано: " << expected_bonuses[i] << "%, " << expected_totals[i]
                 << " | Фактично: " << actual_bonus << "%, " << actual_total << endl;
        }
    }
    cout << endl;
}

void test_task9_2() {
    cout << "Тестування Задачі 9.2 (Розмір шолома)" << endl;
    // Тестові дані: межі діапазону та середина
    int head_sizes[] = {53, 57, 62, 100};
    string expected_sizes[] = {"XS", "M", "XL", "Помилка: Поза діапазоном"};

    for (int i = 0; i < 4; i++) {
        string actual_size = task9_2(head_sizes[i]); // Виклик функції

        cout << "Тест " << i + 1 << " (Обхват: " << head_sizes[i] << " см): ";
        if (actual_size == expected_sizes[i]) {
            cout << "PASSED" << endl;
        } else {
            cout << "FAILED! Очікувано: " << expected_sizes[i] << " | Фактично: " << actual_size << endl;
        }
    }
    cout << endl;
}

void test_task9_3() {
    cout << "Тестування Задачі 9.3 (Підрахунок бітів)" << endl;
    // Тестові дані
    unsigned int n_values[] = {7, 32768, 32771};
    int expected_counts[] = {3, 31, 29}; // Очікувані результати з нашої таблиці

    for (int i = 0; i < 3; i++) {
        int actual_count = task9_3(n_values[i]); // Виклик функції

        cout << "Тест " << i + 1 << " (Число: " << n_values[i] << "): ";
        if (actual_count == expected_counts[i]) {
            cout << "PASSED" << endl;
        } else {
            cout << "FAILED! Очікувано: " << expected_counts[i] << " | Фактично: " << actual_count << endl;
        }
    }
    cout << endl;
}

int main() {
    // Встановлюємо українську мову для консолі
    setlocale(LC_ALL, "ukr");

    cout << "Запуск модульного тестування функцій..." << endl << endl;

    // Запускаємо тестування кожної функції
    test_task9_1();
    test_task9_2();
    test_task9_3();

    cout << "Тестування завершено." << endl;
    return 0;
}
