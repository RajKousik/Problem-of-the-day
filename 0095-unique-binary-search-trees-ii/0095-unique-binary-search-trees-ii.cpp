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
    
    vector<TreeNode*> helper(int start, int end, map< pair<int, int>, vector<TreeNode*> > &umap)
    {
        vector<TreeNode*> ans;
        if(start > end)
        {
            ans.push_back(NULL);
            return ans;
        }
        
        if(umap.find({start, end}) != umap.end())
        {
            return umap[{start, end}];
        }
        
        for(int i=start; i<=end; i++)
        {
            vector<TreeNode*> leftSubTree = helper(start, i-1, umap);
            vector<TreeNode*> rightSubTree = helper(i+1, end, umap);
            
            for(auto left : leftSubTree)
            {
                for(auto right : rightSubTree)
                {
                    TreeNode* root = new TreeNode(i, left, right);
                    ans.push_back(root);
                }
            }
            
        }
        
        return umap[{start, end}] = ans;
        
    }
    
    
    vector<TreeNode*> generateTrees(int n) {
        
        map< pair<int, int>, vector<TreeNode*> > umap;
        
        return helper(1, n, umap);
        
    }
};