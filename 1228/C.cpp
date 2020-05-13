#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll binexp(ll a, ll b, ll m) {
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
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll x,n;
	cin>>x>>n;
	set<ll> primes;
	for(ll i=2;i<=sqrt(x);i++)
	{
		while(x%i==0)
		{
			primes.insert(i);
			x/=i;
		}
	}
	if(x!=1)
		primes.insert(x);
	ll ans=1;
	// for(auto p : primes)
	// 	cout<<p<<" ";
	for(auto p : primes)
	{
		ll ctr=0,j=1;
		while((n/ll(pow(p,j)))>0)
		{
			ctr+=(n/ll(pow(p,j)));
			j++;
		}
		ans = (ans * binexp(p,ctr,MOD)) % MOD;
	}
	cout<<ans<<endl;
	return 0;
}