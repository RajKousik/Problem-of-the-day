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
    
    void dfs(TreeNode* root, long long targetSum, int &ans)
    {
        if(!root)
        {
            return;
        }
        
        if(root->val == targetSum) ans++;
        dfs(root->left, targetSum - root->val, ans);
        dfs(root->right, targetSum - root->val, ans);
        
    }
    
    void pathSumUtil(TreeNode* root, long long targetSum, int &ans)
    {
        if(!root) return;
        
        dfs(root, targetSum, ans);
        pathSumUtil(root->left, targetSum, ans);
        pathSumUtil(root->right, targetSum, ans);
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) 
    {
        int ans = 0;
        pathSumUtil(root, (long long)targetSum, ans);
        return ans;
    }
};