#ifndef MODULESPRIMAK_H
#define MODULESPRIMAK_H

#include <cmath>
#include <stdexcept>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class ClassLab12_Primak {
private:
    double radius;

public:
    ClassLab12_Primak(double r = 1.0);
    void setRadius(double r);
    double getRadius() const;
    double calculateSurfaceArea() const;
};

inline ClassLab12_Primak::ClassLab12_Primak(double r) {
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
