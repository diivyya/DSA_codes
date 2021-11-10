// Topological sort in Directed Acyclic Graph
//Time: O(V+E)
//Space: O(V)
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int>adj[], vector<int>&ans, vector<bool>&vis, int src)
	{
	    vis[src]=true;
	    for(auto it: adj[src])
	    {
	        if(!vis[it]) dfs(adj,ans,vis,it);
	    }
	    ans.push_back(src);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool>vis(V,false);
	    vector<int>ans;
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i]) dfs(adj,ans,vis,i);
	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
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
	vector<int>ans = topoSort(V,adj);
	for(int i=0;i<V;i++)
	{
		cout<<ans[i]<<" ";
	}
}
