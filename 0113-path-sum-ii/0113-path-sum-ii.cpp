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
    
    //just normal recursive call
    //for each node, subtract the targetSum , and puhs the value in the path
    
    //if leaf node and target is 0, then add the path to the ans
    
    // go for left and right subtree
    
    //atlast backtrack by poping the pushed item in the path
    
    //;)
    
    void rec(TreeNode* root, vector<vector<int>> &ans, vector<int> &path, int targetSum)
    {
        
        if(!root)
        {
            return;
        }
        
        targetSum -= root->val;
        
        path.push_back(root->val);
        
        if(!root->left and !root->right and targetSum == 0)
        {
            ans.push_back(path);
        }
        
        rec(root->left, ans, path, targetSum);
        rec(root->right, ans, path, targetSum);

        path.pop_back();
        
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> ans;
        vector<int> path;
        
        rec(root, ans, path, targetSum);
        
        return ans;
        
    }
};