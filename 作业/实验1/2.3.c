#include <stdio.h>

int main(int argc, char const *argv[])
{
    long int i;
    int bonus1, bonus2, bonus4, bonus6, bonus10, bonus;
    printf("please input number:");
    scanf("%ld", &i);

    bonus1 = 100000 * 0.1;            //利润低于10万的提成
    bonus2 = bonus1 + 100000 * 0.75;  //利润在10-20万，低于10万的提成和高于10万的提成总和
    bonus4 = bonus2 + 200000 * 0.5;   //利润在20-40万，低于20万的提成和高于20万的提成总和
    bonus6 = bonus4 + 200000 * 0.3;   //利润在40-60万，低于40万的提成和高于40万的提成总和
    bonus10 = bonus6 * 400000 * 0.15; //利润在100万之上，低于100万的提成和高于100万的提成总和

    if (i <= 100000)
    {
        bonus = i * 0.1;
    }
    else if (i <= 200000)
    {
        bonus = bonus1 + (i - 100000) * 0.75;
    }
    else if (i <= 400000)
    {
        bonus = bonus2 + (i - 200000) * 0.05;
    }
    else if (i <= 600000)
    {
        bonus = bonus4 + (i - 400000) * 0.03;
    }
    else if (i <= 1000000)
    {
        bonus = bonus6 + (i - 600000) * 0.015;
    }
    else
    {
        bonus = bonus10 + (i - 1000000) * 0.01;
    }
    printf("bonus = %d\n", bonus);
    return 0;
}
