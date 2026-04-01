#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>


#include "ModulesYroslav.h"

using namespace std;

// Підзадача 8.2.1
string getAuthorInfo() {

    return "Прімак Ярослав";
}


// Підзадача 8.2.2


bool evaluateLogic(char a, char b) {
    return a <= (b - 32);
}


// Підзадача 8.2.3

string formatDataAndCalculateS(double x, double y, double z) {
    ostringstream out;


    out << "Значення (DEC): x = " << dec << x
        << ", y = " << y
        << ", z = " << z << "\n";


    out << "Значення (HEX): x = " << hex << uppercase << (int)x
        << ", y = " << (int)y
        << ", z = " << (int)z << dec << "\n";


    try {
        double s_result = s_calculation(x, y, z);
        out << "Результат обчислення S = " << s_result;
    } catch (const exception& e) {

        out << "Результат обчислення S = ПОМИЛКА (" << e.what() << ")";
    }

    return out.str();
}


// головна функція

int main() {

    setlocale(LC_ALL, "ukr");

    double x, y, z;
    char a, b;

    cout << "--- Запуск програми (Задача 8.2) ---\n\n";


    cout << "Введіть число x: "; cin >> x;
    cout << "Введіть число y: "; cin >> y;
    cout << "Введіть число z: "; cin >> z;

    cout << "Введіть символ a: "; cin >> a;
    cout << "Введіть символ b: "; cin >> b;

    cout << "\n---------------- РЕЗУЛЬТАТИ ----------------\n\n";

    cout << "8.2.1. Розробник: " << getAuthorInfo() << "\n\n";

    cout << "8.2.2. Результат виразу (a <= b - 32): " << evaluateLogic(a, b) << "\n\n";

    cout << "8.2.3. Дані та функція S:\n" << formatDataAndCalculateS(x, y, z) << "\n";

    cout << "\n--------------------------------------------\n";

    return 0;
}
