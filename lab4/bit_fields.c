#include <stdio.h>
#include <stdlib.h>                                         //cmake-build-debug\bit_fields.exe

typedef struct bit_field {
    unsigned int last_bit: 1;
} bit_field;

int input_int() {
    char c;
    int num, input = scanf("%d", &num);
    if (input == 0 || (c = getchar()) != '\n' || (int) input != input) {
        printf("Incorrect input. Try again. \n");
        rewind(stdin);
    } else
        return num;
}

int pow_two(int num) {
    int check = 1;
    while (check < num)
        check *= 2;
    if (check == num)
        return 1;
    return 0;
}

void bit_remains(int argc, char *argv[]) {
    if (argc != 3)
        exit(-1);

    int divisible = atoi(argv[1]), divisor = atoi(argv[2]), remains = 0;

    while (divisible < 0) {
        printf("Enter the divisible again\n");
        divisible = input_int();
    }
    while (!pow_two(divisor)) {
        printf("Enter the divider being the power of two again\n");
        divisor = input_int();
    }

    bit_field *pointer;

    for (int i = 1; i != divisor; i *= 2) {
        pointer = (bit_field *) &divisible;
        if (pointer->last_bit)
            remains += 1 * i;
        else
            remains += 0 * i;
        divisible /= 2;
    }

    printf("Result: %d \n", remains);
}

int main(int argc, char *argv[]) {
    bit_remains(argc, argv);
    return 0;
}
