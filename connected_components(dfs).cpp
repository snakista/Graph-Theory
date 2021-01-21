#include <bits/stdc++.h>
#define fast                          \
	ios_base::sync_with_stdio(false); \
	cin.tie(0)
#define ll long long int
using namespace std;
//#define mod 1000000007
#define pb push_back
const int MAXN = 1000000;
//const int inf = MAX_N + 9;
/*ll comb(ll n, ll r)
{
	if (r == 0)
	{
		return 1;
	}
	ll dp[MAXN][MAXN];
	for (ll i = 0; i < MAXN; i++)
	{
		dp[i][0] = dp[0][i] = 1;
	}
	for (ll i = 1; i < MAXN; i++)
	{
		for (ll j = 1; j < MAXN; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[r][n - r];
}*/
ll modexp(ll x, ll n, ll mod)
{
	ll result = 1;
	x = x % mod;
	while (n > 0)
	{
		if (n % 2 == 1)
			result = (result * x) % mod;
		x = (x * x) % mod;
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
bool visited[1001];
ll cmp[1001];
ll cnt = 0;
void dfs(ll s, vector<ll> adj[], ll cnt)
{
	visited[s] = true;
	cmp[s] = cnt;
	for (ll i = 0; i < adj[s].size(); i++)
	{
		if (visited[adj[s][i]] == false)
			dfs(adj[s][i], adj, cnt);
	}
}
int main()
{
	fast;
	int n, m;
	cin >> n >> m;
	vector<ll> adj[n];
	memset(visited, false, sizeof(visited));
	ll k = m;
	while (k--)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (ll i = 0; i < n; i++)
	{
		if (visited[i] == false)
		{
			cnt++;
			dfs(i, adj, cnt);
		}
	}
	cout << "No of different connected components are: ";
	ll ans = INT_MIN;
	for (ll i = 0; i < n; i++)
	{
		ans = max(ans, cmp[i]);
	}
	cout << ans;
}
