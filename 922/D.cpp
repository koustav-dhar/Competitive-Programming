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
struct order
{
	string str;
	ll sc;
	ll hc;
	long double val;
};
bool comp(order a, order b)
{
	if (a.val != b.val)
		return a.val > b.val;
	else if (a.hc != b.hc)
		return a.hc < b.hc;
	else
		return a.sc > b.sc;
}
signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	ll n;
	cin >> n;
	vector<order> a(n);
	loop(i, n)	cin >> a[i].str;
	loop(i, n)
	{
		a[i].hc = a[i].sc = 0;
		ll len = a[i].str.length();
		loop(j, len)
		{
			if (a[i].str[j] == 's')
				++a[i].sc;
			else
				++a[i].hc;
		}
		if (a[i].hc == 0)
			a[i].val = MOD * 1.0;
		else
		{
			a[i].val = ((a[i].sc * 1.0)) / (1.0 * (a[i].hc));
		}
	}
	sort(all(a), comp);
	string s = "";
	loop(i, n)
	{
		s += a[i].str;
	}
	// cout << s << END;
	ll len = s.length();
	vector<ll> prefix(len, 0);
	if (s[len - 1] == 'h')
		prefix[len - 1] = 1;
	FORD(i, len - 2, 0)
	{
		prefix[i] = prefix[i + 1];
		if (s[i] == 'h')
			++prefix[i];
	}
	// for (auto itr : prefix)
	// 	cout << itr << " ";
	// cout << END;
	ll ans = 0;
	// cout << len;
	loop(i, len - 1)
	{
		if (s[i] == 's')
		{
			ans += prefix[i + 1];
		}
	}
	cout << ans << END;
	return 0;
}