//Find if the string has balanced paranthesis or not
//Time: O(N)
//Space: O(N)
#include <bits/stdc++.h>
using namespace std;

bool ispar(string x)
    {
        stack<char>s;
        for(int i=0;i<x.length();i++)
        {
            if(x[i]=='{'||x[i]=='['||x[i]=='(') s.push(x[i]);
            if(s.empty()) return false;
            else
            {
                if(x[i]=='}')
            {
                if(s.top()=='{') s.pop();
                else return false;
            }
            if(x[i]==']')
            {
                if(s.top()=='[') s.pop();
                else return false;
            }
            if(x[i]==')')
            {
                if(s.top()=='(') s.pop();
                else return false;
            }
            }
        }
        if(!s.empty()) return false;
        return true;
    }

int main()
{
	string s;
	cin>>s;
	if(ispar(s)) cout<<"Balanced!";
	else cout<<"Not Balanced!";
}
