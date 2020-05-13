#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define loop(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define cases ll T=0;cin>>T;while(T--)
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define END "\n"
#define pb push_back
#define inf 9e18
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
	ll a, b;
	cin >> a >> b;
	if (a == b)
		cout << "infinity\n";
	else if (a < b)
		cout << 0 << END;
	else
	{
		ll ans = 0, n = a - b;
		for (ll i = 1; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				if (n / i == i)
				{
					if (i > b)
						ans++;
				}
				else
				{
					if (i > b)
						ans++;
					if ((n / i) > b)
						ans++;
				}
			}
		}
		cout << ans << END;
	}
	return 0;
}