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
    ListNode* mergeTwoSortedLists(ListNode* head1, ListNode* head2)
    {
        
        if(!head1)
        {
            return head2;
        }
        
        if(!head2)
        {
            return head1;
        }
        
        ListNode* res = new ListNode(-1);
        ListNode* temp = res;
        
        while(head1 and head2)
        {
            if(head1->val < head2->val)
            {
                temp->next = head1;
                head1 = head1->next;
            }
            else
            {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }
        
        if(head1)
        {
            temp->next = head1;
        }
        if(head2)
        {
            temp->next = head2;
        }
        
        return res->next;
        
        
    }
    ListNode* mergeKLists(vector<ListNode*>& arr) 
    {
        if(arr.size() == 0)
        {
            return NULL;
        }
        int last = arr.size()-1;
        
        while(last != 0)
        {
            
            int i = 0;
            int j =last;
            
            while(i < j)
            {
                arr[i] = mergeTwoSortedLists(arr[i], arr[j]);
                i++;
                j--;
                
                last--;
            }
            
        }
        
        return arr[0];
    }
};