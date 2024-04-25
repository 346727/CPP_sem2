#include <iostream>
#include <cmath>

double funA(double x) {
    return cos(x) - x;
}

double funB(double x) {
    return cos(x) - 0.5;
}

double findRoot(double (*f)(double), double a, double b, double tolerance = 1e-10) {
    try {
        if (f(a) * f(b) < 0) {
            if (f((a + b) / 2) != 0) {
                double x;
                while (fabs(a - b) > tolerance) {
                    x = (a + b) / 2;
                    if (f(a) * f(x) < 0)
                        b = x;
                    else
                        a = x;
                }
                return x;
            } else {
                return (a + b) / 2;
            }
        } else {
            throw "Nieprawidłowe granice";
        }
    } catch (const char* err) {
        if (std::string(err) == "Nieprawidłowe granice")
            std::cout << "Wartości funkcji na końcach przedziału muszą mieć przeciwne znaki.\n";
        return 0.0;
    }
}

int main() {
    std::cout << "Produkt funA: " << findRoot(&funA, 0, 2, 1e-6) << std::endl;
    std::cout << "Produkt funB: " << findRoot(&funB, 0, 1.5, 1e-6) << std::endl;

    return 0;
}
