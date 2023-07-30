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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* leftPtr = dummy;
        dummy->next = head;
        ListNode* rightPtr = head;
        
        
        while(rightPtr)
        {
            
            if(rightPtr->next and rightPtr->val == rightPtr->next->val)
            {
                while(rightPtr->next and rightPtr->val == rightPtr->next->val)
                {
                    rightPtr = rightPtr->next;
                }
                leftPtr->next = rightPtr->next;
            }
            else
            {
                leftPtr = leftPtr->next; 
            }
            
            
            rightPtr = rightPtr->next;
        }
        return dummy->next;
    }
};