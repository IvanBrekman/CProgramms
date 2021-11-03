//
// Created by ivanbrekman on 25.08.2021.
//

#define NDEBUG
#include <assert.h>

#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>
#include <errno.h>

#include "solve_equation.h"

const double PRECISION = 0.000001;

/* !
 * Функция решает квадратное уравнение и записывает ответы в указанные переменные
 * @param: a: Коэффициент при x**2
 * @param: b: Коэффициент при x
 * @param: c: Свободный коэффициент
 * @param: solve1: Указатель на переменную, куда будет записан 1 ответ (Если уравнение имеет 1 ответ, то он будет скопирован в solve2)
 * @param: solve2: Указатель на переменную, куда будет записан 2 ответ
 * return: Количество найденных корней (при бесконечном количестве решений вернет -1)
 * Warning! Если решений уравнения нет или их бесконечно много, то в переменные для ответа ничего не будет записано
 */
int solve_square_equation(double a, double b, double c, double* solve1, double* solve2) {
    assert(isfinite(a) && isfinite(b) && isfinite(c));
    assert(solve1 != NULL && solve2 != NULL);

    if (!(isfinite(a) && isfinite(b) && isfinite(c))) {
        errno = NOT_FINITE_NUMBER_ERROR;
        return ERROR;
    }

    if (!(solve1 != NULL && solve2 != NULL)) {
        errno = NULL_PTR_ERROR;
        return ERROR;
    }

    if (is_zero(a)) {
        int n_answers = solve_linear_equation(b, c, solve1);
        *solve2 = *solve1;
        return n_answers;
    }

    double discriminant = b * b - 4 * a * c;
    if (!isfinite(discriminant)) {
        errno = NOT_FINITE_NUMBER_ERROR;
        return ERROR;
    }

    if (is_zero(discriminant)) {
        *solve1 = *solve2 = -b / (2 * a);
        return ONE_ROOT;
    }

    if (discriminant < 0){
        return NO_ROOTS;
    }

    double sqrt_d = sqrt(discriminant);
    *solve1 = (-b - sqrt_d) / (2 * a);
    *solve2 = (-b + sqrt_d) / (2 * a);
    return TWO_ROOTS;
}

/* !
 * Функция решает линейное уравнение и записывает ответ в указанные переменные
 * @param: a: Коэффициент при x
 * @param: b: Свободный коэффициент
 * @param: solve1: Указатель на переменную, куда будет записан ответ
 * return: Количество найденных корней (при бесконечном количестве решений вернет -1)
 * Warning! Если решений уравнения нет или их бесконечно много, то в переменную для ответа ничего не будет записано
 */
int solve_linear_equation(double a, double b, double* solve1) {
    assert(isfinite(a) && isfinite(b));
    assert(solve1 != NULL);

    if (!(isfinite(a) && isfinite(b))) {
        errno = NOT_FINITE_NUMBER_ERROR;
        return ERROR;
    }
    if (solve1 == NULL) {
        errno = NULL_PTR_ERROR;
        return ERROR;
    }

    if (is_zero(a)) {
        return is_zero(b) ? INF_ROOTS : NO_ROOTS;
    }
    *solve1 = -b / a;
    return ONE_ROOT;
}

/*
 * Функция выводит на печать решения уравнения
 * @param: n_answers: Количество решений
 * @param: solve1: 1 решение
 * @param: solve2: 2 решение
 */
void print_answers(int n_answers, double solve1, double solve2) {
    switch (n_answers) {
        case INF_ROOTS:
            printf("Бесконечно много решений\n");
            break;
        case NO_ROOTS:
            printf("Нет решений\n");
            break;
        case ONE_ROOT:
            printf("x = %lf\n", solve1);
            break;
        case TWO_ROOTS:
            printf("x = %lf; %lf\n", solve1, solve2);
            break;
        default:
            assert(0);
    }
}

/*
 * Функция проверяет число на равенство с 0, учитывая погрешность операций с double
 * @param: n: Проверяемое число
 * return: true, если число равно 0 (с учетом погрешности), иначе false
 */
bool is_zero(double n) {
    return fabs(n) < PRECISION;
}
