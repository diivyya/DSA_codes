#include <bits/stdc++.h>
using namespace std;
//V+E
bool checkCycle(vector<int>adj[], bool vis[], int s)
{
	if(vis[s]) return true;
	vis[s]=true;
	for(auto it: adj[s])
	{
		if(!vis[it] && checkCycle(adj,vis,it)) return true;
		else return true;
	}
	return false;
}
void hasCycle(vector<int>adj[], int V)
{
    bool vis[V+1];
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=V;i++)
    {
        if(!vis[i] && checkCycle(adj,vis,i)){
            cout<<"Graph has cycle!";
            return;
        }
    }
    cout<<"Graph has no cycle!";
    return;
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
	hasCycle(adj,V);
	
}
