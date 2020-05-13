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
        char s[n+1];
        scanf("%s",s);
        int p[m];
        for(int i=0;i<m;i++)    cin>>p[i];
        int calhash[n][26]={{0}};
        for(int i=0;i<n;i++)
        {
            if(i==0)
                calhash[i][s[i]-97]++;
            else
            {
                calhash[i][s[i]-97]++;
                for(int j=0;j<26;j++)
                {
                    calhash[i][j]+=calhash[i-1][j];
                }
            }
        }
        int anshash[26]={0};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<26;j++)
            {
                anshash[j]+=calhash[p[i]-1][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            anshash[s[i]-97]++;
        }
        for(int i=0;i<26;i++)
        {
            cout<<anshash[i]<<" ";
        }
        cout<<endl;
    }
}