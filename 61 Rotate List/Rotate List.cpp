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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        
        int i = 1;
        ListNode* p = head;
        while(p->next!=NULL)
        {
            p = p->next;
            i++;
        }
        
        k = (i-k)%i;
        if(k == 0)
            return head;
        if(k < 0)
            k+=i;
        ListNode* q = head;
        for(int j = 0;j<k-1;j++)
        {
            q = q->next;
        }
        p->next = head;
        p = q->next;
        q->next = NULL;
        return p;
    }
};