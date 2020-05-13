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
#define MAXN 10000001
const string alpha = "abcdefghijklmnopqrstuvwxyz";


signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	ll n;
	cin >> n;
	vector<ll> a(n), even, odd;
	loop(i, n)
	{
		cin >> a[i];
		if (a[i] & 1)
			odd.pb(a[i]);
		else
			even.pb(a[i]);
	}
	sort(odd.begin(), odd.end());
	sort(even.begin(), even.end());
	if (odd.size() == even.size())
		cout << 0 << END;
	else if (odd.size() > even.size())
	{
		ll ans = 0;
		loop(i, odd.size() - even.size() - 1)
		ans += odd[i];
		cout << ans << END;
	}
	else
	{
		ll ans = 0;
		loop(i, even.size() - odd.size() - 1)
		ans += even[i];
		cout << ans << END;
	}
	return 0;
}