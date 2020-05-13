#include <bits/stdc++.h>
using namespace std;
#define MAXN   1000001 
  
int spf[MAXN]; 
  
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
        spf[i] = i; 
  
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
int main() {
	// your code goes here
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
	sieve();
	int n,k;
	scanf("%d%d",&n,&k);
	int a[n];
	for(int i=0;i<n;i++)
	    scanf("%d",&a[i]);
	bool flag=true;
	unordered_map<int,int> mk,mi,check;
	while(k!=1)
	{
        mk[spf[k]]++;
        k/=spf[k];
	}
	for(int i=0;i<n;i++)
	{
	    if(check[a[i]]==0)
	    {
    	    unordered_map<int,int> mii;
    	    while(a[i]!=1)
    	    {
    	        mii[spf[a[i]]]++;
    	        a[i]/=spf[a[i]];
    	    }
    	    for(auto itr=mii.begin();itr!=mii.end();itr++)
    	    {
    	        if((itr->second) > mi[itr->first])
    	        {
    	            mi[itr->first] = itr->second;
    	        }
    	    }
    	    check[a[i]]=1;
	    }
	}
	for(auto itr=mk.begin();itr!=mk.end();itr++)
    {
        //cout<<itr->first<<" : "<<itr->second<<endl;
        if(mi[itr->first]<mk[itr->first])
        {
            flag=false;
            break;
        }
    }
	if(flag)
	    printf("Yes\n");
	else
	    printf("No\n");
	return 0;
}