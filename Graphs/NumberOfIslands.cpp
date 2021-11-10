//No of islands (only 4 neighbours)
//Time: O(M*N)
//Space: O(M*N)

#include <bits/stdc++.h>
using namespace std;

bool isInside(int n, int m, int i, int j)
    {
        if(i<0||j<0||i>n-1||j>m-1) return false;
        return true;
    }
    void dfs(vector<vector<char>>&grid, vector<vector<bool>>&vis, int n, int m, int i, int j)
    {
        vis[i][j]=true;
        int dx[] = { 0, -1, 0, 1 };
        int dy[] = { -1, 0, 1, 0 };
        for(int k=0;k<4;k++)
        {
            int x=dx[k]+i;
            int y=dy[k]+j;
            if(isInside(n,m,x,y) && !vis[x][y] && grid[x][y]=='X') dfs(grid,vis,n,m,x,y);
        }
        return;
    }
    int solve(vector<vector<char>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='X')
                {
                    dfs(grid,vis,n,m,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
    int main()
    {
    	int n,m;
    	cin>>n>>m;
    	vector<vector<char>>grid(n,vector<char>(m));
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<m;j++)
    		{
    			cin>>grid[i][j];
			}
		}
		int ans = solve(grid);
		cout<<ans;
	}
