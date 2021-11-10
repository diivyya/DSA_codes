//Reverse in stack

//Outplace---
//Time: O(N)
//Space: O(N)

//Inplace---
//Time: O(N^2)
//Space: O(N)

#include <bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int>&st, int c)
{
    if(st.empty())
    {
        st.push(c);
        return;
    }
    int x = st.top();
    st.pop();
    insert_at_bottom(st,c);
    st.push(x);
    return;
}

void reverse(stack<int>&st)
{
    if(st.empty()) return;
    int x = st.top();
    st.pop();
    reverse(st);
    insert_at_bottom(st,x);
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
    reverse(st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}
