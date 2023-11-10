#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;
int n, arr[MAX];

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin > arr[i];
    }
}

void mergeSort(int a[], int l, int r)
{
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a ,l ,m, r);
}

void merge(int a[], int l, int m, int r)
{
    vector<int> x(a + 1, a + m + 1);
    vector<int> y(a + m + 1, a + r + 1);
    int i = j = 0;
    while (i < x.size() && j < y.size())
    {
        if (x[i] <= y[j])
        {
            a[l] = x[i];
            ++l;
            ++i;
        }
        else
        {
            a[l] = y[j];
            ++l;
            ++i;
        }
    }
    while (i < x.size())
    {
        a[l] = x[i];
        ++l;
        ++i;
    }
    while (j < y.size()){
        a[l] = y[j];
        ++l; ++i;
    }
}

int main()
{
    input();
}