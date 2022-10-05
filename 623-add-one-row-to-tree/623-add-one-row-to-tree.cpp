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
    
    void dfs(TreeNode* root, int val, int currDepth, int depth)
    {
        
        if(root == NULL)
        {
            return;
        }
        
        if(currDepth == depth-1)
        {
            //left side
            TreeNode* temp = root->left;
            
            TreeNode* newNode = new TreeNode(val);
            
            root->left = newNode;
            
            root->left->left = temp;
            
            //right side
            temp = root->right;
            
            newNode = new TreeNode(val);
            
            root->right = newNode;
            
            root->right->right = temp;
            
        }
        else
        {
            
            dfs(root->left, val, currDepth + 1, depth);
            dfs(root->right, val, currDepth + 1, depth);
            
        }
        
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1)
        {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        dfs(root, val, 1, depth);
        
        return root;
        
    }
};