#include <iostream>
#include <math.h>
using namespace std;
int isPrime(int n)
{

    if (n < 2)
        return 0;

    for (int i = 2; i <= (int)sqrt((double)n); i++)
    {

        if (n % i == 0)
            return 0;
    }

    return 1;
}
int main(int argc, char const *argv[])
{

    double m = 0;

    for (int i = 1; i < 20; i++)
    {
        m = pow(2, i) -1;
        if (isPrime(m) == 1)
        {
            cout << m << '\t';
        }
    }

    return 0;
}
