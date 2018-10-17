#include <stdio.h>

int main(int argc, char const *argv[])
{
    int salary = 0;
    float rate = 0.0;
    printf("Enter the salary:\n");
    scanf("%d", &salary);

    if (salary <= 850)
        rate = 0.0;
    else if (salary <= 1350)
        rate = 0.05;
    else if (salary <= 2850)
        rate = 0.1;
    else if (salary <= 5850)
        rate = 0.15;
    else
        rate = 0.2;
    printf("tax = %.2f\n", rate * (salary - 850.0));
    return 0;
}
