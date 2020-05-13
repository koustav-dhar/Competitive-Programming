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
	vector<ll> a(n);
	loop(i, n)	cin >> a[i];
	vector<ll> pref(n + 1);
	pref[0] = 0;
	FOR(i, 1, n )
	{
		pref[i] = a[i - 1] ^ pref[i - 1];
	}
	// loop(i, n + 1)	cout << pref[i] << " ";
	// cout << END;
	vector<vector<ll>> count(2, vector<ll>(1 << 20, 0));
	loop(i, n + 1)
	{
		count[i % 2][pref[i]]++;
	}
	ll ans = 0;
	loop(i, 2)
	{
		loop(j, 1 << 20)
		{
			if (count[i][j] > 1)
			{
				// cout << j << " " << count[i][j] << END;
				ans += count[i][j] * (count[i][j] - 1) / 2;
			}
		}
	}
	cout << ans << END;
	return 0;
}