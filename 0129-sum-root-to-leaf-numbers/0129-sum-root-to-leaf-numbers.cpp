/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
private:
    int helper(TreeNode* root, int val)
    {
        if(!root->left and !root->right)
            return val;
        
        int sum = (val * 10);
        
        int left = 0, right = 0;
        if(root->left)
            left =  helper(root->left, sum + root->left->val);
        if(root->right)
            right = helper(root->right, sum + root->right->val);
        
        return left + right;
    }
    
public:
    int sumNumbers(TreeNode* root)
    {
        return helper(root, root->val);    
    }
};