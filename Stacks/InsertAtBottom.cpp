//Insert at the bottom of stack
//Time: O(N)
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
    int c;
    cin>>c;
    insert_at_bottom(st,c);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}
