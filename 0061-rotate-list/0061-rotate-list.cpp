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
    ListNode* rotateRight(ListNode* head, int k) {
        	if(!head or !head->next or !k)
            {
                return head;
            }
            ListNode* ptr = head;
            int len = 1;

            while(ptr->next)
            {
                ptr = ptr->next;
                len++;
            }

            ptr->next = head;

            k = k % len;
            k = len - k;

            ptr = head;
            while(k-1 > 0)
            {
                ptr = ptr->next;
                k--;
            }

            head = ptr->next;
            ptr->next = NULL;
            return head;
    }
};