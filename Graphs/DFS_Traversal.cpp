#include <bits/stdc++.h>
using namespace std;
vector<int>dfs_traversal;
void dfs(vector<int>adj[], bool vis[], int s)
{
	if(vis[s]) return;
	dfs_traversal.push_back(s);
	vis[s]=true;
	for(auto it: adj[s])
	{
		if(!vis[it]) dfs(adj,vis,it);
	}
}
int main()
{
	int V,E,u,v;
	cin>>V>>E;
	vector<int>adj[V];
	for(int i=0;i<E;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int s;
	cin>>s;
	bool vis[V];
	memset(vis,false,sizeof(vis));
	dfs_traversal.clear();
	dfs(adj,vis,s);
	for(int i=0;i<V;i++)
	{
		cout<<dfs_traversal[i]<<" ";
	}
}
