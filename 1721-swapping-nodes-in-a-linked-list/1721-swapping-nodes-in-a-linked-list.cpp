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
    ListNode* swapNodes(ListNode* head, int k) {
        
        int temp = k-1;
        
        ListNode* ptr1 = head;
        while(temp--)
        {
            ptr1 = ptr1->next;
        }
        ListNode* tempPtr = ptr1;
        ListNode* ptr2 = head;
        
        while(ptr1->next)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        // int tempVal = ptr1->val;
        // ptr1->val = ptr2->val;
        // ptr2->val = tempVal;
        swap(tempPtr->val, ptr2->val);
        return head;
        
    }
};