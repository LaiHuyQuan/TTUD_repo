#include <bits/stdc++.h>
#include <vector>
using namespace std;

int FindStr(string strIn, vector<string>& base)
{
    int count;
    for (const string i : base)
    {
        if (strIn == i)
        {
            count = 1;
            break;
        }
        else
            count = 0;
    }
    return count;
}

int InsertStr(string strIn, vector<string>& base)
{
    int res;
    for (string& a : base)
    {
        if (a == strIn)
        {
            res = 0;
        }
        else
        {
            res = 1;
        }
    }   
    if (res == 1) base.push_back(strIn);
    return res;
}

int main()
{
    vector<string> base;
    string type;
    string strIn;
    vector<int> result;

    do
    {
        cin >> type;
        if (type == "*")
            continue;
        base.push_back(type);
    } while (type != "*");

    do
    {
        cin >> type;
        if (type == "***")
            continue;
        cin >> strIn;

        if (type == "insert")
        {
            int n = InsertStr(strIn, base);
            result.push_back(n);
        }

        if (type == "find")
        {
            int n = FindStr(strIn, base);
            result.push_back(n);
        }
    } while (type != "***");

    for (int i : result)
    {
        cout << i << endl;
    }
    
    return 0;
}