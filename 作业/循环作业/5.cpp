#include <iostream>
using namespace std;
struct fruit
{
    char name[10];
    float piece;
    short num;
};
int main(int argc, char const *argv[])
{
    int Num = 0;
    struct fruit a = {"apples", 3.00, 1};
    struct fruit p = {"pears", 2.50, 2};
    struct fruit o = {"oranges", 4.10, 3};
    struct fruit g = {"grapes", 10.20, 4};
    cout << "[" << a.num << ']' << a.name << endl;
    cout << '[' << p.num << ']' << a.name << endl;
    cout << '[' << o.num << ']' << o.name << endl;
    cout << '[' << g.num << ']' << g.name << endl;
    cout << "[0]exit" << endl;
    cin >> Num;
    switch (Num)
    {
    case 1:
        cout << "The price of " << a.name << " is " << a.piece << endl;
        break;
    case 2:
        cout << "The price of " << p.name << " is " << p.piece << endl;
        break;
    case 3:
        cout << "The price of " << o.name << " is " << o.piece << endl;
        break;
    case 4:
        cout << "The price of " << g.name << " is " << g.piece << endl;
        break;
    defalut:
        cout << '0' << endl;
    }
    return 0;
}
