// time : 10-3
// 此程序只能计算 个位数 一元一次方程 
// 系数为1 不可省略


#include <stdio.h>
#include <ctype.h>

// #define IS_BLANK(c) ((c) == ' ' || (c) == '\t')
// #define IS_DIGIT(c) ((c) >= '0' && (c) <= '9')
// #define IS_ALPHA(c) (((c) >= 'a' && (c) <= 'z') || ((c) >= 'A' && (c) <= 'Z'))
// #define IS_HEX_DIGIT(c) (((c) >= 'A' && (c) <= 'F') || ((c) >= 'a' && (c) <= 'f'))

// /* Whether string s is a number.
//    Returns 0 for non-number, 1 for integer, 2 for hex-integer, 3 for float */
// int is_number(char *s)
// {
//     int base = 10;
//     char *ptr;
//     int type = 0;

//     if (s == NULL)
//         return 0;

//     ptr = s;

//     /* skip blank */
//     while (IS_BLANK(*ptr))
//     {
//         ptr++;
//     }

//     /* skip sign */
//     if (*ptr == '-' || *ptr == '+')
//     {
//         ptr++;
//     }

//     /* first char should be digit or dot*/
//     if (IS_DIGIT(*ptr) || ptr[0] == '.')
//     {

//         if (ptr[0] != '.')
//         {
//             /* handle hex numbers */
//             if (ptr[0] == '0' && ptr[1] && (ptr[1] == 'x' || ptr[1] == 'X'))
//             {
//                 type = 2;
//                 base = 16;
//                 ptr += 2;
//             }

//             /* Skip any leading 0s */
//             while (*ptr == '0')
//             {
//                 ptr++;
//             }

//             /* Skip digit */
//             while (IS_DIGIT(*ptr) || (base == 16 && IS_HEX_DIGIT(*ptr)))
//             {
//                 ptr++;
//             }
//         }

//         /* Handle dot */
//         if (base == 10 && *ptr && ptr[0] == '.')
//         {
//             type = 3;
//             ptr++;
//         }

//         /* Skip digit */
//         while (type == 3 && base == 10 && IS_DIGIT(*ptr))
//         {
//             ptr++;
//         }

//         /* if end with 0, it is number */
//         if (*ptr == 0)
//             return (type > 0) ? type : 1;
//         else
//             type = 0;
//     }
//     return type;
// }
//line输入的字符串
//n字符串长度，内部执行总次数
 
int my_atoi(char *line, size_t n)
{    
    int        value;
	
    if (n == 0) {
        return -1; 
    }   
 
    for (value = 0; n--; line++) {
        if (*line < '0' || *line > '9') {
			//存在非数字字符则，终止解析
			return -1;
        }
 
		/*
			1、当前字符值 *line的ascii码，减去字符0的ascii码，得出个位数字
			2、原计算的value值 乘以10，向上提升一位
			3、二者相加得到新的十进制数值
		*/
        value = value * 10 + (*line - '0');
    }
 
    if (value < 0) {
        return -1; 
    } else {
        return value;
    }
}    

int main(int argc, char const *argv[])
{
    char input[10] = "20+3x=-18";
    //char input[10] = "1x+1=2x";
    //scanf("%s", &input);

    //  short int siglter = 0;
    // printf("%s\n", input);
    //printf("%d", len);
    char catchar[10];
    int len = strlen(input);
    char *letter = &input;
    int allNum = 0;
    int start_count = 0;
    int end_count = -1;
    int x_totalNum;
    short x_Num = 0;
    double result = 0.0;
    float Num = 0.0;
    int transform_Num = letter[start_count] - '0';
    //printf("%d\n", transform_Num);
    // printf("%c\n", *letter);
    for (int count = 0; len > count; count++)
    {
        if (isdigit(letter[count]) == 1)
        {
            allNum = allNum + (letter[count] - '0');
        }

        if (*(letter + count) == 'x')
        {
            for (int i = count - 1; i >= 0; i--)
            {
                if (isdigit(letter[0]) == 1)
                    x_totalNum = letter[0] - '0';

                else

                    x_totalNum = 0;
                if (isdigit((letter[i])) == 1)
                {
                    //strcpy(catchar, strcat(catchar, letter[i]));
                    //catchar = strcat(catchar, letter[i]);
                   // transform_Num =  my_atoi(letter[i],len);
                  //  printf("%d", transform_Num);
                     transform_Num = letter[i] - '0';
                    for (int k = i; k >= 0; k--) //判断加减号
                    {
                        if (letter[k] == '+')
                        {
                            x_totalNum = x_totalNum + transform_Num;
                            x_Num = x_totalNum;
                        //    printf("x_totalNum = %d\n", x_totalNum);
                        }
                        else if (letter[k] == '-')
                        {
                            x_totalNum = x_totalNum - transform_Num;
                             x_Num = x_totalNum;
                      //      printf("x_totalNum = %d\n", x_totalNum);
                        }
                        
                        else if (letter[k] == '=') // 判断等好位置.系数移动到一遍
                        {
                            for (int j = k; j < len; j++)
                                if (letter[j] == '+')
                                {
                                    x_totalNum = x_totalNum - transform_Num;
                                     x_Num = x_totalNum + transform_Num;
                                  //  printf("x_totalNum = %d\n", x_totalNum);
                                }
                                else if (letter[j] == '-')
                                {
                                    x_totalNum = x_totalNum + transform_Num;
                                     x_Num = x_totalNum - transform_Num;
                                //    printf("x_totalNum = %d\n", x_totalNum);
                                }
                            //x_totalNum = x_totalNum + transform_Num;
                            //printf("x_totalNum = %d\n", x_totalNum);
                        }
                        // else if (k == 0)
                        // {
                        //     if (isdigit(letter[k]) == 1)
                        //     {
                        //         x_totalNum = x_totalNum + transform_Num;
                        //         printf("x_totalNum = %d\n", x_totalNum);
                        //     }
                        // }
                    }
                    // x_totalNum = x_totalNum + transform_Num;
                    //printf("x_totalNum = %d\n", x_totalNum);
                }
                // else if ((letter[i]) == '-')
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
            // if (isdigit((letter[start_count])) == 1)
            // {
            //     transform_Num = letter[start_count] - '0';
            //     x_totalNum = x_totalNum + transform_Num;
            //     printf("x_totalNum = %d\n", x_totalNum);
            // }

         //   printf("letter%d is x.\n", count + 1);
        }
    }
    Num = allNum - x_Num;
    printf("x = %f", Num / x_totalNum);
    return 0;
}
