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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* lsr = new ListNode(-1);
        ListNode* grtr = new ListNode(-1);
        ListNode* lhead = lsr;
        ListNode* ghead = grtr;
        
        while(head)
        {
            
            if(head->val < x)
            {
                lsr->next = head;
                lsr = lsr->next;
                head = head->next;
                lsr->next = NULL;
            }
            else
            {
                grtr->next = head;
                grtr = grtr->next;
                head = head->next;
                grtr->next = NULL;
            }
            lsr->next = ghead->next;
        }
        return lhead->next;
    }
};