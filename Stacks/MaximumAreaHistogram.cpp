#include <bits/stdc++.h>
using namespace std;
vector<int>NSL(long long arr[], int n)
    {
        vector<int>ans(n);
        stack<pair<int,long long>>st;
        for(int i=0;i<n;i++)
        {
            if(st.empty()) st.push({-1,arr[i]});
            else
            {
                while(!st.empty() && st.top().second>=arr[i])
                {
                    st.pop();
                }
                if(st.empty()) st.push({-1,arr[i]});
                else st.push({st.top().first,st.top().second});
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            ans[i]=st.top().first;
            st.pop();
        }
        return ans;
    }
    vector<int>NSR(long long arr[], int n)
    {
        vector<int>ans(n);
        stack<pair<int,long long>>st;
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty()) st.push({n,arr[i]});
            else
            {
                while(!st.empty() && st.top().second>=arr[i])
                {
                    st.pop();
                }
                if(st.empty()) st.push({n,arr[i]});
                else st.push({st.top().first,st.top().second});
            }
        }
        for(int i=0;i<n;i++)
        {
            ans[i]=st.top().first;
            st.pop();
        }
        return ans;
    }
    long long getMaxArea(long long arr[], int n)
    {
        vector<int>left = NSL(arr,n);
        vector<int>right = NSR(arr,n);
        vector<long long>ans(n);
        long long mx = INT_MIN;
        for(int i=0;i<n;i++)
        {
            //cout<<right[i]<<" "<<left[i]<<endl;
            ans[i]=(right[i]-left[i]-1)*arr[i];
            mx=max(ans[i],mx);
        }
        return mx;
    }
    int main()
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int ans = getMaxArea(arr,n);
        cout<<ans;
    }
