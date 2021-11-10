//Generate Balanced Paranthesis
//Time: O(2^N)
//Space: O(N)
#include <bits/stdc++.h>
using namespace std;
void solve(vector<string>&ans, int open, int close, int n, string s)
    {
        if(open==n&&close==n)
        {
            ans.push_back(s);
            return;
        }
        if(open<n) solve(ans,open+1,close,n,s+"(");
        if(open>close) solve(ans,open,close+1,n,s+")");
    }
    vector<string> AllParenthesis(int n) 
    {
         vector<string>ans;
         solve(ans,0,0,n,"");
         return ans;
    }
    int main()
    {
    	int n;
    	cin>>n;
    	vector<string> ans;
		AllParenthesis(ans,0,0,n,"");
		for(auto s:ans){
		cout<<s<<endl;
		}
		return 0;
	}
