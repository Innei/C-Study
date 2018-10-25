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
    int a = 0, b = 0, count = 0;
    cout << "Enter two numbers:" << endl;
    cin >> a >> b;

    for (int i = a; i <= b; i++)
    {

        if (isPrime(i) == 1)
        {
            cout << i << '\t';
            count++;

            if (count == 4)
            {
                cout << endl;
                count = 0;
            }
        }

        else
        {
            continue;
        }
    }

    return 0;
}
