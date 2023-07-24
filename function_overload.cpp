#include <iostream>

int addition(int num_1, int num_2)
{
    return num_1 + num_2;
}

double addition(double num_1, double num_2)
{
    return num_1 + num_2;
}

int main(void)
{
    printf("int sum=%d\n", addition(5, 10));
    printf("double sum=%f\n", addition(6.5, 7.5));
    return 0;
}