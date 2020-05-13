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
void task(bool flag)
{
	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";
}
ll assign(ll i, ll j, ll n)
{
	return i * n + j;
}
signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	ll n;
	cin >> n;
	vector<string> tile(n);
	loop(i, n)
	{
		cin >> tile[i];
	}
	bool flag = true;
	unordered_map<ll, ll> check;
	FOR(i, 1, n - 2)
	{
		FOR(j, 1, n - 2)
		{
			if (tile[i][j] == '.' && check[assign(i, j, n)] == 0)
			{
				if (tile[i + 1][j] == '.' && tile[i - 1][j] == '.' && tile[i][j + 1] == '.' && tile[i][j - 1] == '.')
					if (check[assign(i + 1, j, n)] == 0 && check[assign(i - 1, j, n)] == 0 && check[assign(i, j + 1, n)] == 0 && check[assign(i, j - 1, n)] == 0)
					{
						check[assign(i, j, n)] = 1;
						check[assign(i + 1, j, n)] = 1;
						check[assign(i - 1, j, n)] = 1;
						check[assign(i, j + 1, n)] = 1;
						check[assign(i, j - 1, n)] = 1;
					}
			}
		}
	}
	loop(i, n)
	{
		loop(j, n)
		{
			if (tile[i][j] == '.' && check[assign(i, j, n)] == 0)
			{
				flag = false;
				break;
			}
		}
		if (!flag)
		{
			break;
		}
	}
	task(flag);
	return 0;
}