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
	loop(i, n)	cin >> a[i];
	vector<ll> prefix(n + 1, 0);
	FOR(i, 1, n)
	{
		prefix[i] = prefix[i - 1] + a[i - 1];
	}
	set<ll> check;
	check.insert(0);
	ll i = 0, j = 0, ans = 0;
	//#### Using Two Pointers ####//
	while (i < n)
	{
		while (j < n && check.find(prefix[j + 1]) == check.end())
		{
			j++;
			check.insert(prefix[j]);
		}
		ans += j - i;
		check.erase(prefix[i]);
		i++;
	}
	cout << ans << END;
	return 0;
}