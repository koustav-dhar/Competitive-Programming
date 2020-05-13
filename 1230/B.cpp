#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	if(n==1 && k==1)
	{
		cout<<0<<endl;
	}
	else
	{
		ll ctr=0;
		for(ll i=0;i<s.length();i++)
		{
			if(ctr>=k)
			{
				break;
			}
			else
			{
				if(i==0)
				{
					if(s[i]>'1')
					{
						s[i]='1';
						ctr++;
					}
				}
				else
				{
					if(s[i]>'0')
					{
						s[i]='0';
						ctr++;
					}
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}