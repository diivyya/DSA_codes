//Reverse String using stack
//Time: O(N)
//Space: O(N)
#include <bits/stdc++.h>
using namespace std;

string reverse(string S, int len)
{
    stack<char>st;
    for(int i=0;i<len;i++)
    {
        st.push(S[i]);
    }
    int i=0;
    while(!st.empty())
    {
        S[i]=st.top();
        st.pop();
        i++;
    }
    return S;
}

int main()
{
	string s;
	cin>>s;
	cout<<reverse(s,s.length());
}
