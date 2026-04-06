#include <cmath>
#include <stdexcept>

using namespace std;


double s_calculation(double x, double y, double z) {
    const double PI = 3.141592653589793;
    double y_pow_x = pow(y, x);


    if (y_pow_x < PI) {
        throw domain_error("Помилка ОДЗ: підкореневий вираз менший за нуль");
    }


    double term1 = pow(x, 2);
    double term2 = pow(y, 3);
    double term3 = sqrt(y_pow_x - PI);

    return term1 - term2 + term3;
}
