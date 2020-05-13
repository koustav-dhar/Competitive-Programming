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
#define go(c,itr) for(auto itr=(c).begin(); itr!=(c).end(); itr++)
#define back(c,itr) for(auto itr=(c).rbegin(); itr!=(c).rend(); itr++)
#define END "\n"
#define pb push_back
#define inf 9e18
#define MOD 1000000007
#define MODU 998244353
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 1000001
const string alpha = "abcdefghijklmnopqrstuvwxyz";
vector<ll> adj[MAXN];
ll spf[MAXN];
void sieve()
{
	spf[1] = 1;
	for (ll i = 2; i < MAXN; i++)
		spf[i] = i;

	for (ll i = 4; i < MAXN; i += 2)
		spf[i] = 2;

	for (ll i = 3; i * i < MAXN; i++)
	{
		if (spf[i] == i)
		{
			for (ll j = i * i; j < MAXN; j += i)
				if (spf[j] == j)
					spf[j] = i;
		}
	}
}
void addedge()
{
	ll a, b;
	cin >> a >> b;
	adj[a].pb(b);
	adj[b].pb(a);
}
void task(bool flag)
{
	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";
}
signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	// sieve();
	cases
	{
		ll n;
		cin >> n;
		vector<ll> a(n + 1);
		FOR(i, 1, n)	cin >> a[i];
		vector<ll> ans(n + 1, 1);
		for (ll i = 1; i <= n; i++)
		{
			for (ll j = i * 2; j <= n; j += i)
			{
				if (a[j] > a[i])
				{
					ans[j] = max(ans[i] + 1, ans[j]);
				}
			}
		}
		// for (auto itr : ans)
		// 	cout << itr << " ";
		// cout << END;
		cout << *max_element(all(ans)) << END;
	}
	return 0;
}