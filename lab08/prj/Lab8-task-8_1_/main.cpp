#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;
double calculateS(double x, double y) {
const double PI = 3.141592653589793;
double y_pow_x = pow(y, x);
if (y_pow_x < PI) {
        throw domain_error("Помилка ОДЗ: підкореневий вираз (y^x - pi) менший за нуль!");
    }
double term1 = pow(x, 2);
double term2 = pow(y, 3);
double term3 = sqrt(y_pow_x - PI);
return term1 - term2 + term3;
}
int main() {
    setlocale(LC_ALL, "ukr");
double x, y, z;
cout << "--- Розв'язання задачі 8.1 ---" << endl;
cout << "Введіть значення x: ";
cin >> x;
cout << "Введіть значення y: ";
cin >> y;
cout << "Введіть значення z: ";
cin >> z;
try {
        double resultS = calculateS(x, y);
        cout << "\nРезультат обчислення функції S = " << resultS << endl;
    }
    catch (const domain_error& e) {
        cerr << "\n" << e.what() << endl;
        cerr << "Обчислення для введених значень неможливе." << endl;
    }
return 0;
}
