#include <iostream>
int b = 1;
using namespace std;

void printboutofstatic()
{
    cout << "Global out " << b << endl;  // 1
}

void GlobalVariable()
{
    extern int b;  

    cout << "Global extern = " << b << endl; // 1 
    cout << "Now add 1 to extern variable " << endl;

    cout << "Now is " << b + 1;  //  2
}
void f()
{
    static int num = 0;
    num++;
    cout << "静态持续变量" << num << endl;
}

namespace myspace
{
int nu;
char name[3];

} // namespace myspace
using namespace myspace;

int main(int argc, char const *argv[])
{

    static int b;
    b = 3;
    cout << "Private out " << b << endl; //私有变量输出
    printboutofstatic();                 //全局变量输出  //  1
    f();                // 1
    f(); //2次调用;      // 2

    //namespace
    nu = 10;
    cout << "namespace nu is " << nu << endl;

    // extern global
    GlobalVariable();

    return 0;
}
