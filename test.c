//
// Created by ivanbrekman on 25.08.2021.
//

#include <stdio.h>
#include <errno.h>
#include <math.h>

#include "test.h"
#include "solve_equation.h"

struct test_data {
    double a;
    double b;
    double c;

    double solve1;
    double solve2;
    int return_code;
    int error_code;
};

char * get_error_message(int error_code) {
    switch (error_code) {
        case 0: return "code: 0 (OK)";
        case -1: return "code: -1 (Access to NullPtr)";
        case -2: return "code: -2 (Not finite number in input)";
        default: return "Unknown error";
    }
}

void test(void) {
    struct test_data data[] = {
            {7,  1,        7,    0,  0,  NO_ROOTS,             OK },
            {1,  2,        1,   -1, -2,  ONE_ROOT,             OK },
            {2, -5,       -3, -0.5,  3, TWO_ROOTS,             OK },
            {0,  0,        0,    0,  0, INF_ROOTS,             OK },
            {1,  2, INFINITY,    0,  0,     ERROR, NULL_PTR_ERROR }
    };
    size_t n = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < n; i++) {
        double x1 = 0, x2 = 0;
        errno = OK;
        int return_code = solve_square_equation(data[i].a, data[i].b, data[i].c, &x1, &x2);

        printf("Test №%d: ", i + 1);
        if (x1 == data[i].solve1 && x2 == data[i].solve2 && return_code == data[i].return_code && errno == data[i].error_code) {
            printf("OK\n");
        } else {
            printf("Failed - expected: (%lf; %lf; %d) %s,\n                       got: (%lf; %lf, %d) %s\n",
                   data[i].solve1, data[i].solve2, data[i].return_code, get_error_message(data[i].error_code),
                   x1, x2, return_code, get_error_message(errno));
        }
    }

    printf("End of testing\n\n");
}
