#include <stdio.h>

int main(int argc, char const *argv[])
{
    int m, n;
    int m_cup, n_cup, r;

    scanf("%d %d", &m, &n);
    if (m > 0 && n > 0)
    {
        m_cup = m;
        n_cup = n;
        r = m_cup % n_cup;
        while (r != 0)
        {
            m_cup = n_cup;
            n_cup = r;
            r = m_cup % n_cup;
        }
        printf("最大公约数: %d\n", n_cup);
        printf("最小公倍数: %d\n", m * n / n_cup);
    }
    else
        printf("Error!\n");

    return 0;
}
