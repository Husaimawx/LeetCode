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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* pre = NULL;
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(p2)
        {
            p2 = p2->next;
            p1->next = pre;
            pre = p1;
            p1 = p2;
        }
        
        return pre;
    }
};