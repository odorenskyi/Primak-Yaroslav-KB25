#include <iostream>
#include <cmath>
#include <cassert>
#include <stdexcept>

#include "ModulesYroslav.h"

using namespace std;

bool isClose(double a, double b, double epsilon = 0.001) {
    return abs(a - b) < epsilon;
}

void runTestSuite() {
    cout << "=================================================" << endl;
    cout << " Запуск тестового драйвера для задачі 8.1" << endl;
    cout << " Модуль тестування: libModulesPrizvyshche" << endl;
    cout << "=================================================\n" << endl;

    assert(isClose(s_calculation(2, 3, 0), -20.5796));
    cout << "[OK] TC-01 Passed: Normal inputs (x=2, y=3)" << endl;

    bool errorCaught = false;
    try {
        s_calculation(1, 2, 0);
    }
    catch (const domain_error& e) {
        errorCaught = true;
    }
    assert(errorCaught == true);
    cout << "[OK] TC-02 Passed: Caught domain error correctly" << endl;

    const double PI = 3.141592653589793;
    assert(isClose(s_calculation(1, PI, 0), -30.0063));
    cout << "[OK] TC-03 Passed: Boundary value (y^x == pi)" << endl;

    double res_z1 = s_calculation(2, 3, 0);
    double res_z2 = s_calculation(2, 3, 999);
    assert(isClose(res_z1, res_z2));
    cout << "[OK] TC-04 Passed: Independence of z parameter verified" << endl;

    cout << "\n>>> УСІ ТЕСТИ УСПІШНО ПРОЙДЕНО! <<<" << endl;
}

int main() {
    setlocale(LC_ALL, "ukr");
    runTestSuite();

    return 0;
}
