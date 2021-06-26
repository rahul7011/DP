//https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int solve(Node *root,int &res)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=solve(root->left,res);
        int right=solve(root->right,res);
        //for adding current node
        int temp=max(left,right)+1;
        //for taking current node as root whose tree contains the longest diameter
        int ans=max(temp,left+right+1);
        res=max(res,ans);
        return temp;
    }
    int diameter(Node* root) {
        int res=INT_MIN;
        solve(root,res);
        //Notre=Here we are counting nodes whereas if we were counting from edges then return res-1;
        //like here: https://leetcode.com/problems/diameter-of-binary-tree/submissions/
        return res;
    }
};
