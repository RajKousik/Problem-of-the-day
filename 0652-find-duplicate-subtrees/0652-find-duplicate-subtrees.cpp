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
private:
    string dfs(TreeNode* root, vector<TreeNode*> &ans, unordered_map<string, int> &mp)
    {
        if(!root)
        {
            return "#";
        }
        
        string s = "(" + to_string(root->val) + dfs(root->left, ans, mp) + dfs(root->right, ans, mp) + ")";
        
        if(mp[s] == 1)
        {
            ans.push_back(root);
        }
        mp[s]++;
        return s;
        
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        unordered_map<string, int> mp;
        vector<TreeNode*> ans;
        
        dfs(root, ans, mp);
        return ans;
    }
};