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
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		string to;
		if (k == n / 2)
		{
			loop(i, k)
			{
				to += "()";
			}
		}
		else
		{
			loop(i, k - 1)
			{
				to += "()";
			}
			loop(i, n / 2 - k + 1)
			{
				to += "(";
			}
			loop(i, n / 2 - k + 1)
			{
				to += ")";
			}
		}
		// cout << to << END;
		vector<pair<ll, ll>> moves;
		loop(i, n)
		{
			if (s[i] == to[i])
				continue;
			else
			{
				ll j = i;
				while (j < n)
				{
					if (s[j] == to[i])
					{
						break;
					}
					j++;
				}
				moves.pb({i + 1, j + 1});
				for (ll x = 0; x <= (j - i) / 2; x++)
				{
					char temp = s[i + x];
					s[i + x] = s[j - x];
					s[j - x] = temp;
				}
			}
		}
		cout << moves.size() << END;
		for (auto el : moves)
			cout << el.ff << " " << el.ss << END;
	}
	return 0;
}