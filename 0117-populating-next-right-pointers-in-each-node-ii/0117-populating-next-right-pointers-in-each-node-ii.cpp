/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(!root) return NULL;
        
        queue<Node*> queue;
        queue.push(root);
        
        while(!queue.empty())
        {
            int size = queue.size();
            
            while(size)
            {
                auto node = queue.front();
                queue.pop();
                
                if(size == 1)
                {
                    node->next = NULL;
                }
                else
                {
                    node->next = queue.front();
                }
                
                if(node->left) queue.push(node->left);
                if(node->right) queue.push(node->right);
                size--;
            }
        }
        
        return root;
    }
};