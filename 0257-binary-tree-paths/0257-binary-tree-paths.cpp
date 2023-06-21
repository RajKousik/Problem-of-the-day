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
    
    void dfs(string path, TreeNode *root, vector<string> &ans)
    {
        if(!root) return;
        if(!root->left and !root->right)
        {
            path += (to_string(root->val));
            ans.push_back(path);
            return;
        }
        
        dfs(path + to_string(root->val) + "->", root->left, ans);
        dfs(path + to_string(root->val) + "->", root->right, ans);
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> ans;
        string path = "";
        dfs(path, root, ans);
        return ans;
        
    }
};