//Minimum number of steps required by knight to reach target
//Time: O(n^2)
//Space: O(n^2) 
#include <bits/stdc++.h>
using namespace std;
struct cell{
        int x,y;
        int dis;
        cell(){}
        cell(int x, int y, int dis)
          : x(x), y(y), dis(dis){}
    };
    bool isInside(int N, int i, int j)
    {
        if(i<1||j<1||i>N||j>N) return false;
        return true;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
		//BFS approach
	    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
        int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
        queue<cell>q;
        q.push(cell(KnightPos[0],KnightPos[1],0));
        vector<vector<bool>>vis(N+1,vector<bool>(N+1,false));
        cell t;
        vis[KnightPos[0]][KnightPos[1]]=true;
        while(!q.empty())
        {
            t = q.front();
            q.pop();
            if(t.x==TargetPos[0] && t.y==TargetPos[1]) return t.dis;
            
            for(int i=0;i<8;i++)
            {
                int x = t.x+dx[i];
                int y = t.y+dy[i];
                if(isInside(N,x,y)&&!vis[x][y]){
                    q.push(cell(x,y,t.dis+1));
                    vis[x][y]=true;
                }
            }
        }
        return -1;
	}
	int main()
	{
		int N;
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		cin>>N>>KnightPos[0]>>KnightPos[1]>>TargetPos[0]>>TargetPos[1];
		cout<<minStepToReachTarget(KnightPos,TargetPos,N);
	}
