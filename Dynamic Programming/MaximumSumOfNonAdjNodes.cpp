//Find maximum sum of non-adjacent nodes (By DP)
//Time: O(N^2)
//Space: O(N)
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};
struct node* newNode(int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int solveGC(Node*root, map<struct Node*,int>&mp)
    {
        int sum=0;
        if(root->left) sum+=solve(root->left->left,mp)+solve(root->left->right,mp);
        if(root->right) sum+=solve(root->right->left,mp)+solve(root->right->right,mp);
        return sum;
    }
    int solve(Node*root, map<struct Node*,int>&mp)
    {
        if(!root) return 0;
        if(mp.find(root)!=mp.end()) return mp[root];
        int inc = solveGC(root,mp)+root->data;
        int exc = solve(root->left,mp)+solve(root->right,mp);
        return mp[root] = max(inc,exc);
    }
    int getMaxSum(Node *root) 
    {
        map<struct Node*,int>mp;
        return solve(root,mp);
    }
    int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->left->left = newNode(1);
 
    cout << getMaxSum(root) << endl;
    return 0;
}
