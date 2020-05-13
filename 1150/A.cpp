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
	ll n, m, r;
	cin >> n >> m >> r;
	vector<ll> s(n), b(m);
	ll maxd = INT_MAX, maxe = -1;
	loop(i, n)
	{
		cin >> s[i];
		maxd = min(maxd, s[i]);
	}
	loop(i, m)
	{
		cin >> b[i];
		maxe = max(maxe, b[i]);
	}
	ll profit = 0, loss = 0, sh = r / maxd;
	loss = sh * maxd;
	profit = maxe * sh;
	// cout << loss << " " << profit << END;
	if (loss > profit)
		cout << r << END;
	else
		cout << r - loss + profit << END;
	return 0;
}