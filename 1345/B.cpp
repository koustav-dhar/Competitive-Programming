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
#define MAXN 1000001
const string alpha = "abcdefghijklmnopqrstuvwxyz";
void task(bool flag)
{
	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";
}
signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	vector<ll> preh(MAXN, 0);
	preh[1] = 2;
	FOR(i, 2, MAXN - 1)
	{
		preh[i] = i * (i + 1) + i * (i - 1) / 2;
	}
	// FOR(i, 1, 10)
	// cout << preh[i] << " ";
	// cout << END;
	cases
	{
		ll n;
		cin >> n;
		ll ans = 0;
		while (n > 1)
		{
			vector<ll>::iterator low;
			low = upper_bound(preh.begin(), preh.end(), n);
			if (low == preh.begin())
				break;
			low--;
			ans++;
			n -= *low;
			// cout << n << END;
		}
		cout << ans << END;
	}
	return 0;
}