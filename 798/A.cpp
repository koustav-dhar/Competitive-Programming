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
	ll ctr = 0;
	loop(i, s.length() / 2)
	{
		if (s[i] != s[s.length() - i - 1])
			ctr++;
	}
	// cout << ctr << END;
	if (ctr == 1)
		cout << "YES" << END;
	else if (ctr == 0 && s.length() % 2 == 1)
		cout << "YES" << END;
	else
		cout << "NO" << END;
	return 0;
}