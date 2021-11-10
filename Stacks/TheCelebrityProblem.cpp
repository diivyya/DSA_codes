//Find celebrity index (known to all but doesn't know anyone)
#include <bits/stdc++.h>
using namespace std;

//Time: O(N^2)
//Space: O(N)
int celebrityBF(vector<vector<int> >& M, int n) 
    {
        int in[n]={0};
        int out[n]={0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(M[i][j]==1)
                {
                    in[j]++;
                    out[i]++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(in[i]==n-1&&out[i]==0) return i;
        }
        return -1;
    }
    
int main()
{
	int n;
	cin>>n;
	vector<vector<int>>arr(n,vector<int>(n));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	int celeb = celebrityBF(arr,n);
	cout<<celeb;
}
