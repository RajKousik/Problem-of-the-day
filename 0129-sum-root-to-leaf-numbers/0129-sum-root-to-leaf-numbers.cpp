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
    
    int getSumOfNumbers(TreeNode* root, int sum)
    {
        if(!root)
        {
            return 0;
        }
        
        if(root->left == NULL and root->right == NULL)
        {
            return (sum * 10) + root->val;
        }
        
        int left = getSumOfNumbers(root->left, (sum * 10) + root->val);
        int right = getSumOfNumbers(root->right, (sum * 10) + root->val);
        
        return left + right;
        
    }
    
    int sumNumbers(TreeNode* root) {
        
        if(!root)
            return 0;
        
        return getSumOfNumbers(root, 0);
        
    }
};