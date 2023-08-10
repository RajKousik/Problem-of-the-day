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
    ListNode* findMid(ListNode* head) {
        ListNode* fast = head->next, *slow = head;
        while(fast and fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        if(!head1) return head2;
        if(!head2) return head1;
        ListNode* res = new ListNode(-1);
        ListNode* ptr = res;
        while(head1 and head2) {
            if(head1->val <= head2->val) {
                ptr->next = head1;
                head1 = head1->next;
            }
            else {
                ptr->next = head2;
                head2 = head2->next;
            }
            ptr = ptr->next;
        }
        if(head1) {
            ptr->next = head1;
        }
        if(head2) {
            ptr->next = head2;
        }
        return res->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
};