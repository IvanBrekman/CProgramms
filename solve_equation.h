//
// Created by ivanbrekman on 25.08.2021.
//

#include <stdbool.h>

enum sq_return { ERROR = -2, INF_ROOTS = -1, NO_ROOTS = 0, ONE_ROOT = 1, TWO_ROOTS = 2 };
enum sq_errors { OK = 0, NULL_PTR_ERROR = -1, NOT_FINITE_NUMBER_ERROR = -2 };

int solve_square_equation(double a, double b, double c, double* solve1, double* solve2);
int solve_linear_equation(double a, double b, double* solve1);
bool is_zero(double n);
void print_answers(int n_answers, double solve1, double solve2);

