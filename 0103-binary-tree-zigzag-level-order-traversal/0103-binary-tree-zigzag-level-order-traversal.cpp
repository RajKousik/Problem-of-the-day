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
        
        int level = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            
            while(size--)
            {
                auto it = q.front();
                q.pop();
                    
                temp.push_back(it->val);
                
                if(it->left)
                {
                    q.push(it->left);
                }
                
                if(it->right)
                {
                    q.push(it->right);
                }
            }
            
            if(level % 2)
            {
                reverse(temp.begin(), temp.end());
            }
            
            ans.push_back(temp);
            level++;
            
        }
        return ans;
    }
};