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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;
        
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* p1 = head;
        int size = 0;
        while(p1 != NULL) {
            p1 = p1->next;
            size += 1;
        }
        int n = size/k;
        
        p1 = head;
        head = pre;
        ListNode* p2;
        ListNode* first;
        for(int i = 0;i<n;i++) {
            first = p1;
            p2 = p1->next;
            for(int j = 0;j<k-1;j++) {
                ListNode* p3 = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = p3;
            }
            pre->next = p1;
            p1 = p2;
            pre = first;
        }
        pre->next = p1;
        return head->next;
    }
};