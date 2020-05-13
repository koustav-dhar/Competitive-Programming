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
#define MAXN 1000001
const string alpha = "abcdefghijklmnopqrstuvwxyz";

ll f(ll mid, vector<ll> a)
{
	ll maxm = INT_MIN;
	vector<ll> b;
	loop(i, a.size())
	{
		if (a[i] == -1)
			b.pb(mid);
		else
			b.pb(a[i]);
	}
	loop(i, b.size() - 1)
	{
		maxm = max(maxm, abs(b[i + 1] - b[i]));
	}
	// cout << mid << " : " << maxm << END;
	return maxm;
}

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
		ll n;
		cin >> n;
		vector<ll> a(n);
		loop(i, n)	cin >> a[i];
		ll lo = 0, hi = *max_element(a.begin(), a.end()), m1, m2;
		// ll iter = 0;
		while (lo <= hi)
		{
			m1 = lo + (hi - lo) / 3;
			m2 = hi - (hi - lo) / 3;
			// cout << m1 << " " << m2 << END;
			ll f1 = f(m1, a);
			ll f2 = f(m2, a);
			if (f1 > f2)
				lo = m1 + 1;
			else
				hi = m2 - 1;
			// iter++;
		}
		cout << f(lo, a) << " " << lo << END;
	}
	return 0;
}