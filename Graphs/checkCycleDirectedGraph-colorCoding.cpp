#include <bits/stdc++.h>
using namespace std;
//V+E
vector<bool>col;
bool checkForCycle(vector<int>adj[], int src)
{
    col[src]=1;
    for(auto it:adj[src])
    {
        if(col[src]==0 && checkForCycle(adj,it)) return true;
        else if(col[src]==1) return true;
    }
    col[src]=2;
    return false;
}
bool isCyclic(int V, vector<int> adj[]) {
    col.assign(V,0);
    for(int i=0;i<V;i++)
    {
        if(col[i]==0 && checkForCycle(adj,i)) return true;
    }
    return false;
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
	}
	cout<<isCyclic(V,adj);
}
