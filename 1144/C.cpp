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
	ll n;
	cin >> n;
	vector<ll> a(n), a1, a2;
	loop(i, n)	cin >> a[i];
	unordered_map<ll, ll> freq;
	loop(i, n)
	{
		freq[a[i]]++;
	}
	bool flag = true;
	for (auto itr = freq.begin(); itr != freq.end(); itr++)
	{
		if (itr->ss > 2)
		{
			flag = false;
			break;
		}
		if (itr->ss > 1)
		{
			a1.pb(itr->ff);
			a2.pb(itr->ff);
		}
		else
		{
			a1.pb(itr->ff);
		}
	}
	if (flag)
	{
		cout << "YES" << END;
		sort(a1.begin(), a1.end());
		sort(a2.begin(), a2.end(), greater<ll>());
		cout << a1.size() << END;
		loop(i, a1.size())	cout << a1[i] << " ";
		cout << END;
		cout << a2.size() << END;
		loop(i, a2.size())	cout << a2[i] << " ";
		cout << END;
	}
	else
		cout << "NO" << END;
	return 0;
}