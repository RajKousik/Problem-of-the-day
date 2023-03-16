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
private:
    TreeNode* builder(int inStart, int inEnd, vector<int> &inorder, int postStart, int postEnd, vector<int> &postorder, unordered_map<int, int> &index, int n)
    {
        
        if(postStart > postEnd or inStart > inEnd)
        {
            return NULL;
        }
        
        TreeNode *root = new TreeNode(postorder[postEnd]);
        
        int rootIndex = index[root->val];       //1
        int noOfRight = inEnd - rootIndex ;              //3
        
        root->left = builder(inStart, rootIndex - 1, inorder, postStart, postEnd - noOfRight - 1, postorder, index, n);
        
        root->right = builder(rootIndex + 1, inEnd, inorder, postEnd - noOfRight, postEnd - 1, postorder, index, n);
        
        return root;
        
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        unordered_map<int, int> index;
        
        int n = inorder.size();
        
        for(int i=0; i<inorder.size(); i++)
        {
            index[inorder[i]] = i;
        }
        
        return builder(0, n-1, inorder, 0, n-1, postorder, index, n);
        
    }
};