#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define loop(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define END "\n"
#define pb push_back
#define MOD 1000000007
#define MODU 998244353
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 100001
const string alpha = "abcdefghijklmnopqrstuvwxyz";

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
	ll n;
	cin >> n;
	vector<vector<ll>> a(n, vector<ll>(n));
	loop(i, n)
	{
		loop(j, n)
		{
			cin >> a[i][j];
		}
	}
	vector<ll> ans(n);
	loop(i, n)
	{
		ans[i] = *max_element(a[i].begin(), a[i].end());
		loop(j, n)
		{
			if (a[i][j] == 0)
				continue;
			else
				ans[i] = __gcd(ans[i], a[i][j]);
		}
	}
	map<pair<ll, ll>, ll> call;
	loop(i, n )
	{
		FOR(j, 0, n - 1)
		{
			if (a[i][j] == 0)
				continue;
			else
				call[ {i, j}] = (ans[i] * ans[j] / a[i][j]);
		}
	}
	FOR(i, 1, n - 2)
	{
		ll val = ll(sqrt(call[ {i - 1, i}]*call[ {i, i + 1}] / call[ {i - 1, i + 1}]));
		ans[i] /= val;
	}
	if (call[ {1, 2}] != 0)
	{
		ll val = ll(sqrt(call[ {0, 1}]*call[ {0, 2}] / call[ {1, 2}]));
		ans[0] /= val;
		val = ll(sqrt(call[ {0, n - 1}]*call[ {1, n - 1}] / call[ {0, 1}]));
		ans[n - 1] /= val;
	}
	// cout << ans[0] << " ";
	FOR(i, 0, n - 1)	cout << ans[i] << " ";
	return 0;
}