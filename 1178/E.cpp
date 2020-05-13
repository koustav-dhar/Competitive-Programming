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

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// fast
	char s[MAXN];
	cin >> s;
	vector<char> ans;
	ll beg = 0, end = strlen(s) - 1;
	// ll n = s.length();
	while (beg <= end)
	{
		if (s[beg] == s[end])
		{
			ans.pb(s[beg]);
			beg++;
			end--;
			continue;
		}
		end--;
		if (s[beg] == s[end])
		{
			ans.pb(s[beg]);
			beg++;
			end--;
			continue;
		}
		ans.pb(s[beg + 1]);
		beg += 2;
		end --;

	}
	loop(i, ans.size())	cout << ans[i];
	reverse(ans.begin(), ans.end());
	FOR(i, 1, ans.size() - 1)	cout << ans[i];
	cout << END;
	return 0;
}