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
	string s;
	cin >> s;
	ll ctr = 0;
	for (char ch : s)
		if (ch == 'a')
			ctr++;
	if (ctr == s.length())
	{
		cout << s << END;
	}
	else if (ctr == 0)
	{
		ll n = s.length();
		bool flag = true;
		for (ll i = 0; i < n / 2; i++)
		{
			if (s[i] != s[n / 2 + i])
			{
				flag = false;
				break;
			}
		}
		if (flag && n % 2 == 0)
		{
			for (ll i = 0; i < n / 2; i++)
				cout << s[i];
			cout << END;
		}
		else
			cout << ":(" << END;
	}
	else
	{
		bool flag = false;
		string s2 = "";
		ll pos = -1;
		for (ll i = 0; i < s.length(); i++)
		{
			if (s[i] == 'a')
				continue;
			else
			{
				if (s2.length() > s.length() - i)
					break;
				else if (s2.length() == s.length() - i)
				{
					ll j = i;
					bool check = true;
					while (i < s.length())
					{
						if (s[i] != s2[i - j])
						{
							check = false;
							break;
						}
						i++;
					}
					if (check)
					{
						pos = j;
						flag = true;
						break;
					}
					else
					{
						flag = false;
						break;
					}
				}
				else
				{
					s2 += s[i];
					// cout << s2 << END;
				}
			}
		}
		if (flag)
		{
			loop(i, pos)
			{
				cout << s[i];
			}
			cout << END;
		}
		else
		{
			cout << ":(" << END;
		}
	}
	return 0;
}