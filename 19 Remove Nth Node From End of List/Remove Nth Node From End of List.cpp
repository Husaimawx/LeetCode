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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n == 0)
            return head;
        if(head == NULL)
            return head;
        ListNode* q = head;
        for(int i = 0; i<n;i++)
        {
            if(q != NULL)
                q = q->next;
            else
                return head;
        }
        
        if(q == NULL)
            return head->next;
        
        ListNode* p = head;
        while(q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
        return head;
    }
};