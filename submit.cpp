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
#define go(c,itr) for(auto itr=(c).begin(); itr!=(c).end(); itr++)
#define back(c,itr) for(auto itr=(c).rbegin(); itr!=(c).rend(); itr++)
#define END "\n"
#define pb push_back
#define inf 9e18
#define MOD 1000000007
#define MODU 998244353
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 50001
const string alpha = "abcdefghijklmnopqrstuvwxyz";
struct segsums
{
	ll maxsum, maxprefsum, maxsufsum, sum;
};
vector<segsums> segtree(4 * MAXN);
vector<ll> a(MAXN);
void buildtree(ll si, ll ss, ll se)
{
	if (ss == se)
	{
		segtree[si].maxsum = a[ss]; // cout << si << " : " << segtree[si] << END;
		segtree[si].maxprefsum = a[ss];
		segtree[si].maxsufsum = a[ss];
		segtree[si].sum = a[ss];
	}
	else
	{
		ll mid = (ss + se) / 2;
		buildtree(2 * si, ss, mid);
		buildtree(2 * si + 1, mid + 1, se);
		segtree[si].sum = segtree[2 * si].sum + segtree[2 * si + 1].sum;
		segtree[si].maxprefsum = max(segtree[2 * si].maxprefsum, segtree[2 * si].sum + segtree[2 * si + 1].maxprefsum);
		segtree[si].maxsufsum = max(segtree[2 * si + 1].maxsufsum, segtree[2 * si].maxsufsum + segtree[2 * si + 1].sum);
		segtree[si].maxsum = max(max(segtree[2 * si].maxsum, segtree[2 * si + 1].maxsum), segtree[2 * si].maxsufsum + segtree[2 * si + 1].maxprefsum);
		// cout << si << " : " << segtree[si] << END;
	}
}
segsums query(ll l, ll r, ll si, ll ss, ll se)
{
	segsums result;
	result.maxsum = result.sum = result.maxprefsum = result.maxsufsum = (-1) * inf;
	if (l > se || r < ss)
		return result;
	if (l <= ss && r >= se)
		return segtree[si];
	ll mid = (se + ss) / 2;
	if (l > mid)
		return query(l, r, 2 * si + 1, mid + 1, se);
	if (r <= mid)
		return query(l, r, 2 * si, ss, mid);
	segsums left = query(l, r, 2 * si, ss, mid);
	segsums right = query(l, r, 2 * si + 1, mid + 1, se);
	result.sum = left.sum + right.sum;
	result.maxprefsum = max(left.maxprefsum, left.sum + right.maxprefsum);
	result.maxsufsum = max(right.maxsufsum, left.maxsufsum + right.sum);
	result.maxsum = max(max(left.maxsum, right.maxsum), left.maxsufsum + right.maxprefsum);

	return result;
}
signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	ll n;
	cin >> n;
	FOR(i, 1, n)	cin >> a[i];
	buildtree(1, 1, n);
	ll q;
	cin >> q;
	while (q--)
	{
		ll l, r;
		cin >> l >> r;
		cout << query(l, r, 1, 1, n).maxsum << END;
	}
	return 0;
}