//Kruskal Algo: sort by weight, add edge if it does not make cycle
//Time: O(ELogE + ELogV) 
#include <bits/stdc++.h>
using namespace std;
struct DSU{
  vector<int>par,sz;
  DSU(int n)
  {
      par.resize(n+1);
      sz.resize(n+1);
      for(int i=0;i<n;i++)
      {
          par[i]=i;
          sz[i]=1;
      }
  }
  int find(int x)
  {
      if(x!=par[x]) find(par[x]);
      return par[x];
  }
  bool unite(int x, int y)
  {
      x=find(x);
      y=find(y);
      if(x==y) return 0; //cycle
      if(sz[x]<sz[y]) swap(x,y);
      sz[x]+=sz[y];
      par[y]=x;
      return 1;
  }
};

int main()
{
    int V,E,u,v,w;
    cin>>V>>E;
    vector<pair<int, pair<int,int>>>mp;
    for(int i=0;i<E;i++)
    {
        cin>>u>>v>>w;
        mp.push_back({w,{u,v}});
    }
    sort(mp.begin(),mp.end());
    DSU D(V);
    vector<pair<int, pair<int,int>>>ans;
    for(int i=0;i<V-1;i++)
    {
        if(D.unite(mp[i].second.first,mp[i].second.second)) ans.push_back(mp[i]); 
    }
    
}
