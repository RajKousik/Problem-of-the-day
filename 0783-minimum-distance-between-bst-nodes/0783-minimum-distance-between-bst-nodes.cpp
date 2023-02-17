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
    // TreeNode* prevNode;
    int prevNode = -1;
    
    void inorderTraversal(TreeNode* root, int &ans)
    {
        if(!root)
        {
            return;
        }
        
        inorderTraversal(root->left, ans);
        
        if(prevNode != -1)
        {
            ans = min(ans, (root->val - prevNode));
        }
        prevNode = root->val;
        
        inorderTraversal(root->right, ans);
        
    }
    
    int minDiffInBST(TreeNode* root) {
        
        int ans = INT_MAX;
        
        inorderTraversal(root, ans);
        return ans;
    }
};