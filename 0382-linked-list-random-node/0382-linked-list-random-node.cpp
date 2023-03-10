/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* ourHead;
    Solution(ListNode* head) {
        ourHead = head;
    }
    
    int getRandom() 
    {
        ListNode* curr = ourHead;
        
        int value = 0;
        int totalProb = 1;
        while(curr != NULL)
        {
            if(rand() % totalProb == 0)
            {
                value = curr->val;
            }
            totalProb++;
            curr = curr->next;
        }
        return value;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */