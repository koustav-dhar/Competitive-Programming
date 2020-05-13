#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n],p[m];
        for(int i=0;i<n;i++)    cin>>a[i];
        for(int i=0;i<m;i++)    cin>>p[i];
        unordered_map<int,int> mm;
        for(int i=0;i<m;i++)    mm[p[i]]++;
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-1-i;j++)
            {
                if(mm[j+1]>0)
                {
                    if(a[j]>a[j+1])
                    {
                        int temp=a[j];
                        a[j]=a[j+1];
                        a[j+1]=temp;
                    }
                }
            }
        }
        int flag=0;
        for(int i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
            {
                flag=1;
                break;
            }
        }
        if(flag==1) cout<<"NO"<<endl;
        else        cout<<"YES"<<endl;
    }
}