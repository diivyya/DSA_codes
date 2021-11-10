//Flood fill algorithm (fill all cells ith color same as src to newColor)
//Time: O(4^(N^2))
//Space: O(N^2)
#include <bits.stdc++.h>
using namespace std;
bool isInside(int i, int j, int m, int n)
    {
        if(i<0||j<0||i>=m||j>=n) return false;
        return true;
    }
    void solve(vector<vector<int>>&image, vector<vector<bool>>&vis, int m, int n, int sr, int sc, int curr, int prev)
    {
        if(!isInside(sr,sc,m,n)) return;
        image[sr][sc]=curr;
        vis[sr][sc]=true;
        if(isInside(sr+1,sc,m,n) && image[sr+1][sc]==prev && !vis[sr+1][sc]) solve(image,vis,m,n,sr+1,sc,curr,prev);
        if(isInside(sr-1,sc,m,n) && image[sr-1][sc]==prev && !vis[sr-1][sc]) solve(image,vis,m,n,sr-1,sc,curr,prev);
        if(isInside(sr,sc+1,m,n) && image[sr][sc+1]==prev && !vis[sr][sc+1]) solve(image,vis,m,n,sr,sc+1,curr,prev);
        if(isInside(sr,sc-1,m,n) && image[sr][sc-1]==prev && !vis[sr][sc-1]) solve(image,vis,m,n,sr,sc-1,curr,prev);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,0));
        solve(image, vis, m, n, sr, sc, newColor, image[sr][sc]);
        return image;
    }
    int main()
    {
    	int m,n;
    	cin>>m>>n;
    	vector<vector<int>>image(m,vector<int>(n));
    	for(int i=0;i<m;i++)
    	{
    		for(int j=0;j<n;j++)
    		{
    			cin>>image[i][j];
			}
		}
		int sr,sc,newColor;
		cin>>sr>>sc>>newColor;
		vector<vector<int>>ans = floodFill(image,sr,sc,newColor);
		for(int i=0;i<m;i++)
    	{
    		for(int j=0;j<n;j++)
    		{
    			cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}
	}
