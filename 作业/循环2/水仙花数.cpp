#include <iostream>
#include <math.h>
using namespace std;
// int isNarcissus(int n)
// {
//     string ch = to_string(n); //定义在std::
//     // string *p = &ch;

//     char *p = const_cast<char *>(ch.c_str()); //通过const_cast去掉string的const属性 --> char指针
//    // cout << p[2] << endl;

// if (ch == (pow((p[0]-'0'),3)+pow((p[1]-'0'),3)+pow((p[2]-'0'),3)+'0') {
//     /* code */
// }

//     return 1;
// }
int drewNum(int a, int b)
{
    int z;
    string ch = to_string(a);                 //定义在std::
    char *p = const_cast<char *>(ch.c_str()); //通过const_cast去掉string的const属性 --> char指针
    z = *(p+(b-1)) - '0';
    return z;
}
int isNarcissus(int i)
{
    int sum = pow(drewNum(i, 1), 3) + pow(drewNum(i, 2), 3) + pow(drewNum(i, 3), 3);
    return sum;
}
int main(int argc, char const *argv[])
{
    int a = 0, b = 0;
    cout << "Enter two numbers :" << endl;
    cin >> a >> b;
    if(a<100 || b >=1000||a>b){
        cout << "error" << endl;
        exit(0);
    }
    for(int i = a; i <= b; i++)
    {
         if(isNarcissus(i) == i)
         {
             cout << i << endl;

         }
    }
    
   

    return 0;
}
