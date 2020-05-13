#include <bits/stdc++.h>
using namespace std;
vector<int> v[10001];
int vis[10001] = {0}, dis[10001] = {0};
void SieveOfEratosthenes(int n) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
    for (int p = 2; p * p <= n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i = p * p; i <= n; i += p) 
                prime[i] = false; 
        } 
    }
    vector<int> allprime;
    for (int p = 1000; p <= n; p++) 
    	if (prime[p]) 
			allprime.push_back(p);
	for (int child1 : allprime)
	{
		for (int child2 : allprime)
		{
			int a[4], b[4], A = child1, B = child2, k = 0;
			while (A > 0)
			{
				a[k++] = A % 10;
				A /= 10;
			}
			k = 0;
			while (B > 0)
			{
				b[k++] = B % 10;
				B /= 10;
			}
			k = 0;
			for (int i = 0; i < 4 ; i++)
			{
				if(a[i] != b[i])
					k++;
			}
			if(k == 1)
			{
				v[child1].push_back(child2);
			}
		}
	}
           
} 
  
void bfs(int source)
{
	queue<int> q;
	vis[source] = 1;
	q.push(source);
	dis[source] = 0;
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		for (int child : v[curr])
		{
			if(vis[child] == 0)
			{
				vis[child] = 1;
				dis[child] = dis[curr] + 1;
				q.push(child);
			}
		}
	}
}
int main() {
	// your code goes here
	SieveOfEratosthenes(9999);
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		for (int i = 1000; i <= 9999; i++)	vis[i] = 0;
		bfs(a);
		cout << dis[b] << endl;
	}
	return 0;
