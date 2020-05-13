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
#define END "\n"
#define pb push_back
#define MOD 1000000007
#define MODU 998244353
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 100001
const string alpha = "abcdefghijklmnopqrstuvwxyz";

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, x;
		cin >> n >> x;
		vector<ll> a(n);
		loop(i, n)	cin >> a[i];
		ll ans = INT_MAX;
		loop(i, n)
		{
			if (x % a[i] == 0)
			{
				ans = min(ans, x / a[i]);
			}
			else
			{
				if (a[i] > x)
					ans = min(ans, ll(2));
				else
					ans = min(ans, x / a[i] + 1);
			}
		}
		cout << ans << END;
	}
	return 0;
}