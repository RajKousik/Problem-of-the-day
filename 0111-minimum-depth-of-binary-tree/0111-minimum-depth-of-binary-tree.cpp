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
    int minDepth(TreeNode* root) {
        
        if(!root) return 0;
        
        int depth = 1;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto node = q.front();
                q.pop();

                if(!node->left and !node->right)
                {
                    return depth;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            depth++; 
        }
        return depth;
        
    }
};