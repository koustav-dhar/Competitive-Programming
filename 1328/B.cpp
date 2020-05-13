#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		vector<ll> v;
		v.push_back(1);
		for(int i=2;i<n;i++)
			v.push_back(i+v[i-2]);
		//for(ll i:v)	cout<<i<<" ";
		ll left,right;
		vector<ll>::iterator itr;
		itr=lower_bound(v.begin(),v.end(),k);
		//cout<<*itr;
		if(*itr==k)
		{
			left=n-2-(itr-v.begin());
			right=left+1;
		}
		else
		{
			//itr--;
			left=n-2-(itr-v.begin());
			itr--;
			right=n-(k-*itr);
		}
		for(int i=0;i<n;i++)
		{
			if(i==left || i==right)
				cout<<"b";
			else
				cout<<"a";
		}
		cout<<endl;
	}
	return 0;
}