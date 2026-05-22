#include <iostream>
#include <Windows.h>
#include "struct_type_project_4.h"
#include "Modules_Primak.h"
#include "Modules_Bureiko.h"
#include "Modules_Rudenko.h"

using namespace std;

int main() {
    // Налаштування кодування консолі для Windows-1251 (відповідно до реалізації то_lower_ua у Primak)
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Ініціалізація покажчика на початок динамічного списку (нашої бази даних)
    RouteNode* database_head = nullptr;
    const char* db_filename = "schedule.dat";

    // Автоматичне завантаження ІС з бінарного файлу під час запуску програми
    load_from_binary(database_head, db_filename);

    int choice;
    char search_buffer[100];
    char delete_buffer[15];

    do {
        cout << "1. Вивести весь розклад руху автобусів\n";
        cout << "2. Пошук рейсів за назвою автостанції\n";
        cout << "3. Додати новий рейс до ІС\n";
        cout << "4. Вилучити заданий рейс із ІС за номером\n";
        cout << "5. Завершити роботу програми\n";
        cout << "Ваш вибір: ";

        if (!(cin >> choice)) {
            cout << ">>> Помилка введення! Очікується число.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                print_schedule(database_head);
                break;
            case 2:
                cout << "Введіть назву автостанції для пошуку: ";
                cin >> ws;
                cin.getline(search_buffer, 100);
                search_route(database_head, search_buffer);
                break;
            case 3:
                add_route(database_head);
                break;
            case 4:
                cout << "Введіть номер рейсу для вилучення: ";
                cin >> ws;
                cin.getline(delete_buffer, 15);
                delete_route(database_head, delete_buffer);
                break;
            case 5:
                cout << "\n>>> Завершення роботи... Запуск процесів персистентності.\n";
                break;
            default:
                cout << ">>> Некоректний пункт меню. Спробуйте ще раз.\n";
        }
    } while (choice != 5);

    save_to_binary(database_head, db_filename);

    cout << ">>> Програма успішно зберегла дані та завершила роботу.\n";
    return 0;
}
