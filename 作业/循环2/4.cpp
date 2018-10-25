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
	int in = 0;
	cout << "enter a sum: " << endl;
	cin >> in;
	if (isPrime(in) == 1)
		cout << in << " is Prime" << endl;

	else
		cout << in << " not is Prime" << endl;

	return 0;
}
