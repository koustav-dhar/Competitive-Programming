#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ff first
#define ss second
#define END "\n"
#define pb push_back
#define MOD 1000000007
#define MODU 998244353
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

signed main() {
#ifndef ONLINE_JUDGE
	freeopen("input.txt", "r", stdin);
	freeopen("output.txt", "w", stdout);
#endif
	ll n, m;
	cin >> n >> m;
	vector<ll> v[n + 1];
	ll a, b;
	for (ll i = 0; i < m; i++)
		cin >> a >> b , v[a].pb(b) , v[b].pb(a);
	if (n <= 6)
		cout << m << END;
	else
	{
		ll ans = 0, mn = INT_MAX;
		for (ll i = 1; i < n; i++)
		{
			for (ll j = i + 1; j <= n; j++)
			{
				ll x = 0;
				for (auto child1 : v[i])
				{
					for (auto child2 : v[j])
					{
						if (child1 == child2)
						{
							x++;
						}
					}
				}
				mn = min(mn, x);
			}
		}
		ans = (m - mn > 0) ? m - mn : 0;
		cout << ans << END;
	}
	return 0;
}