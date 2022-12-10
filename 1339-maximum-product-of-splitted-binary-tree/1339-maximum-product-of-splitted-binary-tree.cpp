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
    int maxProduct(TreeNode* root) {
        
        if(!root)return 0; 
        
        int mod = 1e9+7;
        int totalSum = 0;
        
        long long maxProduct = 0;
        
        totalSum = dfs(root, maxProduct, totalSum);
        
        dfs(root, maxProduct, totalSum);
        
        return (int)(maxProduct % mod);
    }
    
    int dfs(TreeNode* root, long long &maxProduct, int totalSum)
    {
        if(!root)
        {
            return 0;
        }
        
        long long subTreeSum = dfs(root->left, maxProduct, totalSum) + dfs(root->right, maxProduct, totalSum) + root->val;
        
        maxProduct = max(maxProduct, (long long)((totalSum - subTreeSum) * subTreeSum));
        
        return subTreeSum;
    }
};