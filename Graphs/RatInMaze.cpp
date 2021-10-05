// Time: O(3^(n^2))
// Cost: O(3^(n^2))
// Find all paths to reach from start to end in grid
#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>>&m, vector<vector<bool>>&vis, int n, int i, int j)
    {
     if(i==-1||i==n||j==-1||j==n||m[i][j]==0||vis[i][j]==1) return false;
     return true;
    }
    void solve(vector<vector<int>>&m, int n, vector<vector<bool>>&vis, int i, int j, vector<string>&ans, string path){
        if(!isSafe(m,vis,n,i,j)) return;
        if(i==n-1&&j==n-1)
        {
            ans.push_back(path);
            return;
        }
        vis[i][j]=true;
        //Down
        if(isSafe(m,vis,n,i+1,j))
        {
            path.push_back('D');
            solve(m,n,vis,i+1,j,ans,path);
            path.pop_back();
        }
        //Left
        if(isSafe(m,vis,n,i,j-1))
        {
            path.push_back('L');
            solve(m,n,vis,i,j-1,ans,path);
            path.pop_back();
        }
        //Right
        if(isSafe(m,vis,n,i,j+1))
        {
            path.push_back('R');
            solve(m,n,vis,i,j+1,ans,path);
            path.pop_back();
        }
        //Up
        if(isSafe(m,vis,n,i-1,j))
        {
            path.push_back('U');
            solve(m,n,vis,i-1,j,ans,path);
            path.pop_back();
        }
        vis[i][j]=false;
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        vector<vector<bool>>vis(n, vector<bool>(n,false));
        string path;
        solve(m,n,vis,0,0,ans,path);
        if(ans.empty()) ans.push_back("-1");
        return ans;
    }
    int main()
    {
    	int n;
    	cin>>n;
    	vector<vector<int>>m(n, vector<int>(n));
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<n;j++)
    		{
    			cin>>m[i][j];
			}
		}
		vector<string>ans = findPath(m,n);
		for(int i=0;i<ans.size();i++)
		{
			cout<<ans[i]<<" ";
		}
	}
