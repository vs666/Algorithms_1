#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long double ll;

void insertion_sort(vector<ll> &ar)
{
    int len = ar.size();
    if (len == 0)
    {
        return;
    }
    for (int x = 1; x < len; x++)
    {
        int a = x;
        while (a > 0)
        {
            if ((ar[a] - ar[a - 1]) < 0)
            {
                ll t = ar[a];
                ar[a] = ar[a - 1];
                ar[a - 1] = t;
            }
            a--;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    ll ar[n];
    ll max_num = 0, min_num = INFINITY;
    for (int x = 0; x < n; x++)
    {
        cin >> ar[x];
        max_num = max(max_num, ar[x]);
        min_num = min(min_num, ar[x]);
    }

    vector<vector<ll>> br(n, vector<ll>());

    ll range = max_num - min_num;
    if (range != 0)
    {
        range++;
        for (int x = 0; x < n; x++)
        {
            br[(int)(n * (ar[x] - min_num) / range)].push_back(ar[x]);
        }
        for (int x = 0; x < n; x++)
        {
            insertion_sort(br[x]);
        }
    }
    int index = 0;
    for (int x = 0; x < n; x++)
    {
        for (auto a : br[x])
        {
            ar[index++] = a;
        }
    }
    for (int x = 0; x < n; x++)
    {
        cout << ar[x] << " ";
    }
    cout << endl;
}