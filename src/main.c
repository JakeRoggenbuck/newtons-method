#include <math.h>
#include <stdio.h>

#define H 0.000000001

double f(double x) {
    // f(x) = 3x^2 - x^7 - 4x^3
    return 3 * pow(x, 2) - pow(x, 7) - 4 * pow(x, 3);
}

double g(double x) {
    // g(x) = x^2 - 3x - 5
    return (x * x) - (3.0 * x) - 5.0;
}

double derivative(double (*func)(double), double x) {
    // the difference in y
	// f(x + H) - f(x)
    double dy = (func((double)x + H) - func(x));
    // dy/dx at x
    return dy / H;
}

int main() {
    double a = g(2);
    double ap = derivative(g, 2);

    printf("a = %.2lf, ap = %.2lf\n", a, ap);
    return 0;
}
