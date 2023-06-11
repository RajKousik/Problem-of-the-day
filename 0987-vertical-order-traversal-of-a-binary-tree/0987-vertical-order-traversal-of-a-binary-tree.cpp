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
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        // mp -> {vertical, {horizontal, values(multiset)}}
        map<int, map<int, multiset<int>>> mp;
        
        // set was used to sort the elements, in the case of same row and same column,
        // but set doesnt allow duplicate elements, so we r using multiset.
        
        // q -> {Node, {column, row}}
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        q.push({root, {0, 0}});
        
        while(!q.empty())
        {
            
            auto it = q.front();
            q.pop();
            
            auto node = it.first;
            int column = it.second.first;
            int row = it.second.second;
            
            mp[column][row].insert(node->val);
            
            if(node->left)
            {
                q.push({node->left, {column-1, row+1}});
            }
            
            if(node->right)
            {
                q.push({node->right, {column+1, row+1}});
            }
            
        }
        
        
        vector<vector<int>> ans;
        
        for(auto vertical : mp)
        {
            vector<int> tempStorage;
            
            for(auto horizontal : vertical.second)
            {
                for(auto element : horizontal.second)
                {
                    tempStorage.push_back(element);
                }
            }
            
            ans.push_back(tempStorage);
        }
        
        return ans;
    }
};