#include <stdio.h>

void draw_pyromid(char start_symbol, char end_symbol, int reflection);

int main(void)
{
    char start_symbol, end_symbol;
    int need_reflection;
    
    while (start_symbol != '#' || end_symbol != '#') {
        printf("Выберите стартовый и конечный символы\n");
        scanf("%c %c", &start_symbol, &end_symbol);
    
        printf("Отражать пирамиду зеркально вниз?\nВведите 1, если да, иначе 0\n");
        scanf("%d", &need_reflection);

        draw_pyromid(start_symbol, end_symbol, need_reflection);
    }

    return 0;
}

void draw_pyromid(char start_symbol, char end_symbol, int reflection) {
    if (start_symbol > end_symbol) {
    	printf("Некорректно заданы символы: Стартовый символ позже Конечного\n");
    	return;
    }
    
    int pyr_height = (int)end_symbol - (int)start_symbol + 1;
    int continue_building = 1, upper_build = 1, lower_build = 0;
    int h = 0;

    while (continue_building) {
        char symbol = start_symbol;

        for (int spaces = 0; spaces < pyr_height - h - 1; spaces++)
            printf(" ");

        int symbols_shift = h - 1;
        while (symbols_shift-- >= 0)
            printf("%c", symbol++);

        while (symbols_shift++ < h - 1)
            printf("%c", symbol--);

        printf("\n");
        
        if (upper_build && h < pyr_height) h++;
        if (upper_build && h == pyr_height) {
            upper_build = 0;
            lower_build = 1;
            h--;
        }
        if (lower_build && h >= 0) h--;
        if (lower_build && h < 0) continue_building = 0;
        
        if (lower_build && !reflection) continue_building = 0;
    }
}

