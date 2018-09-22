#include<iostream>
#include<cmath>
using namespace std;

#define  WIDTH   1.5
#define  HEIGHT  1.5


int main(int argc, char const *argv[])
{

	float V = 0.0;
	for (float y = HEIGHT; y >= -HEIGHT; y -= 0.08)
	{
		cout << '%';
		for (float x = -WIDTH; x <= WIDTH; x += 0.04)
		{

			if (x * x + pow(5.0 * y / 4.0 - sqrt(fabs(x)), 2) - 1 <= 0.3)
			{
				cout << '$';

			}
			else
				cout << ' ';



		}
		//cout << '@' << endl;
		V = y;
		cout << endl;

	}
	//cout << V;

	for (int i = 0; i < 30000000000; ++i)
	{
		cout << '\b';
	}
	for (int i = 0; i < 30; ++i)
	{
		cout << "%\ ";
	     }

		     /*
		     if (V < -HEIGHT)
	     {
		     cout << '^';
	     }
		     */
		     return 0;
	     }

