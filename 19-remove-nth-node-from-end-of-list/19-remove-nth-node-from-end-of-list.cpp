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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        
        ListNode* rightPtr = head;
        ListNode* ptr = head;
        
        while(n > 0)
        {
            rightPtr = rightPtr->next;
            n--;
        }
        
        if(!rightPtr)
        {
            return head->next;
        }
        
        while(rightPtr->next != NULL)
        {
            rightPtr = rightPtr->next;
            ptr = ptr->next;
        }
        
        ListNode* toBeDelete = ptr->next;
        ptr->next = ptr->next->next;
        
        delete(toBeDelete);
        
        return head;
        
    }
};