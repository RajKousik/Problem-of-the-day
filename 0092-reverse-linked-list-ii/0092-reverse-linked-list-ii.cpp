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
private:
    
    ListNode* reverse(ListNode* head, int left, int right)
    {

        ListNode* curr = head;
        ListNode* currCopy = curr;
        ListNode* prev = NULL;
        ListNode* nextNode;
        
        int times = right - left + 1;
        while(times--)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        currCopy->next = nextNode;
        return prev;
    }
    
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0), *temp = dummy;
        dummy->next = head;
        
        for (int i = 0; i < left - 1; i++){
            temp = temp->next;
        }
        
        
        
        temp->next = reverse(temp->next, left, right);
        
        
        return dummy->next;
        
    }
};