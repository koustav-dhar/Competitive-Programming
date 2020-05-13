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
	ll n, k;
	cin >> n >> k;
	ll ind = 0, temp = n;
	while (temp > 0)
	{
		ind++;
		temp /= 2;
	}
	bool flag = (n == (ll(pow(2, ind)) - 1)) ? true : false;
	ll minc, maxc = ind;
	if (flag)
		minc = 1;
	else
		minc = 2;
	if (k - minc < 0)
	{
		cout << n << END;
	}
	else
	{
		if ((k - minc) % 2 == 0)
			cout << ll(pow(2, ind)) - 1 << END;
		else if (maxc > minc)
			cout << ll(pow(2, ind)) - 1 << END;
		else
			cout << ll(pow(2, ind)) - 2 << END;
	}
	return 0;
}