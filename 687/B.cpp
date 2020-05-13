#include <bits/stdc++.h>
using namespace std;
#define MAXN   100001 
  
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
	sieve();
	int n,k;
	cin>>n>>k;
	int el;
	unordered_map<int,int> m,ctr;
	for(int i=0;i<n;i++)
	    cin>>el , m[el]++;
	bool flag=true;
	while(k!=1)
	{
	    if(m[spf[k]]>0 && ctr[spf[k]]==0)
	    {
	        ctr[spf[k]]++;
	        k/=spf[k];
	    }
	    else
	    {
	        flag=false;
	        break;
	    }
	}
	if(flag)
	    cout<<"Yes\n";
	else
	    cout<<"No\n";
	return 0;
}