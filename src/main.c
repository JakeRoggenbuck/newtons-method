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

double newtons_method(double (*func)(double), double n) {
    // Question... where does func(x) = n?
    // func(x) - n = 0
    double f(double x) { return func(x) - n; }

	// initial arbitrary guess
    double guess = 0.5;
    printf("Guess for func(x) - %.2lf = 0\n", n);
    printf("%lf\n", guess);

    for (int i = 0; i < 7; ++i) {
        // update guess for next iteration
        // x_1 = x_0 - f(x_0) / f'(x_0)
        // (x_n+1) = x_n - f(x_n) / f'(x_n)
        guess = guess - (f(guess) / derivative(f, guess));
        printf("%lf\n", guess);
    }
}

int main() {
    newtons_method(g, 6);
    newtons_method(g, 10);
    return 0;
}
