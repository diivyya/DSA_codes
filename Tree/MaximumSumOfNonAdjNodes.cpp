//Find maximum sum of non-adjacent nodes (By recursion)
//Time: O(N)
//Space: O(1)
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
pair<int,int>solve(Node*root)
    {
        if(!root)
        {
           pair<int, int> sum(0, 0);
           return sum;
        }
        pair<int,int>l=solve(root->left);
        pair<int,int>r=solve(root->right);
        pair<int,int>t;
        t.first=l.second+r.second+root->data;
        t.second=max(l.first,l.second)+max(r.first,r.second);
        return t;
    }
    int getMaxSum(Node*root)
    {
        pair<int,int>ans = solve(root);
        return max(ans.first,ans.second);
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
