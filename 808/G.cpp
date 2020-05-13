#include<bits/stdc++.h>

using namespace std;

void computelps(char pat[],int m,int lps[])
{
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<m)
    {
        if(pat[len]==pat[i])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}

int countWithKMP(char txt[],char pat[])
{
    int n=strlen(txt);
    int m=strlen(pat);
    int lps[m];
    computelps(pat,m,lps);
    int i=0,j=0,count=0;
    while(i<n)
    {
        if(txt[i]==pat[j] || txt[i]=='?')
        {
            i++;
            j++;
        }
        if(j==m)
        {
            count++;
            j=lps[j-1];
        }
        else if(i<n && ((txt[i]!=pat[j]) && (txt[i]!='?')))
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    char s[100000],t[100000];
    scanf("%s%s",s,t);
    int ans=countWithKMP(s,t);
    cout<<ans<<endl;
    return 0;
}