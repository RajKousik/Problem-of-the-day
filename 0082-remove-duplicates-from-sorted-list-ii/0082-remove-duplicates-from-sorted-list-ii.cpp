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
        dummy->next = head;
        
        ListNode* ptr1 = dummy;
        ListNode* ptr2 = head;
        
        while(ptr2)
        {
            if(ptr2->next and ptr2->val == ptr2->next->val)
            {
                while(ptr2->next and ptr2->val == ptr2->next->val)
                {
                    ptr2 = ptr2->next;
                }
                
                ptr1->next = ptr2->next;
                
            }
            else
            {
                ptr1 = ptr1->next;
            }
            ptr2 = ptr2->next;
        }
        
        
        return dummy->next;
    }
};