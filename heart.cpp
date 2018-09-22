
#include<iostream>
#include<cmath>
using namespace std;

#define  WIDTH   1.5
#define  HEIGHT  1.5

int main(int argc, char **argv)
{
    for (float y = HEIGHT; y >= -HEIGHT; y -= 0.06)
    {
        for (float x = -WIDTH; x <= WIDTH; x += 0.025)
        {
            if (x*x + pow(5.0*y/4.0 - sqrt(fabs(x)), 2) - 1 <= 0.0)
            {
                cout<<" ";
            }
            else
            {
                cout<<"*";
            }
        }
        cout<<endl;
    }

    return 0;
}

