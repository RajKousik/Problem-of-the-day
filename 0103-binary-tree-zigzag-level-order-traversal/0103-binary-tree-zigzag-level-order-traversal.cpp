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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(!root) return {};
        
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int levelNumber = 0;  
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;
            
            while(size--)
            {
                auto curr = q.front();
                q.pop();
                
                level.push_back(curr->val);
                
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
            if(levelNumber % 2)
            {
                reverse(level.begin(), level.end());
            }
            ans.push_back(level);
            levelNumber++;
        }
        return ans;
    }
};