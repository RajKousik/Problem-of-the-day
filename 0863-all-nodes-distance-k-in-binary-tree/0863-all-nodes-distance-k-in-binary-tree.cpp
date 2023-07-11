/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void dfs(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, TreeNode*> &parentMap)
    {
        if(!root) return;
        
        parentMap[root] = parent;
        
        dfs(root->left, root, parentMap);
        dfs(root->right, root, parentMap);
    }
    
    void helper(TreeNode* root, int k, unordered_map<TreeNode*, TreeNode*> &parentMap, unordered_set<TreeNode*> &isVis, vector<int> &ans)
    {
        if(!root) return;
        
        if(isVis.find(root) != isVis.end())
        {
            return;
        }
        cout<<root->val<<" ";
        isVis.insert(root);
        
        if(k == 0)
        {
            ans.push_back(root->val);
            return;
        }
        
        
        helper(root->left, k-1, parentMap, isVis, ans);
        helper(root->right, k-1, parentMap, isVis, ans);
        helper(parentMap[root], k-1, parentMap, isVis, ans);        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        
        dfs(root, NULL, parentMap);
        
        unordered_set<TreeNode*> isVis;
        vector<int> ans;
        helper(target, k, parentMap, isVis, ans);
        return ans;
    }
};