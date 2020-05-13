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
#define MAXN 100001
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
	ll n;
	cin >> n;
	string s;
	cin >> s;
	unordered_map<char, ll> f;
	for (char c : s)
		f[c]++;
	ll zero = 0, one = 0;
	zero = f['z'];
	one = f['o'] - f['z'];
	loop(i, one)
	cout << 1 << " ";
	loop(i, zero)
	cout << 0 << " ";
	return 0;
}