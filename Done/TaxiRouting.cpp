#include <bits/stdc++.h>
#include <array>
#include <vector>
using namespace std;
const int MAX = 1e3;
int n, x[MAX], f, f_best, cmin;
int c[2 * MAX + 1][2 * MAX + 1];
int custom[MAX];   // mảng chứa trạng thái của các khách 1, 2, 3,... i.
vector<int> cus(MAX); // vector chứa điểm đến của khách

void input()
{
    cin >> n;
    cmin = 1e6;
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> c[i][j];
            if (i != j && c[i][j] < cmin)
            {
                cmin = c[i][j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cus[i] = i + n;
    }
}

bool check(int v, int k)
{
    if (custom[v] == 1)
        return false;
    return true;
}

void solution()
{
    if (f + c[x[n]][0] < f_best)
    {
        f_best = f + c[x[n]][0];
    }
}

void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (check(v, k))
        { // kiểm tra khách v đã đc đón chưa
            x[k] = v;
            f += c[x[k - 1]][x[k]]; // đi đón khách
            f += c[x[k]][cus[x[k]]];   // đi trả khách
            x[k] = cus[v];
            custom[v] = 1;
            if (k == n)
            {
                solution();
            }
            else
            {
                if (f + (2 * n + 1 - 2 * k) * cmin < f_best)
                {
                    Try(k + 1);
                }
            }
            custom[v] = 0;
            x[k] = v;
            f -= c[x[k - 1]][x[k]];
            f -= c[x[k]][cus[x[k]]];
        }
    }
}

void solve()
{
    f = 0;
    f_best = 1e6;
    for (int i = 0; i <= n; i++)
    {
        custom[i] = 0;
    }
    x[0] = 0;
    Try(1);
    cout << f_best;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();
    return 0;
}