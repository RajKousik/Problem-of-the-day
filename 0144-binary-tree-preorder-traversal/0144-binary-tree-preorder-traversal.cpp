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
        
    //recursive method
//     void helper(TreeNode* root, vector<int> &nodes)
//     {
//         if(!root)
//         {
//             return;
//         }
        
//         nodes.push_back(root->val);
//         helper(root->left, nodes);
//         helper(root->right, nodes);
        
//     }
    
    
//     vector<int> preorderTraversal(TreeNode* root) {
        
//         vector<int> nodes;
        
//         helper(root, nodes);
        
//         return nodes;
        
//     }
    
    
    //iterative approach
    vector<int> preorderTraversal(TreeNode* root) {
        
        if(!root) return {};
        
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty())
        {
            
            auto node = st.top();
            st.pop();
            
            ans.push_back(node->val);
            
            if(node->right)
            {
                st.push(node->right);
            }
            if(node->left)
            {
                st.push(node->left);
            }
            
        }
        
        return ans;
        
    }
};