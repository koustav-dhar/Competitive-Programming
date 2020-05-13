#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define loop(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define cases ll T=0;cin>>T;while(T--)
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define END "\n"
#define pb push_back
#define inf 9e18
#define MOD 1000000007
#define MODU 998244353
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 1000001
const string alpha = "abcdefghijklmnopqrstuvwxyz";
vector<vector<char>> adj(1001, vector<char>(1001, 'N'));
void add_edge(ll a, ll b)
{
	adj[a][b] = 'Y';
	adj[b][a] = 'Y';
}
ll solve()
{
	add_edge(1, 3);
	add_edge(1, 4);
	ll val = 5, exp = 3;
	for (; exp < 32; exp++)
	{
		FOR(i, 1, exp - 1)
		{
			add_edge(val, val - i);
		}
		val++;
		loop(i, exp - 1)
		{
			add_edge(val, val - exp);
			val++;
		}
	}
	return val - 2;
}
signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	ll k;
	cin >> k;
	ll val = solve();
	ll n = val + 1;
	vector<ll> bitnum(32);
	for (ll i = 0; i < 32; i++, val--)
	{
		bitnum[i] = val;
	}
	ll j = 0;
	while (k > 0)
	{
		if (k & 1)
		{
			add_edge(2, bitnum[j]);
		}
		k /= 2;
		j++;
	}
	cout << n << END;
	FOR(i, 1, n)
	{
		FOR(j, 1, n)
		{
			cout << adj[i][j];
		}
		cout << END;
	}
	return 0;
}