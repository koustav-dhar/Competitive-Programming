#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<n-k;i++)
    {
        cout<<i<<" ";
    }
    for(int i=n;i>=n-k;i--)
    {
        cout<<i<<" ";
    }
    return 0;
}