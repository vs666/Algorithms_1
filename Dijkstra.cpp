#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAX = (ll)1e5 + 5;
const ll INF = (ll)1e15 + 150;

vector<pair<ll, ll>> g[MAX];
vector<ll> dist(MAX, INF);

void dijkstra(ll source) // O(mlog(n))
{
    dist[source] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, source});
    while (!pq.empty())
    {
        ll d = pq.top().first;
        ll node = pq.top().second;
        for (auto x : g[node])
        {
            if (dist[x.second] > dist[node] + x.first)
            {
                dist[x.second] = dist[node] + x.first;
                pq.push({dist[node] + x.first, x.second});
            }
        }
        pq.pop();
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    // n nodes and m edges
    while (m--)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({w, b});
        g[b].push_back({w, a});
    }

    ll source = n; // initialize with non-negative valid node value
    cout << "Enter source node " << endl;
    cin >> source;
    dijkstra(source);

    for (int x = 1; x <= n; x++)
    {
        cout << "Distance of " << x << " from " << source << " is " << dist[x] << endl;
    }
}