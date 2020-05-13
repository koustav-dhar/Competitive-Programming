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
	vector<ll> a(4);
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	bool flag=false;
	for(ll mask=1;mask<15;mask++)
	{
		ll sum1=0,sum2=0;
		for(ll i=0;i<4;i++)
		{
			ll f=1<<i;
			if((f&mask)==0)
				sum1+=a[i];
			else
				sum2+=a[i];
		}
		if(sum1==sum2)
		{
			flag=true;
			break;
		}
	}
	if(flag)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}