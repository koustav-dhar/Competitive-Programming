#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;

signed main()
{
    fast
    ll n,d;
    cin>>n>>d;
    ll arr[d]={0};
    for(ll i=0;i<d;i++)
    {
        string s;
        cin>>s;
        for(ll j=0;j<n;j++)
        {
            if(s[j]=='1')
                arr[i]++;
        }
        // cout<<arr[i]<<"\n";
        if(arr[i]==n)
            arr[i]=1;
        else
            arr[i]=0;
    }
    ll ans=0;
    // for(ll i=0;i<d;i++)
    //     cout<<arr[i]<<" ";
    // cout<<"\n";
    for(ll i=0;i<d;i++)
    {
        if(arr[i]==0)
        {
            ll count=0;
            while(arr[i]==0)
            {
                count++;
                i++;
            }
            if(count>ans)
                ans=count;
            i--;
        }
    }
    cout<<ans<<endl;
}