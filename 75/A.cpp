#include <bits/stdc++.h>
using namespace std;
void remove_zeroes(vector<int> v)
{
	for(auto itr=v.begin();itr!=v.end();itr++)
	{
		if(*itr==0)
			v.erase(itr);
	}
}
int vectonum(vector<int> v)
{
	int num=0;
	for(auto itr=v.begin();itr!=v.end();itr++)
	{
		num=*itr+num*10;
	}
	return num;
}
void numtovect(int num,vector<int>* v)
{
	while(num>0)
	{
		v->push_back(num%10);
		num/=10;
	}
}
int main() {
	// your code goes here
	int a,b;
	cin>>a>>b;
	vector<int> va,vb,vc;
	int c=a+b;
	numtovect(a,&va);
	numtovect(b,&vb);
	numtovect(c,&vc);
	remove_zeroes(va);
	remove_zeroes(vb);
	remove_zeroes(vc);
	a=vectonum(va);
	b=vectonum(vb);
	c=vectonum(vc);
	if(a+b==c)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}