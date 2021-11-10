//Find next greater element of each element
//Time: O(N)
//Space: O(N)
#include <bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long>st;
        vector<long long>ans(n);
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty()) ans[i]=-1;
            else
            {
                while(!st.empty()&&st.top()<=arr[i])
                {
                    st.pop();
                }
                if(st.empty()) ans[i]=-1;
                else ans[i]=st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
int main()
{
	int n;
	cin>>n;
	vector<long long>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	vector<long long>ans = nextLargerElement(v,n);
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}
}
