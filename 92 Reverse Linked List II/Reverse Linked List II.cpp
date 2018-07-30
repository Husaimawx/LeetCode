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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n)
            return head;
        ListNode *p1 = new ListNode(0);
        p1->next = head;
        ListNode *p2,*p3;
        for(int i = 1;i<m;i++)
        {
            p1 = p1->next;
        }
        
        p2 = p1->next;
        p3 = p2->next;
        for(int i = m;i<n;i++)
        {
            p1->next->next = p3->next;
            p3->next = p2;
            p2 = p3;
            p3 = p1->next->next;
        }
        
        p1->next = p2;
        
        if(m == 1)
            return p1->next;
        else
            return head;
    }
};