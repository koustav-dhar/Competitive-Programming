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
	vector<ll> p(n);
	loop(i, n)	cin >> p[i];
	set<ll> track;
	vector<ll> r(n, 0);
	track.insert(p[0]);
	ll maxm = p[0];
	r[0] = 1;
	FOR(i, 1, n - 1)
	{
		if (track.lower_bound(p[i]) == track.end())
		{
			r[i] = 1;
		}
		else
		{
			r[i] = 0;
		}
		track.insert(p[i]);
		maxm = max(maxm, p[i]);
	}
	// loop(i, n)	cout << r[i] << " ";
	// cout << END;
	vector<ll> x(n, 0);
	track.clear();
	maxm = p[0];
	ll maxind = 0;
	loop(i, n)
	{
		if (r[i] == 1)
		{
			x[i] = -1;
		}
	}
	// loop(i, n)	cout << x[i] << " ";
	// cout << END;
	loop(i, n)
	{
		// loop(i, n)	cout << x[i] << " ";
		// cout << END;
		if (r[i] == 0)
		{
			if (*track.lower_bound(p[i]) == maxm)
			{
				x[maxind]++;
			}
		}
		track.insert(p[i]);
		if (p[i] > maxm)
		{
			maxm = p[i];
			maxind = i;
		}
	}
	// loop(i, n)	cout << x[i] << " ";
	// cout << END;
	ll ans = 0;
	maxm = -1;
	loop(i, n)
	{
		if (x[i] > maxm)
		{
			maxm = x[i];
			ans = p[i];
		}
		else if (x[i] == maxm)
		{
			if (p[i] < ans)
			{
				ans = p[i];
			}
		}
	}
	if (maxm == -1)
		cout << 1 << END;
	else
		cout << ans << END;
	return 0;
}