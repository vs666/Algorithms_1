#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll part(ll *ar, ll start, ll end, ll pivot)
{
    while (start < end)
    {
        while (ar[start] < pivot)
        {
            start++;
        }
        while (ar[end] > pivot)
        {
            end--;
        }
        if (ar[start] >= ar[end])
        {
            ll t = ar[start];
            ar[start] = ar[end];
            ar[end] = t;
            start++;
            end--;
        }
    }
    return start;
}

void qSort(ll *ar, ll start, ll end)
{
    if (start >= end)
    {
        return;
    }
    ll pivot = ar[(start + end) / 2];
    ll nextIndex = part(ar, start, end, pivot);
    qSort(ar, start, nextIndex - 1);
    qSort(ar, nextIndex, end);
}

void quicksort(ll *ar, ll size)
{
    qSort(ar, 0, size - 1);
}

int main()
{
    ll n;
    // enter number of elements of the array
    cin >> n;
    ll ar[n];
    for (auto &x : ar)
    {
        cin >> x;
    }
    quicksort(ar, n);
    // sorted elements
    for (auto x : ar)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}