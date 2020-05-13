#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;

signed main()
{
    fast
    string s;
    cin >> s;
    cout << s;
    for(ll i = s.length() - 1; i >= 0; i--)
        cout << s[i];
    cout<<"\n";
    return 0;
}