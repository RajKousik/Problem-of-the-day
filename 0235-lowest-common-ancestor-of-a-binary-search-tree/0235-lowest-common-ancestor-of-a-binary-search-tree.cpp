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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == p or root == q or !root)
        {
            return root;
        }
        
        TreeNode* leftEnd =  lowestCommonAncestor(root->left, p ,q);
        
        TreeNode* rightEnd = lowestCommonAncestor(root->right, p, q);
        
        if(leftEnd and rightEnd)
        {
            return root;
        }
        
        if(leftEnd)
        {
            return leftEnd;
        }
        if(rightEnd)
        {
            return rightEnd;
        }
        
        return NULL;
        
    }
};