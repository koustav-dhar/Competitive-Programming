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
	cases
	{
		string s;
		cin >> s;
		map<pair<pair<ll, ll>, pair<ll, ll>>, ll> check;
		ll x = 0, y = 0, xx = 0, yy = 0, ans = 0;
		loop(i, s.length())
		{
			switch (s[i])
			{
			case 'N': ++yy;
				break;
			case 'S': --yy;
				break;
			case 'W': --xx;
				break;
			case 'E': ++xx;
				break;
			}
			if (check[ {{x, y}, {xx, yy}}] > 0)
			++ans;
			else
				ans += 5;
			check[ {{x, y}, {xx, yy}}] = 1;
			check[ {{xx, yy}, {x, y}}] = 1;
			x = xx;
			y = yy;
		}
		cout << ans << END;
	}
	return 0;
}