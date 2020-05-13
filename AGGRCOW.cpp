#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(ll num,ll a[],ll n,ll c)
{
    ll count=1,pos1=0,pos2=1;
    while(pos2<n)
    {
        // cout<<count<<endl;
        if(a[pos2]-a[pos1]>=num)
        {
            count++;
            pos1=pos2;
            pos2++;
        }
        else
        {
            pos2++;
        }
        if(count==c)
            return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,c;
        cin>>n>>c;
        ll x[n];
        for(ll i=0;i<n;i++)    cin>>x[i];
        sort(x,x+n);
        ll lo=1,hi=x[n-1],mid,best;
        best=x[n/2];
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            // cout<<lo<<" "<<hi<<" "<<mid<<endl;
            if(check(mid,x,n,c))
            {
                best=mid;
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
        cout<<best<<endl;
    }
    return 0;
