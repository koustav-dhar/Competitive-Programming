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

ll binexp(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	ll n;
	cin >> n;
	vector<ll> a[2];
	if (n % 2 == 0)
	{
		ll f = 0, p = n / 2, val = 1;
		if (p % 2 == 0)
		{
			while (p > 0)
			{
				a[f].pb(val);
				a[f].pb(n - val + 1);
				f ^= 1;
				++val;
				--p;
			}
		}
		else
		{
			while (p > 1)
			{
				a[f].pb(val);
				a[f].pb(n - val + 1);
				f ^= 1;
				++val;
				--p;
			}
			if (p == 1)
			{
				a[0].pb(val);
				a[1].pb(n - val);
			}
		}
	}
	else
	{
		a[0].pb(1);
		a[0].pb(n - 1);
		a[1].pb(n);
		ll f = 0, p = (n - 3) / 2, val = 2;
		if (p % 2 == 0)
		{
			while (p > 0)
			{
				a[f].pb(val);
				a[f].pb(n - val);
				f ^= 1;
				++val;
				--p;
			}
		}
		else
		{
			while (p > 1)
			{
				a[f].pb(val);
				a[f].pb(n - val);
				f ^= 1;
				++val;
				--p;
			}
			if (p == 1)
			{
				a[0].pb(val);
				a[1].pb(n - val);
			}
		}
	}
	if ((n * (n + 1) / 2) % 2 == 0)
		cout << 0 << END;
	else
		cout << 1 << END;
	cout << a[0].size() << " ";
	for (auto itr : a[0])
		cout << itr << " ";
	cout << END;
	return 0;
}