#include <iostream>
#include <stdexcept>
#include "ModulesYroslav.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "ukr");

    char choice;
    char exit_choice;

    //цикл програми
    do {
        cout << " e - Обчислити функцію s_calculation (Задача 8.1)" << endl;
        cout << " r - Розрахувати надбавку за стаж (Задача 9.1)" << endl;
        cout << " f - Визначити розмір шолома (Задача 9.2)" << endl;
        cout << " t - Підрахувати біти (Задача 9.3)" << endl;
        cout << "Введіть символ для вибору дії: ";
        cin >> choice;

        // Обробка вибору
        switch (choice) {
            case 'e': {
                double x, y, z;
                cout << "Задача 8.1" << endl;
                cout << "Введіть x: "; cin >> x;
                cout << "Введіть y: "; cin >> y;
                cout << "Введіть z: "; cin >> z;

                try {
                    // Виклик функції з 8 лаби
                    double s = s_calculation(x, y, z);
                    cout << "Результат обчислення S = " << s << endl;
                } catch (const exception& ex) {
                    cout << "Помилка ОДЗ: " << ex.what() << endl;
                }
                break;
            }
            case 'r': {
                float salary, experience;
                int bonus_percent = 0;
                float total_payout = 0.0f;

                cout << "\Задача 9.1" << endl;
                cout << "Введіть розмір заробітної плати (грн): "; cin >> salary;
                cout << "Введіть стаж роботи (років): "; cin >> experience;

                // Виклик функції 9.1
                task9_1(salary, experience, bonus_percent, total_payout);

                cout << "Надбавка складе: " << bonus_percent << "%" << endl;
                cout << "Сума до виплати: " << total_payout << " грн" << endl;
                break;
            }
            case 'f': {
                int head_size;
                cout << "\Задача 9.2" << endl;
                cout << "Введіть обхват голови у см (від 53 до 62): "; cin >> head_size;

                // Виклик функції 9.2
                cout << "Рекомендований розмір шолома: " << task9_2(head_size) << endl;
                break;
            }
            case 't': {
                unsigned int n;
                cout << "\Задача 9.3" << endl;
                cout << "Введіть натуральне число N (0 - 40008050): "; cin >> n;

                // Виклик функції 9.3
                cout << "Кількість знайдених бітів: " << task9_3(n) << endl;
                break;
            }
            default: {
                // Відтворення звукового сигналу
                cout << "\a";
                cout << "\nПомилка: Введено невідомий символ! Будь ласка, оберіть літеру з меню." << endl;
                break;
            }
        }

        //завершення програми
        cout << "\nЧи бажаєте завершити роботу програми?" << endl;
        cout << "(Введіть 'g', 'G' або 'o' для виходу, будь-який інший символ - для продовження): ";
        cin >> exit_choice;

        if (exit_choice == 'g' || exit_choice == 'G' || exit_choice == 'o') {
            cout << "Програму завершено. До побачення!" << endl;
            break;
        }

    } while (true);

    return 0;
}
