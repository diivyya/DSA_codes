#include <bits/stdc++.h>
using namespace std;

vector<int>bfs(vector<int>adj[], int V, int s)
{
	vector<int>ans;
	queue<int>q;
	int visited[V+1] = {0};
	q.push(s);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		ans.push_back(x);
		visited[x]=1;
		for(auto it: adj[x])
		{
			if(visited[it]==0) q.push(it);
		}
	}
	return ans;
}
int main()
{
	int V,E,u,v;
	cin>>V>>E;
	vector<int>adj[V+1];
	for(int i=0;i<E;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int s;
	cin>>s;
	vector<int>bfs_traversal = bfs(adj,V,s);
	for(int i=0;i<v;i++)
	{
		cout<<bfs_traversal[i]<<" ";
	}
}
