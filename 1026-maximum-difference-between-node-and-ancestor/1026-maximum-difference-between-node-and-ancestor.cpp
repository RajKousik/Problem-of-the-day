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
    
    void dfs(TreeNode* root, int curMin, int curMax, int &answer)
    {
     
        if(!root)
        {
            return;
        }
        
        int possibleAnswer = max(abs(curMax - root->val), abs(curMin-root->val));
        
        answer = max(answer, possibleAnswer);
        
        curMax = max(curMax, root->val);
        curMin = min(curMin, root->val);
        
        dfs(root->left, curMin, curMax, answer);
        dfs(root->right, curMin, curMax, answer);
        
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int answer = 0;
        dfs(root, root->val, root->val, answer);
        return answer;
    }
};