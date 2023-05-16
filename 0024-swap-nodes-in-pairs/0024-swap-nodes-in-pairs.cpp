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
//     ListNode* swapPairs(ListNode* head) {
        
//         if(head == NULL or head->next == NULL)
//         {
//             return head;
//         }
        
//         ListNode* temp = head->next;
        
//         head->next = swapPairs(temp->next);
        
//         temp->next = head;
        
//         return temp;
        
//     }
    
     ListNode* swapPairs(ListNode* head) 
     {
         if(!head or !head->next) return head;
         
         ListNode* dummyNode = new ListNode(-1);
         ListNode* curr = head;
         
         ListNode* prev = dummyNode;
         
         while(curr and curr->next)
         {
             prev->next = curr->next;
             curr->next = prev->next->next;
             prev->next->next = curr;
             
             prev = curr;
             curr = curr->next;
             
         }
         
         return dummyNode->next;
     }
};