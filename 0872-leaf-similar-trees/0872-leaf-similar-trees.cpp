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
    
    void dfs(TreeNode* root, vector<int> &t)
    {
        if(!root)
        {
            return;
        }
        
        if(!root->left and !root->right)
        {
            t.push_back(root->val);
        }
        if(root->left)
        {
            dfs(root->left, t);
        }
        if(root->right)
        {
            dfs(root->right, t);
        }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int> t1;
        vector<int> t2;
        
        dfs(root1, t1);
        dfs(root2, t2);
        
        return t1 == t2;
    }
};