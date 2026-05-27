#ifndef MODULESPRIMAK_H
#define MODULESPRIMAK_H

#include <cmath>
#include <stdexcept>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Клас Кулі
class ClassLab12_Primak {
private:
    double radius; // інкапсуляція

public:
    ClassLab12_Primak(double r = 1.0);   // Конструктор
    void setRadius(double r);            // Сетер
    double getRadius() const;            // Гетер
    double calculateSurfaceArea() const; // Метод обчислення площі
};

// Реалізація методів ПОЗА тілом класу з inline
inline ClassLab12_Primak::ClassLab12_Primak(double r) { // Виправлено: прибрано зайвий пробіл перед ::
    setRadius(r);
}

inline void ClassLab12_Primak::setRadius(double r) {
    if (r <= 0.0) {
        throw std::invalid_argument("Радіус має бути більшим за 0!");
    }
    this->radius = r;
}

inline double ClassLab12_Primak::getRadius() const {
    return this->radius;
}

inline double ClassLab12_Primak::calculateSurfaceArea() const {
    return 4.0 * M_PI * std::pow(this->radius, 2);
}

#endif
