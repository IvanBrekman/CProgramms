#include <stdio.h>
#include <math.h>

void solve_square_equation(double a, double b, double c);

int main(void)
{
    double a, b, c;

    printf("Введите 3 коэффициента квадратного уравнения (введите q для выхода)\n");
    while (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        printf("%.3lfx**2 + %.3lfx + %.3lf = 0\n", a, b, c);
        solve_square_equation(a, b, c);

        printf("\nВведите новые коэффициенты (или q для выхода)\n");
    }

    return 0;
}

void solve_square_equation(double a, double b, double c) {
    double d = b * b - 4 * a * c;

    if (d > 0) {
        double sqrt_d = sqrt(d);
        printf("Решения квадратного уравнения: %.3lf; %.3lf\n", (-b - sqrt_d) / (2 * a), (-b + sqrt_d) / (2 * a));
    }
    else if (d == 0){
        printf("Решение квадратного уравнения: %.3lf\n", -b / (2 * a));
    }
    else
        printf("У данного уравнения нет решений в действительных числах.\n");
}

