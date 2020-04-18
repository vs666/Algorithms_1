#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAXLEN = (ll)1e6 + 6;

void preCalculate(string s, vector<ll> &ans)
{
    ll len = s.length();
    ll index = 0;
    for (int x = 1; x < len; x++)
    {
        if (s[x] == s[index])
        {
            index++;
            ans[x] = index;
        }
        else
        {
            index = max((ll)0, index - 1);
            ans[x] = index;
        }
    }
}

void compareKMP(string s, string m)
{
    ll slen = s.length();
    ll mlen = m.length();

    vector<ll> comp(mlen, 0);
    preCalculate(m, comp);
    ll index = 0;
    bool found = false;
    ll count = 1;
    vector<ll> ans;
    for (int x = 0; x < slen; x++)
    {
        if (s[x] == m[index])
        {
            index++;
            if (index == mlen)
            {
                index = comp[index - 1];
                found = true;
                ans.push_back(x + 1 - mlen);
            }
        }
        else
        {
            index = 0;
        }
    }
    for (auto x : ans)
    {
        cout << x << endl;
    }
    cout << endl;
}

int main()
{

    string s1, s2;
    cin >> s2 >> s1;
    compareKMP(s1, s2);
    return 0;
}