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

//     priority_queue<int> pq;
//     int size;
    
//     void help(TreeNode* root, int k){
//         if(!root) return;
        
//         if(pq.size()< k) pq.push(root->val);
//         else if(root->val < pq.top()){
//                 pq.pop();
//                 pq.push(root->val);
//             }
        
//         help(root->left,k);
//         help(root->right,k);

//     }
    
    void solver(TreeNode* root, int &k, int &ans)
    {
        if(root->left)
             solver(root->left, k, ans);
        
        k--;
        if(k == 0)
        {
            ans = root->val;
            return;
        }
        
        if(root->right)
             solver(root->right, k, ans);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        // help(root,k);
        // return pq.top();
        
        int ans;
        solver(root, k, ans);
        return ans;
    }

};