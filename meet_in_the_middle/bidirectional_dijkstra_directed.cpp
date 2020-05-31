#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = (ll)1e17;
const ll MAX = (ll)1e5 + 55;
vector<pair<ll, ll>> g[MAX];
vector<pair<ll, ll>> gR[MAX];

int main()
{
    ll n, m;
    cin >> n >> m;
    for (int x = 1; x <= m; x++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({c, b});
        gR[b].push_back({c, a});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pqf;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pqb;
    ll t;
    cin >> t;
    while (t--)
    {
        vector<ll> distf(n + 1, INF);
        vector<ll> distb(1 + n, INF);
        vector<ll> done;
        ll f, b;
        cin >> f >> b;
        distf[f] = 0;
        distb[b] = 0;
        pqf.push({0, f});
        pqb.push({0, b});
        done.push_back(f);
        done.push_back(b);

        while (!pqf.empty() && f != b)
        {
            ll node = pqf.top().second;
            f = node;
            cout << node << endl;
            done.push_back(node);
            for (auto x : g[node])
            {
                if (distf[x.second] >= x.first + distf[node])
                    pqf.push({distf[x.second], x.second});
                distf[x.second] = min(distf[x.second], x.first + distf[node]);
            }
            pqf.pop();
            if (f == b)
            {
                break;
            }
            node = pqb.top().second;
            b = node;
            done.push_back(node);
            for (auto x : gR[node])
            {
                if (distb[x.second] >= x.first + distb[node])
                    pqb.push({distb[x.second], x.second});
                distb[x.second] = min(distb[x.second], x.first + distb[node]);
            }
            pqb.pop();
            if (f == b)
            {
                break;
            }
        }
        for (auto x : done)
        {
            for (auto y : g[x])
            {
                if (distf[y.first] != INF)
                {
                    distf[y.first] = min(distf[y.first], distf[x] + y.second);
                }
            }
            for (auto y : gR[x])
            {
                if (distb[y.first] != INF)
                {
                    distb[y.first] = min(distb[y.first], distb[x] + y.second);
                }
            }
        }

        ll ans = INF;
        for (auto x : done)
        {
            ans = min(distf[x] + distb[x], ans);
        }
        if (ans == INF)
        {
            ans = -1;
        }
        cout << ans << endl;
    }
}