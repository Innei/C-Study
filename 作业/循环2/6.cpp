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
int main(int argc, char const *argv[])
{
    int count = 0, temp = 0;
    int input = 0, output = 0;
    cout << "Enter a num:" << endl;
    cin >> input;
    temp = input;
    if (input < 0)
    {
        input = -input;
        cout << '-';
        count = 0;
        while (temp != 0)
        {

            temp /= 10;
            count++;
        }

        for (int i = count; i >= 1; i--)
        {
            cout << drewNum(input, i);
        }
    }
    else if (input > 0)
    {
        count = 0;
        while (temp != 0) //计算位数
        {

            temp /= 10;
            count++;
        }
        // cout << count << endl;
        //cout << drewNum(input, 5);
        for (int i = count; i >= 1; i--)
        {
            cout << drewNum(input, i);
        }
    }

    return 0;
}
