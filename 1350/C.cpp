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
#define MAXN 1000002
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
	sieve();
	ll n;
	cin >> n;
	vector<ll> a(n);
	loop(i, n)	cin >> a[i];
	ll ans = 1;
	unordered_map<ll, ll> track;
	loop(i, n)
	{
		ll val = 1;
		while (a[i] > 1)
		{
			if (val % spf[a[i]] == 0)
				val *= spf[a[i]];
			else
				val = spf[a[i]];
			track[val]++;
			a[i] /= spf[a[i]];
		}
	}
	go(track, itr)
	{
		// cout << itr->ff << " " << itr->ss << END;
		if (itr->ss >= (n - 1))
		{
			ll val = 1;
			while (ans % spf[itr->ff] == 0)
				ans /= spf[itr->ff] , val *= spf[itr->ff];
			if (itr->ff > val)
				ans *= itr->ff;
			else
				ans *= val;
			// cout << ans << END;
		}
	}
	cout << ans << END;
	return 0;
}