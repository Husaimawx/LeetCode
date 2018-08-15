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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return head;
        ListNode* odd = head, *even = head->next;
        ListNode* temp1 = odd, *temp2 = even;
        while(temp1->next != NULL && temp2->next != NULL)
        {
            temp1->next = temp2->next;
            temp2->next = temp2->next->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp1->next = even;
        return odd;
    }
};