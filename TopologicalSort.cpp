#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MAX = (ll)1e5 + 5;
vector<ll> graph[MAX];
stack<ll> toporder;
vector<bool> visited(MAX, false);

void topSort(ll node)
{
    visited[node] = true;
    for (auto x : graph[node])
    {
        if (visited[x] == false)
        {
            topSort(x);
        }
    }
    toporder.push(node);
}

int main()
{
    ll n, m;
    cin >> n >> m;
    for (int x = 0; x < m; x++)
    {
        ll a, b, w;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int x = 1; x <= n; x++)
    {
        if (visited[x] == false)
        {
            topSort(x);
        }
    }
    cout << "Topologically Sorted order is : \n";
    while (toporder.empty() == false)
    {
        cout << toporder.top() << " ";
        toporder.pop();
    }
    cout << endl;
    return 0;
}
