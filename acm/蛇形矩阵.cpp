#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    static int a[100][100];
    int m; //纬数
    int n; // 数组
    int i;
    cin >> m;
    if (m % 2 == 0)
        exit(-1);
    n = m - 1;
    int 圈 = m / 2; // 计数需要的圈数
    int x, y;       // 定位坐标
    x = n / 2;      // 起始点位置
    y = n / 2;
    a[x][y] = 1;   // 初始点赋值
    int count = 1; // 记录要走的步数
    int add = 2;   //数据累加器
    while (圈)
    {
        y++;
        //向上

        for (i = x; i >= x - count; i--)
        {
            a[i][y] = add;
            add++;
            //cout << i << endl;
        }
        // 向左
        x = ++i;
        //cout << y <<endl;
        for (i = y - 1; i >= y - count - 1; i--)
        {
            a[x][i] = add;
            add++;
        }
        y = ++i;
        //cout << x << endl;
        //向下
        for (i = x + 1; i <= x + count + 1; i++)
            a[i][y] = add++;

        x = --i;
        //cout << y << endl;
        //向右
        for (i = y + 1; i <= y + count + 1; i++)
        {
            a[x][i] = add;
            add++;
        }
        圈--;
        count += 2;
        y = --i;
    }

    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < m; j++)
        {
            printf("%5d", a[i][j]);
        }
        cout << endl;
    }
    int sum = 0;

    for (int i = 0; i < m; i++)
    {
        sum = sum + a[i][i] + a[i][n--];
    }
    cout << endl
         << sum << endl;
    return 0;
}
