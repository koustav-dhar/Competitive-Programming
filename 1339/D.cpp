// C++ program to find diameter of a binary tree 
// using DFS. 
#include <iostream> 
#include <limits.h> 
#include <list> 
using namespace std; 

// Used to track farthest node. 
int x; 

// Sets maxCount as maximum distance from node. 
void dfsUtil(int node, int count, bool visited[], 
				int& maxCount, list<int>* adj) 
{ 
	visited[node] = true; 
	count++; 
	for (auto i = adj[node].begin(); i != adj[node].end(); ++i) { 
		if (!visited[*i]) { 
			if (count >= maxCount) { 
				maxCount = count; 
				x = *i; 
			} 
			dfsUtil(*i, count, visited, maxCount, adj); 
		} 
	} 
} 

// The function to do DFS traversal. It uses recursive 
// dfsUtil() 
void dfs(int node, int n, list<int>* adj, int& maxCount) 
{ 
	bool visited[n + 1]; 
	int count = 0; 

	// Mark all the vertices as not visited 
	for (int i = 1; i <= n; ++i) 
		visited[i] = false; 

	// Increment count by 1 for visited node 
	dfsUtil(node, count + 1, visited, maxCount, adj); 
} 

// Returns diameter of binary tree represented 
// as adjacency list. 
int diameter(list<int>* adj, int n) 
{ 
	int maxCount = INT_MIN; 

	/* DFS from a random node and then see 
	farthest node X from it*/
	dfs(1, n, adj, maxCount); 

	/* DFS from X and check the farthest node 
	from it */
	dfs(x, n, adj, maxCount); 

	return maxCount; 
} 

/* Driver program to test above functions*/
int main() 
{ 
	int n ; 
	cin>>n;
	/* Constructed tree is 
		1 
		/ \ 
		2 3 
	/ \ 
	4 5 */
	list<int>* adj = new list<int>[n + 1]; 
	int a,b;
	for(int i=0;i<n-1;i++)
		cin>>a>>b , adj[a].push_back(b) , adj[b].push_back(a);
	/*create undirected edges */
	// adj[1].push_back(2); 
	// adj[2].push_back(1); 
	// adj[1].push_back(3); 
	// adj[3].push_back(1); 
	// adj[2].push_back(4); 
	// adj[4].push_back(2); 
	// adj[2].push_back(5); 
	// adj[5].push_back(2); 


	/* maxCount will have diameter of tree */
	int dia=diameter(adj,n);
	//cout<<dia<<endl;
	if(dia%2==0)
		cout<<dia-1<<" "<<dia-1<<endl;
	else
		cout<<"1 "<<dia-1<<endl;
	return 0; 
}