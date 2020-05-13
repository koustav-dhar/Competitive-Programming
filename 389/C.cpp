#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<ll> x, ll mid)
{
	for(ll i=0;i<x.size();i++)
	{
		if(x[i]<(i/mid))
			return false;
	}
	return true;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<ll> x;
	ll el;
	for(ll i=0;i<n;i++)
		cin>>el , x.push_back(el);
	sort(x.begin(),x.end());
	ll lo=1,hi=100,best=100,mid;
	while(lo<hi)
	{
		mid=(lo+hi)/2;
		if(check(x,mid))
		{
			best=mid;
			hi=mid;
		}
		else
		{
			lo=mid+1;
		}
	}
	cout<<best<<endl;
	return 0;
}