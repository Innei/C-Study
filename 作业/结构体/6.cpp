#include <iostream>
using namespace std;

typedef struct book
{
    char name[80];
    double price;
} B, *pB;

int main()
{
    struct book *bk;

    int n, i, max = 0, min = 0;
    cout << "n = :" << endl;
    cin >> n;
    bk = (pB)malloc(sizeof(B) * n);

    for (i = 0; i < n; i++)
    {
        cout << "输入第" << i + 1 << "本书的名字和定价: " << endl;
        cin >> bk[i].name >> bk[i].price;

        if (bk[i].price < bk[min].price)
        {
            min = i;
        }

        if (bk[i].price > bk[max].price)
        {
            max = i;
        }
    }
    cout << "max: " << (bk + max)->name << '\t' << (bk + max)->price << endl;
    cout << "min: " << (bk + min)->name << '\t' << (bk + min)->price;
    return 0;
}
