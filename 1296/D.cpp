#include<bits/stdc++.h>
using namespace std;

int main()
{
    //int t;
    //cin>>t;
    
        int n,a,b,k;
        cin>>n>>a>>b>>k;
        int h[n];
        for(int i=0;i<n;i++)
            cin>>h[i];
        int count[n]={0};
        for(int i=0;i<n;i++)
        {
            if(h[i]>a && h[i]<=a+b)
            {
                count[i]=(h[i]-a)/a+1;
            }
            else if(h[i]>a+b && h[i]%(a+b)>a && h[i]<=a+b)
                count[i]=(h[i]%(a+b)-a)/a+1;
            else if(h[i]%(a+b)==0)
                count[i]=b/a+1;
        }
        sort(count,count+n);
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(k<=0)
                break;
            else
            {
                if(count[i]<=k)
                {
                    k-=count[i];
                    c++;
                }
            }
        }
        cout<<c<<endl;
        
    return 0;
}