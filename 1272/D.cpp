#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];
    vector<ll> left(n),right(n);
    for(ll i=0;i<n;i++)
        left[i] = 1 , right[i] = 1;
    for(ll i=1;i<n;i++)
    {
        if(a[i]>a[i-1])
        {
            left[i] = left[i-1] + 1;
        }
        else
        {
            left[i] = 1;
        }
    }
    for(ll i=n-2;i>=0;i--)
    {
        if(a[i]<a[i+1])
        {
            right[i] = right[i+1] + 1;
        }
        else
        {
            right[i] = 1;
        }
    }
    ll ans=*max_element(left.begin(), left.end());
    for(ll i = 1; i < n-1; i++)
    {
        if(a[i+1] > a[i-1])
        {
            ans = max(ans, left[i-1] + right[i+1]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}