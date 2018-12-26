#include <iostream>
using namespace std;

typedef struct tel
{
    char name[8];
    char tel[80];
    int bir;
} B, *pB;

int main()
{
    struct tel *t, *temp;
    int index;

    int n, i, max = 0, min = 0;
    cout << "n = :" << endl;
    cin >> n;
    t = (pB)malloc(sizeof(B) * n);

    for (i = 0; i < n; i++)
    {
        cout << "输入第" << i + 1 << "个人的姓名生日和电话: " << endl;
        cin >> t[i].name >> t[i].bir >> t[i].tel;

        for (int j = 0; j < n - 1; j++)
        {
            index = 0;

            for (int j = 0; j < n - 1; j++)
            {

                if ((t + j)->bir > (t + index)->bir)
                {
                    index = j;
                }
                temp = &t[n - i - 1];
                t[n - i - 1] = t[index];
                t[index] = *temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        cout << (t + i)->name << ' ' << (t + i)->bir << "  " << (t + i)->tel << endl;
    }

    return 0;
}
