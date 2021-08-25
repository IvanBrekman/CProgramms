#include <stdio.h>

#define SIZE 1000000

void get_strongly_composite_numbers(int number);
int get_sum_of_min_delimiters(int number);

int main(void)
{
    int end_num;
    scanf("%d", &end_num);

    printf("%d", get_sum_of_min_delimiters(end_num + 1));

    return 0;
}

void get_strongly_composite_numbers(int number) {
    int sieve[SIZE];
    for (int i = 0; i < number; i++) sieve[i] = 0;

    for (int i = 2; i < number; i++) {
        if (sieve[i] != 0) continue;

        for (int j = i; j < number; j += i)
            sieve[j] += 1;
    }

    for (int i = 0; i < number; i++) {
        if (sieve[i] >= 3) printf("%d ", i);
    }
}

int get_sum_of_min_delimiters(int number) {
    int sieve[SIZE];
    for (int i = 0; i < number; i++) sieve[i] = 0;

    for (int i = 2; i < number; i++) {
        if (sieve[i] != 0) continue;

        for (int j = i; j < number; j += i)
            if (sieve[j] == 0)
                sieve[j] = i;
    }

    int sum = 0;
    for (int i = 0; i < number; i++) {
        sum += sieve[i];
    }

    return sum;
}

