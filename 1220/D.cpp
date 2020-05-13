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
	vector<ll> b(n);
	loop(i, n)	cin >> b[i];
	unordered_map<ll, ll> powercount, powerindexing;
	loop(i, n)
	{
		ll val = b[i];
		ll ctr = 0;
		while (val % 2 == 0)
		{
			val /= 2;
			ctr++;
		}
		powercount[ctr]++;
		powerindexing[i] = ctr;
	}
	ll maxp = 0, maxm = INT_MIN;
	for (auto itr = powercount.begin(); itr != powercount.end(); itr++)
	{
		if (itr->ss > maxm)
		{
			maxm = itr->ss;
			maxp = itr->ff;
		}
	}
	vector<ll> ans;
	loop(i, n)
	{
		if (powerindexing[i] != maxp)
		{
			ans.pb(b[i]);
		}
	}
	cout << ans.size() << END;
	for (auto itr : ans)
		cout << itr << " ";
	cout << END;
	return 0;
}