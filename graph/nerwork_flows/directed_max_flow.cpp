#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ll m, n;
    cin >> n >> m;
    vector<pair<pair<ll, ll>, ll>> g[n + 1];

    for (int x = 0; x < m; x++)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({{w, w}, b});
        g[b].push_back({{0, w}, a});
    }

    const ll inf = (ll)1e15;
    ll ap = -1;
    ll flow = 0;
    while (ap != 0)
    {
        queue<ll> q;
        vector<ll> parent(n + 1, -1);
        q.push(1);
        int count = 0;
        while (!q.empty())
        {
            count++;
            bool isSink = false;
            ll node = q.front();
            for (auto x : g[node])
            {
                if (x.first.first <= 0 || x.second == parent[node])
                {
                    continue;
                }
                if (parent[x.second] == -1 && x.first.first != 0)
                {
                    q.push(x.second);
                }
                if (x.first.first != 0)
                    parent[x.second] = node;

                if (x.second == n)
                {
                    isSink = true;
                    break;
                }
            }
            if (isSink)
            {
                break;
            }
            else if (count == 2 * m)
            {
                break;
            }

            q.pop();
        }
        ll dist = inf;
        ll index = n;
        ll c = 0;
        while (index != 1)
        {
            if (parent[index] == -1)
            {
                if (index != 1)
                    c = m + 1;
                break;
            }
            c++;
            for (auto x : g[parent[index]])
            {
                if (x.second == index)
                {
                    if (dist > x.first.first)
                        // cout << parent[index] << " " << index << " " << x.first << endl;
                        dist = min(dist, x.first.first);
                }
            }
            // cout << dist << endl;
            index = parent[index];
            if (c > m)
            {
                break;
            }
        }
        if (c == 0 || c > m)
        {
            ap = 0;
            dist = 0;
        }
        c = 0;
        index = n;
        while (index != 1 && dist != 0)
        {
            if (parent[index] == -1)
            {
                break;
            }
            c++;
            for (auto &x : g[parent[index]])
            {
                if (x.second == index)
                {
                    x.first.first -= dist;
                }
            }
            for (auto &x : g[index])
            {
                if (x.second == parent[index])
                {
                    x.first.first += dist;
                }
            }
            index = parent[index];
            if (c > n)
            {
                break;
            }
        }
        ap = dist;
        flow += dist;
    }
    cout << "Max Flow : " << flow << endl;
}