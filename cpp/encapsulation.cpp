#include <iostream>

class Numbers
{
    public:
        int get_number();
        void set_number(int new_value);

    private:
        int number = 0;
};

// Getter Function
int Numbers::get_number()
{
    return number;
}

// Setter Function
void Numbers::set_number(int new_value)
{
    number = new_value;
}

int main(void)
{
    Numbers myNumber; 

    printf("myNumber.get_number() = %d \n", myNumber.get_number());
    myNumber.set_number(10);
    printf("myNumber.get_number() = %d \n", myNumber.get_number());
    myNumber.set_number(500);
    printf("myNumber.get_number() = %d \n", myNumber.get_number());

    return 0;
}