//Dijkstra Algo: Shortest distance from source to all vertices (weighted undirected graph)
//Time: O(N^2) O(V+ElogV)--fibonacci heap
//Space: O(N^2)

#include <bits/stdc++.h>
using namespace std;

int minDistance(vector<bool>spt, vector<int>dis)
    {
        int mini=INT_MAX, min_index;
        for(int i=0;i<spt.size();i++)
        {
            if(!spt[i] && dis[i]<mini)
            {
                mini=dis[i];
                min_index=i;
            }
        }
        return min_index;
    }
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<bool>spt(V,false);
        vector<int>dis(V,INT_MAX);
        dis[S]=0;
        for(int c=0;c<V-1;c++)
        {
            int u=minDistance(spt,dis);
            spt[u]=true;
            for(auto v:adj[u])
            {
                if(!spt[v[0]] && dis[u]!=INT_MAX)  dis[v[0]] = min(dis[u]+v[1],dis[v[0]]);
            }
        }
        return dis;
    }
    int main()
    {
    	int V,E;
    	cin>>V>>E;
    	vector<vector<int>>adj[V];
    	for(int i=0;i<E;i++)
    	{
    		int u,v,w;
    		cin>>u>>v>>w;
    		vector<int>t1;
    		t1.push_back(v);
    		t1.push_back(w);
    		adj[u].push_back(t1);
    		vector<int>t2;
    		t2.push_back(u);
    		t2.push_back(w);
    		adj[v].push_back(t2);	
		}
		int S;
		cin>>S;
		vector<int>dist = dijkstra(V,adj,S);
		for(int i=0;i<V;i++)
		{
			cout<<dist[i]<<" ";
		}
	}
