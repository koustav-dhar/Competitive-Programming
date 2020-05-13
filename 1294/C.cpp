#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int f[N],j=0;
        for(int i=2;i<=sqrt(N);i++)
        {
            if(N%i==0)
            {
                f[j++]=i;
            }
        }
        int flag=0;
        for(int i=0;i<j;i++)
        {
            for(int k=i+1;k<j;k++)
            {
                int a=f[i]*f[k],x=N/a;
                if(N%(N/a)==0 && (N/a)!=f[i] && (N/a)!=f[k])
                {
                    cout<<"YES"<<endl;
                    cout<<f[i]<<" "<<f[k]<<" "<<N/a<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        if(flag==0)
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}