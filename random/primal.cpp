#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll modExp(ll b, ll m)
{
	ll ans = 1;
	ll e = m - 1;
	while (e)
	{
		if (e & 1)
		{
			ans *= b;
			ans %= m;
		}
		b *= b;
		b %= m;
		e >>= 1;
	}
	return ans;
}
bool checkPrime(ll n, ll k)
{
	srandom(time(NULL));
	if (n % 2 == 0)
	{
		return n == 2;
	}
	else
	{
		bool isP = true;
		while (k-- && isP)
		{
			ll z = 0;
			while (z == 0)
				z = random() % n;
			isP = modExp(z, n) == 1;
		}
		return isP;
	}
}

int main()
{
	ll num, k;
	cout << "Enter prob accuracy (1-1/2^k)*100 %% accuracy :";
	cin >> k;
	while (1)
	{
		cout << "Enter number :";
		cin >> num;
		if (checkPrime(num, k))
		{
			cout << "Prime Number\n";
		}
		else
		{
			cout << "Not prime number\n";
		}
	}
}
