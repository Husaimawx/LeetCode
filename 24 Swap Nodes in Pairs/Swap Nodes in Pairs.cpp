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
    ListNode* swapPairs(ListNode* head) {
        ListNode* prehead = new ListNode(0);
        prehead->next = head;
        ListNode *p1,*p2,*p3,*p4;
        p1 = prehead;
        p2 = head;
        bool changed = false;
        while(p2 != NULL && p2->next != NULL)
        {
            p3 = p2->next;
            p4 = p3->next;
            p1->next = p3;
            p3->next = p2;
            p2->next = p4;
            if(!changed)
            {
                head = p3;
                changed = true;
            }
            p1 = p2;
            p2 = p4;
        }
        return head;
    }
};