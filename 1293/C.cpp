#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    int A[2][n],blockage=0;
    for(int i=0;i<2;i++)
        for(int j=0;j<n;j++)
            A[i][j]=0;
    for(int i=0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        if(A[x-1][y-1]==0)
        {
            A[x-1][y-1]=1;
            if(x==1)
            {
                //cout<<"YE";
                if(y>1 && y<n)
                {
                    if(A[1][y-2]==1)    blockage++;
                    if(A[1][y-1]==1)    blockage++;
                    if(A[1][y]==1)      blockage++;
                }
                else if(y==1)
                {
                    if(A[1][y-1]==1)    blockage++;
                    if(A[1][y]==1)      blockage++;
                }
                else if(y==n)
                {
                    if(A[1][y-2]==1)    blockage++;
                    if(A[1][y-1]==1)    blockage++;
                }
            }
            else if(x==2)
            {
                //cout<<"NYE";
                if(y>1 && y<n)
                {
                    if(A[0][y-2]==1)    blockage++;
                    if(A[0][y-1]==1)    blockage++;
                    if(A[0][y]==1)      blockage++;
                }
                else if(y==1)
                {
                    if(A[0][y-1]==1)    blockage++;
                    if(A[0][y]==1)      blockage++;
                }
                else if(y==n)
                {
                    if(A[0][y-2]==1)    blockage++;
                    if(A[0][y-1]==1)    blockage++;
                }
            }
        }
        else if(A[x-1][y-1]==1)
        {
            A[x-1][y-1]=0;
            if(x==1)
            {
                //cout<<"YEE";
                if(y>1 && y<n)
                {
                    if(A[1][y-2]==1)    blockage--;
                    if(A[1][y-1]==1)    blockage--;
                    if(A[1][y]==1)      blockage--;
                }
                else if(y==1)
                {
                    if(A[1][y-1]==1)    blockage--;
                    if(A[1][y]==1)      blockage--;
                }
                else if(y==n)
                {
                    if(A[1][y-2]==1)    blockage--;
                    if(A[1][y-1]==1)    blockage--;
                }
            }
            else if(x==2)
            {
                //cout<<"NYEE";
                if(y>1 && y<n)
                {
                    if(A[0][y-2]==1)    blockage--;
                    if(A[0][y-1]==1)    blockage--;
                    if(A[0][y]==1)      blockage--;
                }
                else if(y==1)
                {
                    if(A[0][y-1]==1)    blockage--;
                    if(A[0][y]==1)      blockage--;
                }
                else if(y==n)
                {
                    if(A[0][y-2]==1)    blockage--;
                    if(A[0][y-1]==1)    blockage--;
                }
            }
        }
        //cout<<blockage;
        if(blockage==0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}