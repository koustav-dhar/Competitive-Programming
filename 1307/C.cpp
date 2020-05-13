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
	string s;
	cin >> s;
	ll n = s.length();
	unordered_map<char, ll> pref[n];

	pref[0][s[0]]++;
	FOR(i, 1, s.length() - 1)
	{
		pref[i] = pref[i - 1];
		pref[i][s[i]]++;
	}
	ll ans = -1;
	for (char ch = 'a'; ch <= 'z'; ch++)
	{
		ans = max(ans, pref[n - 1][ch]);
	}
	map<pair<char, char>, ll> ctr;
	loop(i, n)
	{
		for (char c1 = 'a'; c1 <= 'z'; c1++)
		{
			ctr[ {s[i], c1}] += (pref[n - 1][c1] - pref[i][c1]);
		}
	}
	for (auto itr = ctr.begin(); itr != ctr.end(); itr++)
	{
		ans = max(ans, itr->ss);
	}
	cout << ans << END;
	return 0;
}