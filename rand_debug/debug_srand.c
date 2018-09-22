#include <iostream>
using namespace std;
#include   <stdlib.h>
#include   <time.h>
#define MIN 0    //随机数产生的范围      
#define MAX 99

int main()
{
    int i;
    srand((unsigned)time(NULL));
    cout << "Ten random numbers from " << MIN <<
         " to " << MAX << " :\n" << endl;
    cout << rand() << endl;

    for (i = 0; i < 10; i++)     //产生随机数
    {
        cout << MIN + rand() % (MAX + MIN - 1) << "\t";
    }
    cout << endl;
    return   0;
}