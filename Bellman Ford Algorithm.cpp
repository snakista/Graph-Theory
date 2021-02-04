#include <bits/stdc++.h>
#define fast                          \
	ios_base::sync_with_stdio(false); \
	cin.tie(0)
#define ll long long int
using namespace std;
#define modm 1000000007
#define pb push_back
const int MAX_N = 1000000;
const int inf = MAX_N + 9;
ll modexp(ll x, ll n)
{
	ll result = 1;
	x = x % modm;
	while (n > 0)
	{
		if (n % 2 == 1)
			result = (result * x) % modm;
		x = (x * x) % modm;
		n = n / 2;
	}
	return result;
}
ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
ll D, c1, c2;
void extendedEuclid(ll A, ll B)
{
	if (B == 0)
	{
		D = A;
		c1 = 1;
		c2 = 0;
	}
	else
	{
		extendedEuclid(B, A % B);
		ll temp = c1;
		c1 = c2;
		c2 = temp - (A / B) * c2;
	}
}
ll modInverse(ll A, ll M)
{
	extendedEuclid(A, M);
	return (c1 % M + M) % M;
}
ll fact(ll n)
{
	ll res = 1;
	for (ll i = 1; i <= n; i++)
	{
		res = (res * 1ll * i) % modm;
	}
	return res;
}
ll C(ll n, ll k)
{
	return fact(n) * 1ll * modexp(fact(k), modm - 2) % modm * 1ll * modexp(fact(n - k), modm - 2) % modm;
}
bool prime[101];
void sieve()
{
	memset(prime, true, sizeof(prime));
	ll n = 101;
	for (ll i = 2; i * i <= n; i++)
	{
		if (prime[i] == true)
		{
			for (ll j = i * i; j <= n; j += i)
				prime[j] = false;
		}
	}
}
vector<pair<ll, pair<ll, ll>>> v;
ll dist[1000];
int main()
{
	//fast;
	ll n, m, x, a, b, w;
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
		dist[i] = inf;
	while (m--)
	{
		cin >> a >> b >> w;
		v.push_back(make_pair(a, make_pair(b, w)));
	}
	cout << "Enter source vertex: ";
	cin >> x;
	// bellman ford algorithm
	dist[x] = 0;
	for (ll i = 1; i <= n - 1; i++)
	{
		for (auto e : v)
		{
			ll a, b, w;
			a = e.first;
			b = e.second.first;
			w = e.second.second;
			dist[b] = min(dist[b], dist[a] + w);
		}
	}
	for (ll i = 1; i <= n; i++)
		cout << dist[i] << " ";
}
