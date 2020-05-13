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
	if (n <= 2)
	{
		cout << "No" << END;
	}
	else
	{
		cout << "Yes" << END;
		if (n % 2 == 0)
		{
			cout << 1 << " " << n / 2 << END;
			cout << n - 1 << " ";
			FOR(i, 1, n)
			{
				if (i == n / 2)
					continue;
				cout << i << " ";
			}
		}
		else
		{
			cout << 1 << " " << n << END;
			cout << n - 1 << " ";
			FOR(i, 1, n - 1)
			{
				cout << i << " ";
			}
		}
	}
	return 0;
}