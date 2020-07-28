#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

class Random
{
public:
    Random(ll seed_)
    {
        recVal = seed_;
        seed = seed_;
    }
    ll getRandom()
    {
        return recurse();
    }

private:
    ll seed;
    const ll a = (ll)934653647, b = (ll)982103831, m = (ll)984034907;
    ll recVal;
    ll recurse()
    {
        recVal = recVal * a + b;
        recVal %= m;
        return recVal;
    }
};

int main()
{
    ll t;
    cin >> t;
    Random ob(0);
    for(int x=0;x<t;x++)
    {
        cout << ob.getRandom() << endl;
    }
}