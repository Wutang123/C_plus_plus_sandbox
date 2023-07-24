#include <iostream>

void swap_numbers(int &num_1, int &num_2)
{
    int temp;

    temp = num_1;
    num_1 = num_2;
    num_2 = temp;
}

int main(void)
{
    int num_1 = 10;
    int num_2 = 20;

    printf("Original Values: num_1=%d, num_2=%d \n", num_1, num_2);

    swap_numbers(num_1, num_2);

    printf("New Values: num_1=%d, num_2=%d \n", num_1, num_2);

    return 0;
}