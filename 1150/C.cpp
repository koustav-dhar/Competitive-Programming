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
	ll n;
	cin >> n;
	vector<ll> a(n);
	ll c1 = 0, c2 = 0;
	loop(i, n)
	{
		cin >> a[i];
		if (a[i] == 1)
			c1++;
		else
			c2++;
	}
	vector<ll> ans;
	if (c2 > 0)
	{
		ans.pb(2);
		c2--;
	}
	if (c1 > 0)
	{
		ans.pb(1);
		c1--;
	}
	while (c2 > 0)
	{
		ans.pb(2);
		c2--;
	}
	while (c1 > 0)
	{
		ans.pb(1);
		c1--;
	}
	loop(i, n)
	{
		cout << ans[i] << " ";
	}
	return 0;
}