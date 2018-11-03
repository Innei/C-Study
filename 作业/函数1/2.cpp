#include <iostream>
#include <string.h>
using namespace std;
int drewNum(int a, int b);
int countdigit(int a, int b)
{
    int z;
    int count = 0, len = 0;
    string ch = to_string(a); //定义在std::
    char *p = const_cast<char *>(ch.c_str());
    len = strlen(p);
    // cout << count << endl;

    for (int i = 1; i <= len; i++)
    {
        if (drewNum(a, i) == b)
        {
            count++;
        }
    }
    return count;
}
int drewNum(int a, int b)
{
    int z;
    string ch = to_string(a);                 //定义在std::
    char *p = const_cast<char *>(ch.c_str()); //通过const_cast去掉string的const属性 --> char指针
    z = *(p + (b - 1)) - '0';
    return z;
}
int main(int argc, char const *argv[])
{
    int ipt = 0, num = 0;
    cout << "输入一个整数:" << endl;
    cin >> ipt;
    cout << "输入一个值:" << endl;
    cin >> num;
    if (num > 9 && num < 0)
    {
        cout << "error.." << endl;
        exit(0);
    }
    cout << ipt << "有" << countdigit(ipt, num) << "个" << num << endl;
    return 0;
}
