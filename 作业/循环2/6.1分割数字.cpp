#include <iostream>
using namespace std;

int drewNum(int a, int b) //提取单个数字的函数原型
{
    int z;
    string ch = to_string(a);                 //定义在std::
    char *p = const_cast<char *>(ch.c_str()); //通过const_cast去掉string的const属性 --> char指针
    z = *(p + (b - 1)) - '0';

    return z;
}
int calbit(int temp) //计算位数的函数原型
{
    int count = 0;
    while (temp != 0)
    {

        temp /= 10;
        count++;
    }
    return count;
}
int main(int argc, char const *argv[])
{
    int input = 0;
    cout << "Enter a num :" << endl;
    cin >> input;
    for (int i = calbit(input); i > 0; i--)
    {
        cout << drewNum(input, calbit(input) - i + 1) << "    ";
    }
    cout << endl;
    return 0;
}
