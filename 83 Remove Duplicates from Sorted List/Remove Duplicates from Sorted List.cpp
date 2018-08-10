/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        while(p != NULL)
        {        
            ListNode* q = p->next;
            while(q!=NULL && q->val == p->val)
                q = q->next;
            p->next = q;
            p = q;
        }
        return head;
    }
};