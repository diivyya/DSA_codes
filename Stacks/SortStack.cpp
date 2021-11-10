//Insert at the bottom of stack
//Time: O(N^2)
//Space: O(N)

#include <bits/stdc++.h>
using namespace std;
void insert(stack<int>&s, int e)
{
    if(s.empty())
    {
        s.push(e);
        return;
    }
    if(s.top()<=e) s.push(e);
    else
    {
        int x = s.top();
        s.pop();
        insert(s,e);
        s.push(x);
    }
    
}
void sort(stack<int>&s)
{
   if(s.empty()) return;
   int x = s.top();
   s.pop();
   sort();
   insert(s,x);
}

int main()
{
    stack<int>st;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        st.push(x);
    }
    sort(st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}
