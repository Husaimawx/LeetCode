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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
        {
            return l2;
        }
        if(l2 == NULL)
        {
            return l1;
        }
        ListNode* ans = NULL;
        ListNode* anshead;
        ListNode* p = l1;
        ListNode* q = l2;
        while(p != NULL && q != NULL)
        {
            if(p->val < q->val)
            {
                if(ans == NULL)
                {
                    ans = new ListNode(p->val);
                    anshead = ans;
                }
                else
                {
                    ans->next = new ListNode(p->val);
                    ans = ans->next;
                }
                p = p->next;
            }
            else
            {
                if(ans == NULL)
                {
                    ans = new ListNode(q->val);
                    anshead = ans;
                }
                else
                {
                    ans->next = new ListNode(q->val);
                    ans = ans->next;
                }
                q = q->next;
            }
        }
        
        if(p == NULL)
        {
            while(q != NULL)
            {
                ans->next = new ListNode(q->val);
                ans = ans->next;
                q = q->next;
            }
        }
        else
        {
            while(p != NULL)
            {
                ans->next = new ListNode(p->val);
                ans = ans->next;
                p = p->next;
            }            
        }
        return anshead;
    }
};