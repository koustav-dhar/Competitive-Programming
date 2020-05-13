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

struct moves
{
	ll times;
	string move;
};
signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	ll n, m, k;
	cin >> n >> m >> k;
	if (k > (4 * n * m - 2 * n - 2 * m))
	{
		cout << "NO" << END;
	}
	else
	{
		cout << "YES" << END;
		vector<moves> ans;
		if (n == 1)
		{
			ans.pb({min(k, m - 1), "R"});
			k -= min(k, m - 1);
			if (k > 0)
			{
				ans.pb({k, "L"});
				k = 0;
			}
		}
		else if (m == 1)
		{
			ans.pb({min(k, n - 1), "D"});
			k -= min(k, n - 1);
			if (k > 0)
			{
				ans.pb({k, "U"});
				k = 0;
			}
		}
		else if (k >= (n - 1))
		{
			ans.pb({n - 1, "D"});
			k -= (n - 1);
			if (k >= (n - 1))
			{
				ans.pb({n - 1, "U"});
				k -= (n - 1);
				ll col = 1;
				while (k > 0 && col < m)
				{
					if (k >= 3)
					{
						ans.pb({min(k / 3, n - 1), "RDL"});
						k -= min((k / 3) * 3, 3 * (n - 1));
						if (k > 0)
						{
							ans.pb({1, "R"});
							k--;
							if (k > 0)
							{
								ans.pb({min(k, n - 1), "U"});
								k -= min(k, n - 1);
							}
						}
						col++;
					}
					else
					{
						ans.pb({1, "R"});
						k--;
						if (k > 0)
						{
							ans.pb({1, "D"});
							k--;
						}
					}
				}
			}
			else
			{
				if (k > 0)
				{
					ans.pb({k, "U"});
					k = 0;
				}
			}
		}
		else
		{
			if (k > 0)
			{
				ans.pb({k, "D"});
				k = 0;
			}
		}
		if (k > 0)
		{
			ans.pb({min(k, m - 1), "L"});
			k -= min(k, m - 1);
		}
		cout << ans.size() << END;
		loop(i, ans.size())
		{
			cout << ans[i].times << " " << ans[i].move << END;
		}
	}
	return 0;
}