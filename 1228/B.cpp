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
	ll h,w;
	cin>>h>>w;
	vector<ll> rh(h),cw(w);
	for(ll i=0;i<h;i++)
		cin>>rh[i];
	for(ll i=0;i<w;i++)
		cin>>cw[i];
	ll matrix[h][w];
	for(ll i=0;i<h;i++)
	{
		for(ll j=0;j<w;j++)
		{
			matrix[i][j]=-1;
		}
	}
	for(ll i=0;i<h;i++)
	{
		ll j;
		for(j=0;j<rh[i];j++)
		{
			matrix[i][j]=1;
		}
		if(j<w)
		{
			matrix[i][j]=0;
		}
	}
	for(ll j=0;j<w;j++)
	{
		ll i;
		for(i=0;i<cw[j];i++)
		{
			if(matrix[i][j]==0)
			{
				cout<<"0\n";
				return 0;
			}
			else
			{
				matrix[i][j]=1;
			}
		}
		if(i<h)
		{
			if(matrix[i][j]==1)
			{
				cout<<"0\n";
				return 0;
			}
			else
			{
				matrix[i][j]=0;
			}
		}
	}
	ll ans=0;
	for(ll i=0;i<h;i++)
	{
		for(ll j=0;j<w;j++)
		{
			if(matrix[i][j]==-1)
				ans++;
		}
	}
	cout<<binexp(2,ans,MOD)<<"\n";
	return 0;
}