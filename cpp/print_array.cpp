#include <iostream>

void print_array(int myArray[5], int array_length)
{
    for (int i=0; i<array_length; i++)
    {
        printf("myArray[%d]=%d \n", i, myArray[i]);
    }
}

void print_array_v2(int* myArray, int array_length)
{
    for (int i=0; i<array_length; i++)
    {
        printf("myArray[%d]=%d \n", i, myArray[i]);
    }

}

int main(void)
{
    int myArray[5] = {10, 20, 30, 40, 50};

    printf("sizeof(myArray)=%ld \n",sizeof(myArray));
    printf("sizeof(myArray[0])=%ld \n",sizeof(myArray[0]));

    int array_length = sizeof(myArray)/sizeof(myArray[0]);
    printf("array_length=%d \n", array_length);

    printf("\n");
    print_array(myArray, array_length);
    printf("\n");
    print_array_v2(myArray, array_length);

    return 0;
}