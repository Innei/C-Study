#include<iostream>
using namespace std;

int main(void)
{

    char *p = "hello";
    cout<<p<<endl;
    cout<<*p<<endl;
//拼接字符串..
//
    char a1[11] = "hello";
    char a2[6] = "world";
    cout<<a2<<endl;

    for (int count = 5;count <= 9;count++)
    {
        a1[count]=a2[count-5];
    }
    a1[10]='\0';
cout<<a1<<endl;

    return 0;
}
