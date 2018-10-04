#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
using namespace std;
bool isdigits(char c)
{ //判断字符是否是数字
    if (c < '9' && c > '0')
        return true;
    else
        return false;
}

int solve(string s)
{
    if (s.size() == 0)
        return 0;
    int sum = 0, count = 0, sum_part = 0;
    bool isdigit = false; //判断是否有数字存在
    int i = 0;
    while (i < s.size())
    {
        isdigit = false;
        while (i < s.size() && s[i] == '-')
        { //累计符号的数量
            count++;
            i++;
        }
        while (i < s.size() && isdigits(s[i]))
        { //若是数字，则统计局部和
            isdigit = true;
            sum_part = sum_part * 10 + (s[i] - '0');
            i++;
        }
        if (isdigit)
        { //若前面是数字，则将其加到总和上去
            if (count % 2 == 1)
                sum_part *= -1;
            sum += sum_part;
            sum_part = 0;
        }
        count = 0;
        ++i;
    }
    return sum;
}

// char *join3(char *s1, char *s2)
// {
//     char *result = malloc(strlen(s1) + strlen(s2) + 1); //+1 for the zero-terminator
//     //in real code you would check for errors in malloc here
//     if (result == NULL)
//         exit(1);

//     strcpy(result, s1);
//     strcat(result, s2);

//     return result;
// }
int ten(int i)
{
    int result = 1;
    for (int a = 1; a <= i; a++)
    {
        result = result * 10;
    }
    return result;
}
int main(int argc, char const *argv[])
{
    char input[20] = "20+30x=8+2x";
    //char input[10] = "1x+1=2x";
    //scanf("%s", &input);

    //  short int siglter = 0;
    // printf("%s\n", input);
    //printf("%d", len);
    char temp[4];
    int len = strlen(input);
    //char *input = &input;
    int allNum = solve(input);
    int start_count = 0;
    int end_count = -1;
    int x_totalNum;
    short x_Num = 0;
    double result = 0.0;
    float Num = 0.0;
    //int transform_Num = input[start_count] - '0';
    int transform_Num = 0;
    //printf("%d\n", transform_Num);
    // printf("%c\n", *input);
    for (int count = 0; len > count; count++)
    {
        if (isdigit(input[count]) == 1)
        {
            allNum = allNum + (input[count] - '0');
        }

        if (*(input + count) == 'x')
        {
            for (int i = count - 1; i >= 0; i--)
            {
                if (isdigit(input[0]) == 1)
                    x_totalNum = input[0] - '0';

                else

                    x_totalNum = 0;
                if (isdigit((input[i])) == 1)
                {
                    for (int a = i; a > 0; a--)
                    {
                        cout << i << endl; //20+3x=8
                        cout << a << endl;
                        if (input[a] == '+' || input[a] == '-')
                            break;
                        transform_Num = transform_Num + (input[a] - '0') * ten(i - a);
                        cout << "transform_Num = " << transform_Num << endl;
                    }
                    for (int k = i; k >= 0; k--) //判断加减号
                    {
                        if (input[k] == '+')
                        {
                            x_totalNum = x_totalNum + transform_Num;
                            x_Num = x_totalNum;
                            transform_Num = 0;
                            //    printf("x_totalNum = %d\n", x_totalNum);
                        }
                        else if (input[k] == '-')
                        {
                            x_totalNum = x_totalNum - transform_Num;
                            x_Num = x_totalNum;
                            transform_Num = 0;
                            //      printf("x_totalNum = %d\n", x_totalNum);
                        }

                        else if (input[k] == '=') // 判断等好位置.系数移动到一遍
                        {
                            for (int j = k; j < len; j++)
                                if (input[j] == '+')
                                {
                                    x_totalNum = x_totalNum - transform_Num;
                                    x_Num = x_totalNum + transform_Num;
                                    transform_Num = 0;
                                    //  printf("x_totalNum = %d\n", x_totalNum);
                                }
                                else if (input[j] == '-')
                                {
                                    x_totalNum = x_totalNum + transform_Num;
                                    x_Num = x_totalNum - transform_Num;
                                    transform_Num = 0;
                                    //    printf("x_totalNum = %d\n", x_totalNum);
                                }
                            //x_totalNum = x_totalNum + transform_Num;
                            //printf("x_totalNum = %d\n", x_totalNum);
                        }
                        // else if (k == 0)
                        // {
                        //     if (isdigit(input[k]) == 1)
                        //     {
                        //         x_totalNum = x_totalNum + transform_Num;
                        //         printf("x_totalNum = %d\n", x_totalNum);
                        //     }
                        // }
                    }
                    // x_totalNum = x_totalNum + transform_Num;
                    //printf("x_totalNum = %d\n", x_totalNum);
                }
                // else if ((input[i]) == '-')
                // {
                // }

                else
                {
                    break;
                }
            }
            // start_count = end_count + 1;
            // end_count = count - 1;
            // //printf("%d\n", isdigit(input[0]));
            // if (isdigit((input[start_count])) == 1)
            // {
            //     transform_Num = input[start_count] - '0';
            //     x_totalNum = x_totalNum + transform_Num;
            //     printf("x_totalNum = %d\n", x_totalNum);
            // }

            //   printf("input%d is x.\n", count + 1);
        }
    }
    cout << "x_totalNum = " << x_totalNum << endl;

    Num = allNum - x_Num;
    printf("x = %f", Num / x_totalNum);
    return 0;
}
