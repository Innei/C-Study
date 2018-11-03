#include <iostream>
#include <math.h>
using namespace std;

int fn(int a, int n)
{

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = a * pow(10, i) + res;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int a, n, res = 0;

    cout << "输入两个正整数:" << endl;
    cin >> a >> n;
    for (int i = 1; i <= n; i++)
    {
        res = fn(a, i) + res;
    }
    cout << res << endl;
  
    return 0;
}
