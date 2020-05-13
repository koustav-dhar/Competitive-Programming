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
	ll l,r;
	cin>>l>>r;
	ll ans=-1;
	for(ll n=l;n<=r;n++)
	{
		ll num=n;
		bool flag=true;
		unordered_map<ll,ll> digs;
		while(num>0)
		{
			ll digit=num%10;
			if(digs[digit]==0)
			{
				digs[digit]++;
			}
			else
			{
				flag=false;
				break;
			}
			num/=10;
		}
		if(flag)
		{
			ans=n;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}