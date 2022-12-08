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
    
//     void dfs(TreeNode* root, vector<int> &t)
//     {
//         if(!root)
//         {
//             return;
//         }
        
//         if(!root->left and !root->right)
//         {
//             t.push_back(root->val);
//         }
//         if(root->left)
//         {
//             dfs(root->left, t);
//         }
//         if(root->right)
//         {
//             dfs(root->right, t);
//         }
//     }
    
//     bool leafSimilar(TreeNode* root1, TreeNode* root2)
//     {
//         vector<int> t1;
//         vector<int> t2;
        
//         dfs(root1, t1);
//         dfs(root2, t2);
        
//         return t1 == t2;
//     }
    
    void dfs(TreeNode* root, queue<int> &q)
    {
        if(!root)
        {
            return;
        }
        
        if(!root->left and !root->right)
        {
            // cout<<root->val<<" ";
            q.push(root->val);
        }
        if(root->left)
        {
            dfs(root->left, q);
        }
        if(root->right)
        {
            dfs(root->right, q);
        }
    }
    
     bool leafSimilar(TreeNode* root1, TreeNode* root2)
     {
        queue<int> q1;
        
        dfs(root1, q1);
         
        return check(root2, q1) and q1.empty();
     }
    
    bool check(TreeNode* root, queue<int> &q)
    {
        if(!root->left and !root->right)
        {
            int tmp = q.front();
            q.pop();
            cout<<tmp<<" "<<root->val<<endl;
            return tmp == root->val;
        }
        bool result1=true, result2=true;
        if(root->left)
        {
            result1 = check(root->left, q);
        }
        if(root->right)
        {
            result2 = check(root->right, q);
        }
        return result1 and result2;
    }


};