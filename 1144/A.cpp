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
#define MAXN 10000001
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
		string s;
		cin >> s;
		if (s.length() == 1)
			cout << "Yes\n";
		else
		{
			unordered_map<ll, ll> check;
			char low = s[0], high = s[0];
			bool flag = true;
			for (char ch : s)
			{
				check[ch]++;
				if (check[ch] > 1)
				{
					flag = false;
					break;
				}
				low = min(low, ch);
				high = max(high, ch);
			}
			if (flag)
			{
				// cout << low << " " << high << END;
				if (high - low + 1 == s.length())
					cout << "Yes\n";
				else
					cout << "No\n";
			}
			else
				cout << "No\n";
		}
	}
	return 0;
}