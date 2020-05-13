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
struct moves
{
	ll type;
	ll ind1;
	ll ind2;
};
signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	ll n;
	cin >> n;
	vector<ll> a(n);
	unordered_map<ll, ll> freq;
	loop(i, n)	cin >> a[i] , freq[a[i]]++;
	ll el, maxf = INT_MIN;
	for (auto itr = freq.begin(); itr != freq.end(); itr++)
	{
		if (itr->ss > maxf)
		{
			el = itr->ff;
			maxf = itr->ss;
		}
	}
	ll pos = -1;
	loop(i, n)
	{
		if (a[i] == el)
		{
			pos = i;
			break;
		}
	}
	vector<moves> ans;
	FORD(i, pos - 1, 0)
	{
		if (a[i] > a[i + 1])
		{
			ans.pb({2, i, i + 1});
			a[i] = a[i + 1];
		}
		else
		{
			ans.pb({1, i, i + 1});
			a[i] = a[i + 1];
		}
	}
	FOR(i, 0, n - 1)
	{
		if (a[i] > el)
		{
			ans.pb({2, i, i - 1});
			a[i] = a[i - 1];
		}
		else if (a[i] < el)
		{
			ans.pb({1, i, i - 1});
			a[i] = a[i - 1];
		}
	}
	cout << ans.size() << END;
	loop(i, ans.size())
	{
		cout << ans[i].type << " " << ans[i].ind1 + 1 << " " << ans[i].ind2 + 1 << END;
	}
	return 0;
}