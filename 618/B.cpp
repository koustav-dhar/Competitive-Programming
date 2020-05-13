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
	vector<vector<ll>> a(n, vector<ll>(n));
	loop(i, n)
	{
		loop(j, n)
		{
			cin >> a[i][j];
		}
	}
	vector<ll> p(n);
	ll defaulter = n;
	loop(i, n)
	{
		unordered_map<ll, ll> freq;
		loop(j, n)
		{
			freq[a[i][j]]++;
		}
		ll val, maxf = INT_MIN;
		for (auto itr = freq.begin(); itr != freq.end(); itr++)
		{
			if (itr->ss > maxf)
			{
				maxf = itr->ss;
				val = itr->ff;
			}
		}
		if (maxf == 1)
		{
			p[i] = defaulter;
			defaulter--;
		}
		else
		{
			p[i] = val;
		}
	}
	loop(i, n)	cout << p[i] << " ";
	return 0;
}