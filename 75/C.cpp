#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	int a,b;
	scanf("%d%d",&a,&b);
	int g=__gcd(a,b);
	vector<int> v1,v2;
	int sq=sqrt(g);
	for(int i=1;i<=sq;i++)
	{
		if(g%i==0)
		{
			if(i*i==g)
			{
				v1.push_back(i);
			}
			else
			{
				v1.push_back(i);
				v2.push_back(g/i);
			}
		}
	}
	for(int i=v2.size()-1;i>=0;i--)
	{
		v1.push_back(v2[i]);
	}
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int low,high;
		scanf("%d%d",&low,&high);
		vector<int>::iterator lower, higher;
		lower=lower_bound(v1.begin(),v1.end(),low);
		if(lower==v1.end())
			cout<<"-1\n";
		else if(*lower>high)
			cout<<"-1\n";
		else if(*lower==high)
			cout<<high<<endl;
		else
		{
			higher=lower_bound(v1.begin(),v1.end(),high);
			if(*higher==high)
			    cout<<high<<endl;
			else
			    cout<<*(higher-1)<<endl;
		}
	}
	return 0;
}