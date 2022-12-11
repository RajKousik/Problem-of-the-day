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
    
    int helper(TreeNode* root, int &maxi)
    {
        if(!root)
        {
            return 0;
        }
        
        //try to take max value , as negative values donest give max path sum
        int ls = max(0, helper(root->left, maxi));
        int rs = max(0, helper(root->right, maxi));
        
        //for all the nodes, try to add ls + rs + root data and updating max if needed
        maxi = max(maxi, (ls + rs + root->val));
        
        //returning only max path sum
        return max(ls, rs) + root->val;
        
    }
    
    int maxPathSum(TreeNode* root) {
       
        int maxi = INT_MIN;
        helper(root, maxi);
        return maxi;
        
    }
};