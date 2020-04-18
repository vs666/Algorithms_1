#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAX = (ll)1e5 + 55;

vector<ll> heap(4 * MAX, 0);

void heapify(ll index)
{
    ll t = heap[index];
    if (heap[index] > max(heap[index * 2], heap[index * 2 + 1]))
    {
        return;
    }
    else if (heap[index * 2] > heap[index * 2 + 1])
    {
        heap[index] = heap[index * 2];
        heap[index * 2] = t;
        heapify(index * 2);
    }
    else if (heap[index * 2] < heap[index * 2 + 1])
    {
        heap[index] = heap[index * 2 + 1];
        heap[index * 2 + 1] = t;
        heapify(index * 2 + 1);
    }
}

void heapify(ll index, ll size)
{
    if (index > size)
    {
        cout << index << " > " << size << endl;
        return;
    }
    ll t = heap[index];

    if (size == index * 2)
    {
        if (heap[index * 2] > heap[index])
        {
            heap[index] = heap[index * 2];
            heap[index * 2] = t;
        }
        return;
    }
    else if (heap[index] > max(heap[index * 2], heap[index * 2 + 1]))
    {
        return;
    }
    else if ((heap[index * 2] >= heap[index * 2 + 1] && size >= index * 2))
    {
        heap[index] = heap[index * 2];
        heap[index * 2] = t;
        if (index * 4 <= size)
            heapify(index * 2, size);
    }
    else if (heap[index * 2] < heap[index * 2 + 1] && size >= index * 2 + 1)
    {
        heap[index] = heap[index * 2 + 1];
        heap[index * 2 + 1] = t;
        if (index * 4 + 2 <= size)
            heapify(index * 2 + 1, size);
    }
}

void buildHeap(ll n = heap[0])
{
    for (int x = 1; x <= n; x++)
    {
        heapify(x);
    }
}

void heapSort(ll end)
{
    if (end == 1)
    {
        return;
    }
    ll t = heap[1];
    heap[1] = heap[end];
    heap[end] = t;
    heapify(1, end - 1);
    heapSort(end - 1);
}

int main()
{
    ll n;
    cin >> n;
    heap[0] = n;
    for (int x = 1; x <= n; x++)
    {
        cin >> heap[x];
    }
    buildHeap();
    heapSort(n);
    for (int x = 0; x < n; x++)
    {
        cout << heap[x + 1] << " ";
    }
    cout << endl;
}