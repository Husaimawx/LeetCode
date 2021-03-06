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
    bool hasCycle(ListNode *head) {
        ListNode *p1,*p2;
        p1 = head;
        p2 = head;
        while(1)
        {
            if(p2 == NULL)
                return false;
            if(p2->next == NULL)
                return false;
            p1 = p1->next;
            p2 = p2->next->next;
            if(p1 == p2)
                return true;
        }
    }
};