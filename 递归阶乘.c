#include<stdio.h>

int main(int argc, char const *argv[])
{

	int input = 0;
	double total = 0;
	printf("please enter a number..\n");
	while (scanf("%d", &input) == 1)
	{
		if (input > 170)
		{
			/* code */continue;
		}
		else if (input <= 0)
		{
			continue;
		}
		//适当用用goto吧 太难搞了...qaq

		int sumdown = input;
		int count = input;
		double total = input;
		for (int i = 1; i < count; i++)
		{
			sumdown--;
			total = total * sumdown;


		}
		printf("%f\n", total );
	}
	return 0;
}
int fac(int sum)  //递归实现 函数原型
{
	if (sum == 1)
		return 1;
	else
		return sum * fac(sum - 1);

}