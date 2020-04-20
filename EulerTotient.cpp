#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAX = (ll)1e6 + 6;
vector<ll> phi(MAX + 1, 0);

void precomputePhi()
{
    for (int x = 1; x <= MAX; x++)
    {
        phi[x] = x;
    }
    for (int x = 2; x <= MAX; x++)
    {
        if (phi[x] == x)
        {
            for (int y = x; y <= MAX; y += x)
            {
                phi[y] -= phi[y] / x;
            }
        }
    }
}

int main()
{
    precomputePhi();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << "Phi(" << n << ") = " << phi[n] << endl;
    }
    return 0;
}
