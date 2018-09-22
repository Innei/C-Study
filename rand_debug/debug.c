#include<stdio.h>
#include<stdlib.h>
int i = 1;
#define RAND_MAX 10
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	while (1) {
		printf("%d = %d\n", i, rand());
		i ++;
		system("sleep 1");

	}
	return 0;
}