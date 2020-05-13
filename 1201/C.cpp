#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(ll num,ll a[],ll n,ll k)
{
    ll count=0;
    for(ll i=n/2;i<n;i++)
    {
        count+=max(ll(0),num-a[i]);
        if(count>k)
            return false;
    }
    if(count<=k)
        return true;
    else
        return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for(ll i=0;i<n;i++)    cin>>a[i];
    if(n==1)
        cout<<a[0]+k<<endl;
    else
    {
        sort(a,a+n);
        ll lo=1,hi=2000000000,mid,best;
        best=a[n/2];
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            // cout<<mid<<endl;
            if(check(mid,a,n,k))
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
}