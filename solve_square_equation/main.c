#include <stdio.h>
#include "solve_equation.h"
#include "test.h"

int main(void)
{
    test();

    double a = 0, b = 0, c = 0;

    printf("Введите 3 коэффициента квадратного уравнения (введите q для выхода)\n");
    while (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        printf("%.3lfx**2 + %.3lfx + %.3lf = 0\n", a, b, c);

        double x1 = 0, x2 = 0;
        int n_answers = solve_square_equation(a, b, c, &x1, &x2);
        print_answers(n_answers, x1, x2);

        printf("\nВведите новые коэффициенты (или q для выхода)\n");
    }

    return 0;
}

