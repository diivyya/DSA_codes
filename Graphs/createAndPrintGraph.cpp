#include <bits/stdc++.h>
using namespace std;

void print_graph(vector<int>adj[], int v)
{
	for(int i=1;i<=v;i++)
	{
		cout<<i;
		for(auto it: adj[i])
		{
			cout<<"-->"<<it;
		}
		cout<<endl;
	}
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
	print_graph(adj,V);
}
