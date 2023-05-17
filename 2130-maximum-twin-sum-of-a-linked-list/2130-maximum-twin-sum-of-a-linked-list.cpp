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
    
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nextNode;
        
        while(curr)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
public:
    int pairSum(ListNode* head) 
    {
        
        ListNode* fast = head;
        ListNode* slow = fast;
        
        while(fast and fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        cout<<slow->val;
        
        ListNode *reverseHead = reverseLL(slow);
        ListNode *temp1 = head;
        ListNode* temp2 = reverseHead;
        int maxi = INT_MIN;
        
        while(temp2)
        {
            maxi = max(maxi, temp1->val + temp2->val);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        return maxi;
        
    }
};