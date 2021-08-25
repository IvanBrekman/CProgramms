#include <stdio.h>

int get_digits(int number) {
    int digits = 0;

    while (number > 0){
        digits += 1;
        number /= 10;
    }

    return digits;
}

int power(int number, int degree) {
    int num = 1;

    for (int i = 0; i < degree; i++)
        num *= number;

    return num;
}

int main(void)
{
    int lower_bound, upper_bound;

    printf("Выберите нижний и верхние границы таблицы\n");
    scanf("%d %d", &lower_bound, &upper_bound);

    int max_digits = get_digits(power(upper_bound, 3)) + 1;
    printf("%-*s %-*s %-*s \n", max_digits, "n^1", max_digits, "n^2", max_digits, "n^3");

    for (int number = lower_bound; number <= upper_bound; number++)
        printf(" %-*d %-*d %-*d \n", max_digits, number, max_digits, power(number, 2), max_digits, power(number, 3));

    return 0;
}

