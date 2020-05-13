#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define LOOP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ff first
#define ss second
#define END "\n"
#define pb push_back
#define MOD 1000000007
#define MODU 998244353
#define MODHERE 9223372036854775807
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll binexp(ll a, ll b, ll m=MODHERE) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll ans=MODHERE;
void calc(vector<ll> x,vector<ll> y,vector<ll> z)
{
	for(auto i:x)
	{
		vector<ll>::iterator j,k;
		j=upper_bound(y.begin(),y.end(),i);
		k=lower_bound(z.begin(),z.end(),i);
		if(j==y.begin() || k==z.end())
			continue;
		else
		{
			j--;
			ans = min(ans,(binexp(*j-*k,2) + binexp(*j-i,2) + binexp(*k-i,2)));
		}
	}
	// return MODHERE;
}
int main()
{
    fast
    ll t;
    cin>>t;
    while(t--)
    {
		ll nr,ng,nb;
		cin>>nr>>ng>>nb;
		vector<ll> r,g,b;
		ll el;
		for(ll i=0;i<nr;i++)
			cin>>el , r.pb(el);
		for(ll i=0;i<ng;i++)
			cin>>el , g.pb(el);
		for(ll i=0;i<nb;i++)
			cin>>el , b.pb(el);
		sort(r.begin(),r.end());
		sort(g.begin(),g.end());
		sort(b.begin(),b.end());
		ans=MODHERE;
		calc(r,g,b);
		calc(r,b,g);
		calc(g,b,r);
		calc(g,r,b);
		calc(b,r,g);
		calc(b,g,r);
		
		cout<<ans<<END;
    }
    return 0;
}