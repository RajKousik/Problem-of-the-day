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
class Solution {
public:
    
    bool helper(TreeNode* root, long low, long high)
    {
        if(!root) return true;
        
        if(root->val <= low or root->val >= high)
        {
            return false;
        }
        
        return helper(root->left, low, root->val) and helper(root->right, root->val, high);
    }
    
    
    bool isValidBST(TreeNode* root) {
        
        if(!root) return true;
        
        long low = (long)INT_MIN - 1;
        long high = (long)INT_MAX + 1;
        
        return helper(root, low, high);
        
    }
};