#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;

int i = 1;
int main(int argc, char const *argv[])
{
	srand(time(0));
	unsigned int MAX = pow(2, 20);
	while (i < 10)
	{
		cout << rand() % MAX << "\t";
		i ++;

	}
	return 0;
}