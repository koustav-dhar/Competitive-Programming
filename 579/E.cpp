#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define epsilon 1e-6
typedef long long ll;
double maxSubArraySum(double a[], ll size) 
{ 
    double max_so_far = INT_MIN, max_ending_here = 0;
    ll start =0, end = 0, s=0; 
    for (ll i=0; i< size; i++ ) 
    { 
        max_ending_here += a[i]; 
        if (max_so_far < max_ending_here) 
        { 
            max_so_far = max_ending_here; 
            start = s; 
            end = i; 
        } 
        if (max_ending_here < 0) 
        { 
            max_ending_here = 0; 
            s = i + 1; 
        } 
    } 
    return max_so_far;
} 
double f(double m, double ar[], ll n)
{
    double sum1,sum2,a[n];
    for(ll i=0;i<n;i++)
        a[i]=ar[i]-m;
    sum1=maxSubArraySum(a,n);
    for(ll i=0;i<n;i++)
        a[i]=(-1)*a[i];
    sum2=maxSubArraySum(a,n);
    return (sum1>sum2)?sum1:sum2;
}
signed main() {
	// your code goes here
	fast
	ll n;
	cin>>n;
	double a[n];
	for(ll i=0;i<n;i++)
	    cin>>a[i];
	double l=-10000,r=10000,m1,m2;
	for(ll iter=0;iter<100;iter++)
	{
	    m1 = l + (r-l)/3;
	    m2 = r - (r-l)/3;
	   // cout<<l<<endl;
	    double f1=f(m1,a,n);
	    double f2=f(m2,a,n);
	    if(f1>f2)
	        l=m1;
	    else
	        r=m2;
	}
// 	printf("%lf\n",l);
	double ans=f(l,a,n);
	printf("%.15lf\n",ans);
	return 0;
}