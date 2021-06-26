//https://practice.geeksforgeeks.org/problems/maximum-path-sum/1

class Solution {
public:
int helper(Node* root, int& res) {
    if (root == NULL) {
        return 0;
    }
    
    int l = helper(root->left, res);
    int r = helper(root->right, res);
    
    int temp = root->data;
    
    if (root->left != NULL and root->right != NULL) {
        temp = max(l, r) + root->data;
        res = max(res, l+r+root->data);
    }
    else if (root->left and !root->right) {
        temp = root->data + l;
    }
    else if (root->right and !root->left) {
        temp = root->data + r;
    }
    
    return temp;
}
    int maxPathSum(Node* root)
    {
        int res=INT_MIN;
        int ans = helper(root,res);
        if(res==INT_MIN)
        {
            return ans;
        }
        return res;
        
    }
};