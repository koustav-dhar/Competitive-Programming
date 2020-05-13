#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	// your code goes here
	ll a,b;
	cin>>a>>b;
	int flag=1;
	vector<ll> v;
	v.push_back(b);
	while(b>a)
	{
		if(b%10==1)
		{
			b/=10;
			v.push_back(b);
		}
		else
		{
			if(b%2==1)
			{
				flag=0;
				break;
			}
			else
			{
				b/=2;
				v.push_back(b);
			}
		}
		
	}
	if(flag==1 && b==a)
		{
			cout<<"YES\n";
			cout<<v.size()<<endl;
			for(auto itr=v.end()-1;itr>=v.begin();itr--)
			{
				cout<<*itr<<" ";
			}
		}
		else 
			cout<<"NO";
	return 0;
}