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
        ListNode* res = NULL, *last = NULL;
        ListNode* newNode = NULL;
        
        while(1)
        {
            if(p == NULL)
                return res;
            if(p->next != NULL && p->val == p->next->val)
            {
                int temp = p->val;
                while(p->val == temp)
                {
                    p = p->next;
                    if(p == NULL)
                        return res;
                }
            }
            else
            {
                if(res == NULL)
                {
                    res = new ListNode(p->val);
                    last = res;
                }
                else
                {
                    newNode = new ListNode(p->val);
                    last->next = newNode;
                    last = newNode;
                }
                p = p->next;
            }
        }
    }
};