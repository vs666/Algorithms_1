#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool comp(const ll &a, const ll &b)
{
    return a <= b;
}

void merge(ll *ar, ll l, ll u)
{
    ll mid = (l + u) / 2;
    ll size1 = mid - l + 1, size2 = u - mid;
    ll a1[size1], a2[size2];
    for (int x = l; x <= u; x++)
    {
        if (x <= mid)
        {
            a1[x - l] = ar[x];
        }
        else
        {
            a2[x - mid - 1] = ar[x];
        }
    }
    ll i = 0, j = 0, k = l;
    while (i < size1 && j < size2)
    {
        if (comp(a1[i], a2[j]))
        {
            ar[k] = a1[i];
            i++, k++;
        }
        else
        {
            ar[k] = a2[j];
            j++, k++;
        }
    }
    while (i < size1)
    {
        ar[k++] = a1[i++];
    }
    while (j < size2)
    {
        ar[k++] = a2[j++];
    }
}

void mergeSort(ll *ar, ll l, ll u)
{
    if (l >= u)
    {
        return;
    }
    mergeSort(ar, l, (l + u) / 2);
    mergeSort(ar, (l + u) / 2 + 1, u);
    merge(ar, l, u);
}

int main()
{
    ll n;
    cin >> n;
    ll ar[n];
    for (auto &x : ar)
    {
        cin >> x;
    }
    mergeSort(ar, 0, n - 1);
    cout << "Sorted Array :\n";
    for (auto x : ar)
    {
        cout << x << " ";
    }
    cout << endl;
}